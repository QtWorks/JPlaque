#ifndef CONSUMABLES_H
#define CONSUMABLES_H

#include <QPainter>
#include <QPixmap>

#include <memory>

#include "animatedobject.h"
#include "drawable.h"

using std::shared_ptr;

class ScoreObject : public AnimatedObject, public Drawable
{
    shared_ptr<QPixmap> image;
    int                 score;
public:
    ScoreObject(shared_ptr<QPixmap>image, int score, int startX, int startY) : AnimatedObject(startX, startY), score{score}, image{image}{}
    void draw(QPainter&) const override;
};

#endif // CONSUMABLES_H
