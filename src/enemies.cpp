#include "enemies.h"

const shared_ptr<QPixmap> Leukocythe::image = ImageBuffer::getInstance().getImage(ImageBuffer::Image::LEUKOCYTHE);

void Leukocythe::draw(QPainter & painter) const {
    painter.drawPixmap(static_cast<int>(this->position.x), static_cast<int>(this->position.y), *image);
}

void Leukocythe::update(){
    this->position.x += this->velocity.horizontal;
    this->position.y += this->velocity.vertical;
    if (0 > this->position.x + image->width()){

    }
}
