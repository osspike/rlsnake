#pragma once

#include "Common.hpp"
#include "Game.hpp"

class Engine
{
    enum mode
    {
        GAME,
        START,
        GAMEOVER,
        EDITOR,
        LEADERBOARD
    };

private:
    mode mMode;
    Game mGame;

    uint32_t mFrameCount;
    double mLastTickTime;

    void initializeSnake();
public:
    Engine();
    ~Engine();
    void handleInput();
    void reset();
    void update();
    void render() const;
};