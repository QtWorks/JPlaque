#include "canvas.h"

Canvas::Canvas(QWidget *parent) :
    QWidget(parent)
{
    this->size.setHeight(this->game.getMaxHeight());
    this->size.setWidth(this->game.getMaxWidth());
    this->setFixedSize(this->size);

    connect(&this->game, SIGNAL(updated()), this, SLOT(update()));

    this->game.start();
}

void Canvas::paintEvent(QPaintEvent *event){
    static long timesPainted{0};
    QPainter painter{this};
    game.drawContent(painter);
    qWarning() << "Canvas painted" << ++timesPainted << "times";
}
