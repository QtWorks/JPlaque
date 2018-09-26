#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QPainter>
#include <QDebug>
#include <QKeyEvent>
#include <QRandomGenerator>

#include <algorithm>
#include <chrono>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

#include "ambient.h"
#include "consumables.h"
#include "imagebuffer.h"
#include "player.h"

using std::lock_guard;
using std::mutex;
using std::shared_ptr;
using std::unique_ptr;
using std::vector;
using std::remove_if;

namespace {
    constexpr long UPDATE_SLEEPTIME    = 10;
    constexpr long COLLISION_SLEEPTIME = 100;
    constexpr long CHANCE_ERYTHROCYTE  = 600;
    constexpr long CHANCE_LEUKOCYTE    = 600;
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
    bool isCollided();
    void checkCollisions();
    void tryNewScoreObject(quint64);    
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

    mutex               scoreObjectsLock;
    vector<ScoreObject> scoreObjects;
    // Enemies
};

#endif // GAME_H
