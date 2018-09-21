#ifndef PLAYER_H
#define PLAYER_H

#include <QDebug>
#include <QPixmap>
#include <QSize>

#include <memory>
#include "animatedobject.h"
#include "drawable.h"

using std::shared_ptr;

namespace {
    constexpr double MAX_SPEED  = 0.5;
    constexpr double SPEED_STEP = 0.001;
}

class Player : public AnimatedObject, public Drawable
{
    shared_ptr<QPixmap> image;
    QSize               movableArea;

public:
    Player(shared_ptr<QPixmap>, Position, QSize);
    void draw(QPainter&) const override;
    void update() override;

    bool north;
    bool east;
    bool south;
    bool west;
};

#endif // PLAYER_H
