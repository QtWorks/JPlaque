#include "gameframe.h"

GameFrame::GameFrame(QWidget *parent) : QWidget(parent)
{
    this->buildContentHolder();
    QCoreApplication::instance()->installEventFilter(this->canvas);
}

GameFrame::~GameFrame(){
    QCoreApplication::instance()->removeEventFilter(this->canvas);
    qWarning() << "GameFrame got deleted";
}

void GameFrame::buildContentHolder(){
    QVBoxLayout vBoxLayout{};
    this->contentHolder = new QComboBox;
    this->canvas = new Canvas;
    this->setFixedSize(this->canvas->getSize());

    vBoxLayout.addWidget(this->canvas);
    this->contentHolder->setLayout(&vBoxLayout);
    this->setLayout(&vBoxLayout);
    //this->setCentralWidget(this->contentHolder);
}
