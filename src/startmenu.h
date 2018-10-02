#ifndef STARTMENU_H
#define STARTMENU_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class StartMenu : public QWidget
{
    Q_OBJECT
public:
    explicit StartMenu(QWidget *parent = nullptr);
    ~StartMenu() override;

private slots:
    void startGame();

private:
    void build();
    void connectSignals();
    void disconnectSignals();

    QPushButton * btnStart;
    QPushButton * btnQuit;
};

#endif // STARTMENU_H
