#include "game.h"

Game::Game() :
    gameState{State::RUNNING},
    imageBuffer{&ImageBuffer::getInstance()},
    background01{this->imageBuffer->getImage(ImageBuffer::Image::BACKGROUND_01), -0.1},
    background02{this->imageBuffer->getImage(ImageBuffer::Image::BACKGROUND_02), -0.3},
    nebular{this->imageBuffer->getImage(ImageBuffer::Image::NEBULAR), -0.2},
    maxWidth{background01.getWidth()},
    maxHeight{background01.getHeight()},
    gameTick{0},
    player{this->imageBuffer->getImage(ImageBuffer::Image::PLAYER), Position(50, 100), QSize(maxWidth,maxHeight)}
{

}

void Game::drawContent(QPainter & painter){
    this->background01.draw(painter);
    this->player.draw(painter);
    this->background02.draw(painter);
    this->nebular.draw(painter);
}

void Game::start(){
    std::thread t{&Game::run, this};
    t.detach();
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

void Game::run(){
    while (State::RUNNING == this->gameState){
        this->background01.update();
        this->player.update();
        this->background02.update();
        this->nebular.update();
        std::for_each(this->scoreObjects.begin(), this->scoreObjects.end(),
                      [](ScoreObject& element){ element.update(); });
        std::this_thread::sleep_for(std::chrono::microseconds(SLEEPTIME));
    }
}