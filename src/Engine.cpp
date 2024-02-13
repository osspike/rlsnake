#include "Engine.hpp"

#include "TextureManager.hpp"

Engine::Engine()
{
    mMode = GAME;
    mFrameCount = 0;
    mLastTickTime = GetTime();

    TextureManager::loadTextures();
}

Engine::~Engine()
{
    TextureManager::unloadTextures();
}

void Engine::reset()
{
    mMode = GAME;
    mGame.reset();
    mFrameCount = 0;
    mLastTickTime = GetTime();
}

void Engine::update()
{
    if (GetTime() - mLastTickTime > mGame.tickDuration())
    {
        bool running = mGame.update();
        if (!running) {
            mMode = GAMEOVER;
        }
        mLastTickTime = GetTime();
    }
}

void Engine::handleInput()
{
    int lastKey = 0;
    int key = 0;
    while ((key = GetKeyPressed())) {
        lastKey = key;
    }

    if (lastKey == KEY_SPACE) {
        reset();
    } else {
        mGame.handleInput(lastKey);
    }
}

void Engine::render() const
{
    switch (mMode) {
    case GAME:
        mGame.render();
        break;
    case GAMEOVER:
        BeginDrawing();
        ClearBackground(RED);
        EndDrawing();
        break;
    case LEADERBOARD:
        break;
    case EDITOR:
        break;
    case START:
        break;
    default:
        break;
    }
}