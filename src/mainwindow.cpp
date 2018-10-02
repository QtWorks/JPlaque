#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent){
    //this->buildContentHolder();
    //QCoreApplication::instance()->installEventFilter(this->canvas);
    this->showStartMenu();
}

MainWindow::~MainWindow(){
   // QCoreApplication::instance()->removeEventFilter(this->canvas);
}

void MainWindow::showStartMenu(){
    this->setCentralWidget(new StartMenu{this});
}

void MainWindow::showGameFrame(){
    this->setCentralWidget(new GameFrame{this});
}

/*
void MainWindow::buildContentHolder(){
    QVBoxLayout vBoxLayout{};
    this->contentHolder = new QComboBox;
    this->canvas = new Canvas;
    this->setFixedSize(this->canvas->getSize());

    vBoxLayout.addWidget(this->canvas);
    this->contentHolder->setLayout(&vBoxLayout);
    this->setCentralWidget(this->contentHolder);
}*/
