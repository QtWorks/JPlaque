#include "ambient.h"

void Background::update(){
    this->position.x += this->velocity.horizontal;
    if (this->position.x < 0 - this->bufferWidth){
        this->position.x = 0;
    }
}

void Background::draw(QPainter & painter) const{
    painter.drawPixmap(static_cast<int>(this->position.x), static_cast<int>(this->position.y), *this->image);
    painter.drawPixmap(static_cast<int>(this->position.x) + this->bufferWidth, static_cast<int>(this->position.y), *this->image);
}
