#include "player.h"

Player::Player(shared_ptr<QPixmap> image, Position startingPosition, QSize area)
    : AnimatedObject(startingPosition, Velocity(0, 0), image->width() / 2),
      image{image},
      movableArea{area},
      north{false},
      east{false},
      south{false},
      west{false}
{

}

void Player::draw(QPainter & painter) const{
    painter.drawPixmap(static_cast<int>(this->position.x), static_cast<int>(this->position.y), *this->image);
}

void Player::update(){
    if (this->position.y < 0){
        this->position.y = 0;
        this->velocity.vertical = 0;
    } else if (this->position.y + this->image->height() >= this->movableArea.height()){
        this->position.y = this->movableArea.height() - this->image->height();
        this->velocity.vertical = 0;
    }

    if (this->position.x < 0){
        this->position.x = 0;
        this->velocity.horizontal = 0;
    } else if (this->position.x + this->image->width() >= this->movableArea.width()){
        this->position.x = this->movableArea.width() - this->image->width();
        this->velocity.horizontal = 0;
    }

    if (this->north && this->velocity.vertical > -MAX_SPEED){
        this->velocity.vertical -= SPEED_STEP;
    }
    if (this->east && this->velocity.horizontal < MAX_SPEED){
        this->velocity.horizontal += SPEED_STEP;
    }
    if (this->south && this->velocity.vertical < MAX_SPEED){
        this->velocity.vertical += SPEED_STEP;
    }
    if (this->west && this->velocity.horizontal > -MAX_SPEED){
        this->velocity.horizontal -= SPEED_STEP;
    }

    this->position.x += this->velocity.horizontal;
    this->position.y += this->velocity.vertical;
}
