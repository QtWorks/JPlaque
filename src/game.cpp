#include "game.h"

Game::Game() :
    gameState{State::RUNNING},
    imageBuffer{&ImageBuffer::getInstance()},
    background01{this->imageBuffer->getImage(ImageBuffer::Image::BACKGROUND_01)},
    background02{this->imageBuffer->getImage(ImageBuffer::Image::BACKGROUND_02)}
{
    this->maxWidth = this->background01.getWidth();
    this->maxHeight = this->background01.getHeight();
}

void Game::drawContent(QPainter & painter){
    this->background01.draw(painter);
    this->background02.draw(painter);
}

void Game::start(){
    std::thread t{&Game::run, this};
    t.detach();
}

void Game::processKey(Key key){

}

void Game::update(){
    emit this->updated();
}

void Game::run(){
    while (State::RUNNING == this->gameState){
        this->background01.update();
        this->background02.update();
        emit this->updated();
        std::this_thread::sleep_for(std::chrono::microseconds(SLEEPTIME));
    }
}
