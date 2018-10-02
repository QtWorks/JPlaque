#ifndef ENEMIES_H
#define ENEMIES_H

#include <QRandomGenerator>

#include <memory>

#include "animatedobject.h"
#include "drawable.h"
#include "imagebuffer.h"


using std::shared_ptr;

enum EnemyType {
    LEUCOCYTE, SEEKER
};

class Enemy : public AnimatedObject, public Drawable
{
    shared_ptr<QPixmap> image;
    const int areaWidth;
    const int areaHeight;

public:
    Enemy(shared_ptr<QPixmap> image, Position position, Velocity velocity, const int areaWidth, const int areaHeight) :
        AnimatedObject(position, velocity, image->width() / 2),
        image{image},
        areaWidth{areaWidth},
        areaHeight{areaHeight}{}
    void draw(QPainter &) const override;
    void update() override;
    virtual void triggerAbillity(){}
};

Enemy enemyFactory(EnemyType, const int, const int);
#endif // ENEMIES_H
