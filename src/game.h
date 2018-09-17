#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QPainter>

#include <chrono>
#include <memory>
#include <thread>
#include <vector>

#include "ambient.h"
#include "imagebuffer.h"

using std::shared_ptr;
using std::unique_ptr;
using std::vector;

namespace {
    constexpr long SLEEPTIME = 10;
}

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game();
    virtual ~Game() { this->gameState = State::GAMEOVER; }
    void drawContent(QPainter&);
    void start();
    int getMaxWidth() const { return this->maxWidth; }
    int getMaxHeight() const { return this->maxHeight; }

    enum Key   {NORTH, EAST, SOUTH, WEST};
    enum State {RUNNING, GAMEOVER};

public slots:
    void processKey(Key);

signals:
    void updated();

private:
    void update();
    void run();

    int           maxWidth;
    int           maxHeight;
    State         gameState;
    ImageBuffer * imageBuffer;
    Background    background01;
    Background    background02;
    // Player
    // Enemies
};

#endif // GAME_H
