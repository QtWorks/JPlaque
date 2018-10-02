#include "startmenu.h"

StartMenu::StartMenu(QWidget *parent) : QWidget(parent)
{
    this->build();
    this->connectSignals();
}

StartMenu::~StartMenu(){
    disconnect(this->btnStart, SIGNAL(clicked()), this, SLOT(startGame()));
}

void StartMenu::startGame(){
    //TODO
}

void StartMenu::build(){
    QVBoxLayout vBoxLayout{};
    this->btnStart = new QPushButton{"Start"};
    this->btnQuit  = new QPushButton{"Quit"};

    vBoxLayout.addWidget(this->btnStart);
    vBoxLayout.addWidget(this->btnQuit);
    this->setLayout(&vBoxLayout);
}

void StartMenu::connectSignals(){
    connect(this->btnStart, SIGNAL(clicked()), this, SLOT(startGame()));
}
