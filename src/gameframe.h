#ifndef GAMEFRAME_H
#define GAMEFRAME_H

#include <QComboBox>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QCoreApplication>
#include <QDebug>

#include "canvas.h"

class GameFrame : public QWidget
{
    Q_OBJECT
public:
    explicit GameFrame(QWidget *parent = nullptr);
    ~GameFrame();

private:
    void buildContentHolder();

    QComboBox *contentHolder;
    Canvas    *canvas;
};

#endif // GAMEFRAME_H
