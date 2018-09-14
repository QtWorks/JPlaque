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
    Background(std::shared_ptr<QPixmap> image) : AnimatedObject(0,0,-2,0), image{image}, bufferWidth{image->width()} {}
    void update() override;
    void draw(QPainter&) const override;
};

#endif // AMBIENT_H
