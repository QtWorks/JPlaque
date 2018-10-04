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
    this->startmenu = new StartMenu{this};
    connect(startmenu, SIGNAL(startGameClicked()), this, SLOT(showGameFrame()));
    this->setCentralWidget(startmenu);
}

void MainWindow::showGameFrame(){    
    disconnect(startmenu, SIGNAL(startGameClicked()), this, SLOT(showGameFrame()));
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
