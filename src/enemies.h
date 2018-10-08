#ifndef ENEMIES_H
#define ENEMIES_H

#include <QRandomGenerator>

#include <memory>

#include "animatedobject.h"
#include "drawable.h"
#include "imagebuffer.h"
#include "player.h"


using std::shared_ptr;

namespace{
    auto seek = [](Player & player){

    };
}

enum EnemyType {
    LEUCOCYTE, SEEKER
};

class Enemy : public AnimatedObject, public Drawable
{
    shared_ptr<QPixmap> image;
    const int areaWidth;
    const int areaHeight;
    void (*abillity)(Player &);

public:
    Enemy(shared_ptr<QPixmap> image, Position position, Velocity velocity, const int areaWidth, const int areaHeight, void (*abillity)(Player &) = nullptr) :
        AnimatedObject(position, velocity, image->width() / 2),
        image{image},
        areaWidth{areaWidth},
        areaHeight{areaHeight},
        abillity(abillity){}
    void draw(QPainter &) const override;
    void update() override;
    void triggerAbillity(Player &);
};

class Seeker : public Enemy
{
public:
    Seeker(shared_ptr<QPixmap> image, Position position, Velocity velocity, const int areaWidth, const int areaHeight) :
        Enemy(image, position, velocity, areaWidth, areaHeight) {}
    void update() override;
};

Enemy enemyFactory(EnemyType, const int, const int);
#endif // ENEMIES_H
