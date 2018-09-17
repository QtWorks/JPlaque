#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QMainWindow>
#include <QVBoxLayout>

#include "canvas.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private:
    void buildContentHolder();

    QComboBox *contentHolder;
    Canvas    *canvas;
};

#endif // MAINWINDOW_H
