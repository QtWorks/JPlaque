#ifndef CANVAS_H
#define CANVAS_H

#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QWidget>

#include "game.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    QSize getSize() const { return this->size; }

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

public slots:

private:
    Game  game;
    QSize size;
};

#endif // CANVAS_H
