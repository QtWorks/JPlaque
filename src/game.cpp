#include "game.h"

Game::Game() :
    gameState{State::RUNNING},
    imageBuffer{&ImageBuffer::getInstance()},
    background01{this->imageBuffer->getImage(ImageBuffer::Image::BACKGROUND_01), -0.1},
    background02{this->imageBuffer->getImage(ImageBuffer::Image::BACKGROUND_02), -0.3},
    nebular{this->imageBuffer->getImage(ImageBuffer::Image::NEBULAR), -0.2},
    maxWidth{background01.getWidth()},
    maxHeight{background01.getHeight()},
    difficulty{0},
    gameTick{0},
    player{this->imageBuffer->getImage(ImageBuffer::Image::PLAYER), Position(50, 100), QSize(maxWidth,maxHeight)}
{

}

void Game::drawContent(QPainter & painter){
    this->background01.draw(painter);
    this->player.draw(painter);
    {
        lock_guard<mutex> lock(this->scoreObjectsLock);
        std::for_each(this->scoreObjects.begin(), this->scoreObjects.end(),
                      [&painter](ScoreObject& element){ element.draw(painter); });
    }
    {
        lock_guard<mutex> lock(this->enemiesLock);
        std::for_each(this->enemies.begin(), this->enemies.end(),
                      [&painter](Enemy & element){ element.draw(painter); });
    }

    this->background02.draw(painter);
    this->nebular.draw(painter);    
}

void Game::start(){
    std::thread updater{&Game::run, this};
    updater.detach();
    std::thread collider{&Game::checkCollisions, this};
    collider.detach();
    std::thread eraser{&Game::clearObjects, this};
    eraser.detach();
}

void Game::stop(){
    this->gameState = State::GAMEOVER;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void Game::processKeyPress(QKeyEvent * keyPress){
    switch (keyPress->key()){
        case Qt::Key_W: this->player.north = true; break;
        case Qt::Key_A: this->player.west  = true; break;
        case Qt::Key_S: this->player.south = true; break;
        case Qt::Key_D: this->player.east  = true; break;
    }
}

void Game::processKeyRelease(QKeyEvent * keyPress){
    switch (keyPress->key()){
        case Qt::Key_W: this->player.north = false; break;
        case Qt::Key_A: this->player.west  = false; break;
        case Qt::Key_S: this->player.south = false; break;
        case Qt::Key_D: this->player.east  = false; break;
    }
}

void Game::clearObjects(){
    while (State::RUNNING == this->gameState){
        std::this_thread::sleep_for(std::chrono::microseconds(GARBAGE_SLEEPTIME));
        {
            lock_guard<mutex> lock(this->scoreObjectsLock);
            for (size_t i = 0; i < this->scoreObjects.size(); i++){
                ScoreObject & current = this->scoreObjects.at(i);

                if (current.isOutOfArea()){
                    qWarning() << "Current arraysize: " << this->scoreObjects.size();
                    this->scoreObjects.erase(this->scoreObjects.begin() + i);
                    break;
                }
            }
        }
    }
}

void Game::checkCollisions(){
    static long score{0};
    while (State::RUNNING == this->gameState){
        std::this_thread::sleep_for(std::chrono::microseconds(COLLISION_SLEEPTIME));
        {
            lock_guard<mutex> lock(this->scoreObjectsLock);
            for (size_t i = 0; i < this->scoreObjects.size(); i++){
                ScoreObject & current = this->scoreObjects.at(i);

                if (current.isCollidedWith(this->player)){
                    score += current.getScore();
                    qWarning() << "Current score: " << score;
                    this->scoreObjects.erase(this->scoreObjects.begin() + i);
                    this->difficulty++;
                    break;
                }
            }
        }
        {
            lock_guard<mutex> lock(this->enemiesLock);
            for (const Enemy & enemy : this->enemies){
                if (enemy.isCollidedWith(this->player)){
                    this->gameState = State::GAMEOVER;
                }
            }
        }
    }
}

void Game::tryNewEnemy(quint64 randomNumber){
    if (this->difficulty >= this->enemies.size()){
        lock_guard<mutex> lock(this->enemiesLock);
        this->enemies.push_back(enemyFactory(EnemyType::LEUCOCYTE,this->maxWidth, this->maxHeight));
    }
}

void Game::tryNewScoreObject(quint64 randomNumber){
    if (randomNumber % CHANCE_ERYTHROCYTE == 0){
        lock_guard<mutex> lock(this->scoreObjectsLock);
        this->scoreObjects.push_back(
                ScoreObject(this->imageBuffer->getImage(ImageBuffer::ERYTHROCYTE), 1, this->maxWidth, static_cast<int>(QRandomGenerator::system()->generateDouble() * this->maxHeight))
        );
    }
}

void Game::run(){
    quint64 randomNumber{0};

    while (State::RUNNING == this->gameState){
        randomNumber = QRandomGenerator::system()->generate64();
        this->background01.update();
        this->player.update();
        this->background02.update();
        this->nebular.update();
        {
            lock_guard<mutex> lock(this->scoreObjectsLock);
            std::for_each(this->scoreObjects.begin(), this->scoreObjects.end(),
                          [](ScoreObject& element){ element.update(); });
        }
        {
            lock_guard<mutex> lock(this->enemiesLock);
            std::for_each(this->enemies.begin(), this->enemies.end(),
                          [](Enemy & element){ element.update(); });
        }
        this->tryNewScoreObject(randomNumber);
        this->tryNewEnemy(randomNumber);
        std::this_thread::sleep_for(std::chrono::microseconds(UPDATE_SLEEPTIME));
    }
}
