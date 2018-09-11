#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QMainWindow>
#include <QVBoxLayout>

#include <thread>
#include <chrono>

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

void runningUpdater(Canvas * target);

#endif // MAINWINDOW_H
