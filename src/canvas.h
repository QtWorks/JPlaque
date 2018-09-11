#ifndef CANVAS_H
#define CANVAS_H

#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QWidget>

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
    QPixmap background;
    QSize   size;
    int     width;
    int     height;
};

#endif // CANVAS_H
