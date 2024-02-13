#pragma once

#include <stdint.h>

#include "Level.hpp"
#include "Snake.hpp"
#include "Apple.hpp"

struct GameState
{
    uint32_t score           = 0u;
    uint32_t applesEaten     = 0u;
    uint32_t difficultyLevel = 1u;
};

class Game
{
    GameState mState;
    Level mLevel;
    Snake mSnake;
    Apple mApple;

public:
    Game();
    void reset();
    void handleInput(int key);
    bool update();
    void render() const;
    double tickDuration() const;
};