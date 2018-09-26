#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H

#include <cmath>

namespace {
    constexpr long PROXIMITY = 0;
}

struct Position {
    double x;
    double y;
    Position() : Position(0, 0){}
    Position(double x, double y) : x{x}, y{y}{}
};

struct Velocity {
    double horizontal;
    double vertical;
    Velocity() : Velocity(0, 0){}
    Velocity(double horizontal, double vertical) : horizontal{horizontal}, vertical{vertical}{}
};

class AnimatedObject {
protected:
    Position position;
    Velocity velocity;
    double radius;
public:
    explicit AnimatedObject() : AnimatedObject(Position(0, 0), Velocity(0, 0), 0){}
    explicit AnimatedObject(Position position) : AnimatedObject(position, Velocity(0, 0), 0){}
    explicit AnimatedObject(Position position, Velocity velocity) : AnimatedObject(position, velocity, 0){}
    explicit AnimatedObject(Position position, Velocity velocity, double radius) :
        position{position},
        velocity{velocity},
        radius{radius}{}

    virtual ~AnimatedObject() = default;
    virtual void update() = 0;
    virtual bool isCollidedWith(AnimatedObject&) const;
};

#endif // ANIMATEDOBJECT_H
