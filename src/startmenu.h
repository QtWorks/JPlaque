#ifndef STARTMENU_H
#define STARTMENU_H

#include <QGroupBox>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include <QDebug>

class StartMenu : public QGroupBox
{
    Q_OBJECT
public:
    explicit StartMenu(QWidget *parent = nullptr);
    ~StartMenu() override;

signals:
    void startGameClicked();

private slots:
    void startGame();

private:
    void build();
    void connectSignals();
    void disconnectSignals();

    QVBoxLayout * layout;
    QLabel      * title;
    QPushButton * btnStart;
    QPushButton * btnHighscore;
    QPushButton * btnQuit;
};

#endif // STARTMENU_H
