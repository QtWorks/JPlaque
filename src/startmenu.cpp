#include "startmenu.h"

StartMenu::StartMenu(QWidget *parent) : QGroupBox(parent)
{
    this->setMinimumSize(500,500);
    this->build();
    this->connectSignals();
}

StartMenu::~StartMenu(){
    qWarning() << "Startmenu will be deleted now";
    disconnect(this->btnStart, SIGNAL(clicked()), this, SLOT(startGame()));
}

void StartMenu::startGame(){
    emit startGameClicked();
}

void StartMenu::build(){
    this->layout       = new QVBoxLayout{this};
    this->btnStart     = new QPushButton{"Start", this};
    this->btnHighscore = new QPushButton{"Highscore", this};
    this->btnQuit      = new QPushButton{"Quit", this};

    this->layout->addWidget(this->btnStart);
    this->layout->addWidget(this->btnHighscore);
    this->layout->addWidget(this->btnQuit);

    this->setLayout(this->layout);
}

void StartMenu::connectSignals(){
    connect(this->btnStart, SIGNAL(clicked()), this, SLOT(startGame()));
}
