#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent){
    this->background.load(":/images/arteria_background.png", "PNG");
    qWarning() << this->background.width() << "x" << this->background.height();
    this->width = this->background.width();
    this->height = this->background.height();
    this->size.setHeight(this->height);
    this->size.setWidth(this->width);
    this->setFixedSize(this->size);
}

void Canvas::paintEvent(QPaintEvent *event){
    static long timesPainted{0};
    QPainter painter{this};
    painter.drawPixmap(0, 0, this->background);
    qWarning() << "Canvas painted" << ++timesPainted << "times";
}
