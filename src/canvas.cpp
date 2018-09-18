#include "canvas.h"

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    timer{this}
{
    this->size.setHeight(this->game.getMaxHeight());
    this->size.setWidth(this->game.getMaxWidth());
    this->setFixedSize(this->size);

    connect(&this->timer, SIGNAL(timeout()), this, SLOT(update()));

    this->game.start();
    this->timer.setInterval(16);
    this->timer.start();
}

void Canvas::paintEvent(QPaintEvent *event){
    //static long timesPainted{0};
    QPainter painter{this};
    game.drawContent(painter);
    //qWarning() << "Canvas painted" << ++timesPainted << "times";
}

bool Canvas::eventFilter(QObject * dist, QEvent * event){
    if (event->type() == QEvent::KeyPress){
        QKeyEvent * keyPress = static_cast<QKeyEvent*>(event);
        this->game.processKeyPress(keyPress);
        return true;
    } else if (event->type() == QEvent::KeyRelease){
        QKeyEvent * keyPress = static_cast<QKeyEvent*>(event);
        this->game.processKeyRelease(keyPress);
        return true;
    }
    return false;
}
