#include "canvas.h"

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    objects()
{
    this->objects.push_back(make_shared<Background>(ImageBuffer::getInstance().getImage(ImageBuffer::BACKGROUND_01)));
    this->width  = 640;
    this->height = 400;
    this->size.setHeight(this->height);
    this->size.setWidth(this->width);
    this->setFixedSize(this->size);
}

void Canvas::paintEvent(QPaintEvent *event){
    static long timesPainted{0};
    QPainter painter{this};
    /*
    std::for_each(this->objects.begin(), this->objects.end(),
                  [&painter](auto & element){ element.draw(painter); }
                  );*/
    for (auto const & element : this->objects){
        element->draw(painter);
    }
    qWarning() << "Canvas painted" << ++timesPainted << "times";
}
