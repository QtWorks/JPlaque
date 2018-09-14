#include "ambient.h"

void Background::update(){
    this->positionX += this->speedX;
    if (this->positionX < 0 - this->bufferWidth){
        this->positionX = 0;
    }
}

void Background::draw(QPainter & painter) const{
    painter.drawPixmap(static_cast<int>(this->positionX), static_cast<int>(this->positionY), *this->image);
    painter.drawPixmap(static_cast<int>(this->positionX) + this->bufferWidth, static_cast<int>(this->positionY), *this->image);
}
