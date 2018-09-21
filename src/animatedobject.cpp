#include "animatedobject.h"

bool AnimatedObject::isCollidedWith(AnimatedObject & other) const {
    const double A = std::abs(this->position.x - other.position.x);
    const double B = std::abs(this->position.y - other.position.y);
    const double C = std::sqrt(A * A + B * B);

    return (0 >= C - this->radius - other.radius);
}
