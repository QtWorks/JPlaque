#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent){
    this->buildContentHolder();
    std::thread t{runningUpdater, this->canvas};
    t.detach();
}

void MainWindow::buildContentHolder(){
    QVBoxLayout vBoxLayout{};
    this->contentHolder = new QComboBox;
    this->canvas = new Canvas;

    this->setFixedSize(this->canvas->getSize());

    vBoxLayout.addWidget(this->canvas);
    this->contentHolder->setLayout(&vBoxLayout);
    this->setCentralWidget(this->contentHolder);
}

void runningUpdater(Canvas * target){
    while (true){
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
        target->update();
    }
}
