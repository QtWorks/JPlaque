#include "enemies.h"

//const shared_ptr<QPixmap> Leukocythe::image = ImageBuffer::getInstance().getImage(ImageBuffer::Image::LEUKOCYTHE);

void Enemy::draw(QPainter & painter) const {
    painter.drawPixmap(static_cast<int>(this->position.x), static_cast<int>(this->position.y), *image);
}

void Enemy::update(){
    this->position.x += this->velocity.horizontal;
    //this->position.y += this->velocity.vertical;
    if (0 > this->position.x + image->width()){
        this->position.x = QRandomGenerator::system()->generateDouble() * 100 + this->areaWidth;
        this->position.y = QRandomGenerator::system()->generateDouble() * this->areaHeight;
    }
}

Enemy enemyFactory(EnemyType type, const int areaWidth, const int areaHeight){
    Position start{QRandomGenerator::system()->generateDouble() * 100 + areaWidth,
                   QRandomGenerator::system()->generateDouble() * areaHeight};
    double speedX{-QRandomGenerator::system()->generateDouble() / 2 + 0.1};

    switch (type){
    default: return Enemy{ImageBuffer::getInstance().getImage(ImageBuffer::Image::LEUKOCYTHE), start, Velocity{speedX, 0}, areaWidth, areaHeight};
    }
}
