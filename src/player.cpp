#include "player.h"

Player::Player(shared_ptr<QPixmap> image, double startX, double startY, QSize area)
    : AnimatedObject(startX, startY),
      image{image},
      radius{static_cast<double>(image->width() / 2)},
      movableArea{area},
      north{false},
      east{false},
      south{false},
      west{false}
{

}

void Player::draw(QPainter & painter) const{
    painter.drawPixmap(static_cast<int>(this->positionX), static_cast<int>(this->positionY), *this->image);
}

void Player::update(){
    if (this->positionY < 0){
        this->positionY = 0;
        this->speedY = 0;
    } else if (this->positionY + this->image->height() >= this->movableArea.height()){
        this->positionY = this->movableArea.height() - this->image->height();
        this->speedY = 0;
    }

    if (this->positionX < 0){
        this->positionX = 0;
        this->speedX = 0;
    } else if (this->positionX + this->image->width() >= this->movableArea.width()){
        this->positionX = this->movableArea.width() - this->image->width();
        this->speedX = 0;
    }

    if (this->north && this->speedY > -MAX_SPEED){
        this->speedY -= SPEED_STEP;
    }
    if (this->east && this->speedX < MAX_SPEED){
        this->speedX += SPEED_STEP;
    }
    if (this->south && this->speedY < MAX_SPEED){
        this->speedY += SPEED_STEP;
    }
    if (this->west && this->speedX > -MAX_SPEED){
        this->speedX -= SPEED_STEP;
    }

    this->positionX += this->speedX;
    this->positionY += this->speedY;
}
