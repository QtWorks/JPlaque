#ifndef ENEMIES_H
#define ENEMIES_H

#include <QRandomGenerator>
#include <QDebug>

#include <cmath>
#include <memory>

#include "animatedobject.h"
#include "drawable.h"
#include "imagebuffer.h"
#include "player.h"


using std::shared_ptr;

enum EnemyType {
    LEUCOCYTE, SEEKER
};

class Enemy : public AnimatedObject, public Drawable
{
    shared_ptr<QPixmap> image;
    const int areaWidth;
    const int areaHeight;
    void (*abillity)(Enemy &, Player &);

public:
    Enemy(shared_ptr<QPixmap> image, Position position, Velocity velocity, const int areaWidth, const int areaHeight, void (*abillity)(Enemy &, Player &) = nullptr) :
        AnimatedObject(position, velocity, image->width() / 2),
        image{image},
        areaWidth{areaWidth},
        areaHeight{areaHeight},
        abillity(abillity){}
    void draw(QPainter &) const override;
    void update() override;
    void triggerAbillity(Player &);
};

/* Available abillities for different types of enemies.
 */
namespace Abillities{
constexpr double SPEED_INCREASE = 0.00005;
constexpr double MAX_SPEED      = 0.2;
void seek(Enemy &, Player &);
}

Enemy enemyFactory(EnemyType, const int, const int);

#endif // ENEMIES_H
