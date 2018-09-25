#ifndef AMBIENT_H
#define AMBIENT_H

#include <QPixmap>
#include <memory>
#include "animatedobject.h"
#include "drawable.h"

class Background final : public AnimatedObject, public Drawable
{
    std::shared_ptr<QPixmap> image;
    int bufferWidth;
public:
    Background(std::shared_ptr<QPixmap> image, double speedY) : AnimatedObject(Position(),Velocity(speedY,0)), image{image}, bufferWidth{image->width()} {}
    void draw(QPainter&) const override;
    void update() override;
    int getWidth() { return this->bufferWidth; }
    int getHeight() { return this->image->height(); }
};

#endif // AMBIENT_H
