#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QComboBox>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QKeyEvent>
#include <QCoreApplication>

//#include "canvas.h"

#include "gameframe.h"
#include "startmenu.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showStartMenu();
    void showGameFrame();

private:
    StartMenu * startmenu;
};

#endif // MAINWINDOW_H
