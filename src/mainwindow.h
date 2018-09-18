#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QCoreApplication>

#include "canvas.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void buildContentHolder();

    QComboBox *contentHolder;
    Canvas    *canvas;
};

#endif // MAINWINDOW_H
