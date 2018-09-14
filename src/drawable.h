#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <QPainter>

class Drawable {
public:
    explicit Drawable() = default;
    virtual ~Drawable() = default;
    virtual void draw(QPainter&) const = 0;
};

#endif // DRAWABLE_H
