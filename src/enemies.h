#ifndef ENEMIES_H
#define ENEMIES_H

#include "animatedobject.h"
#include "drawable.h"
#include "imagebuffer.h"
#include <memory>

using std::shared_ptr;

class Leukocythe : public AnimatedObject, public Drawable
{
    static const shared_ptr<QPixmap> image;

public:
    Leukocythe(Position position, Velocity velocity);
    void draw(QPainter &) const override;
    void update() override;
};

#endif // ENEMIES_H
