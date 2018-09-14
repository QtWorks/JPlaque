#ifndef ANIMATEDOBJECT_H
#define ANIMATEDOBJECT_H

class AnimatedObject {
protected:
    double positionX;
    double positionY;
    double speedX;
    double speedY;
public:
    explicit AnimatedObject() : AnimatedObject(0, 0, 0, 0){}
    explicit AnimatedObject(double x, double y) : AnimatedObject(x, y, 0, 0){}
    explicit AnimatedObject(double x, double y, double sx, double sy) : positionX{x}, positionY{y}, speedX{sx}, speedY{sy}{}
    virtual ~AnimatedObject() = default;
    virtual void update() = 0;
};

#endif // ANIMATEDOBJECT_H
