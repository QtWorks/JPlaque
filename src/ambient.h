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
    Background(std::shared_ptr<QPixmap> image) : AnimatedObject(0,0,-0.5,0), image{image}, bufferWidth{image->width()} {}
    void update() override;
    void draw(QPainter&) const override;
    int getWidth() { return this->bufferWidth; }
    int getHeight() { return this->image->height(); }
};

#endif // AMBIENT_H
