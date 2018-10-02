#ifndef CANVAS_H
#define CANVAS_H

#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QWidget>

#include <memory>

#include "game.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
    QSize getSize() const { return this->size; }
    ~Canvas() override;

protected:
    bool eventFilter(QObject *, QEvent *) override;
    void paintEvent(QPaintEvent *) override;

signals:

public slots:

private:
    Game   game;
    QTimer timer;
    QSize  size;
};

#endif // CANVAS_H
