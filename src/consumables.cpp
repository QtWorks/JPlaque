#include "consumables.h"

void ScoreObject::draw(QPainter & painter) const {
    painter.drawPixmap(static_cast<int>(this->position.x), static_cast<int>(this->position.y), *this->image);
}

void ScoreObject::update(){
    this->position.x += this->velocity.horizontal;
    this->position.y += this->velocity.vertical;
}

bool ScoreObject::isOutOfArea() const {
    return this->position.x + this->image->width() < 0;
}
