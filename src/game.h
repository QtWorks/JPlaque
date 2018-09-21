#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>

#include <chrono>
#include <memory>
#include <thread>
#include <vector>

#include "ambient.h"
#include "consumables.h"
#include "imagebuffer.h"
#include "player.h"

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
    void processKeyPress(QKeyEvent *);
    void processKeyRelease(QKeyEvent *);

    enum Key   {NORTH, EAST, SOUTH, WEST};
    enum State {RUNNING, GAMEOVER};

private:
    void run();

    State               gameState;
    ImageBuffer *       imageBuffer;
    Background          background01;
    Background          background02;
    Background          nebular;
    int                 maxWidth;
    int                 maxHeight;
    long                gameTick;
    Player              player;
    vector<ScoreObject> scoreObjects;
    // Enemies
};

#endif // GAME_H
