#ifndef CANVAS_H
#define CANVAS_H

#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QWidget>

#include <vector>

#include "imagebuffer.h"
#include "ambient.h"

using std::vector;

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    int getHeight() const { return this->height; }
    int getWidth() const { return this->width; }
    QSize getSize() const { return this->size; }

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

public slots:

private:
    vector<shared_ptr<Drawable>> objects;
    QSize            size;
    int              width;
    int              height;
};

#endif // CANVAS_H
