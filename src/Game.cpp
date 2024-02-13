#include "Game.hpp"

Game::Game()
{
    reset();
}

void Game::reset()
{
    mState = {};
    mLevel.loadFromFile("./assets/maze.lev");
    mSnake.reset();
    mApple.reposition(mLevel.walls());
}

void Game::handleInput(int key)
{
    mSnake.handleInput(key);
}

bool Game::update()
{
    mSnake.update();
    if (mSnake.isSelfCollided()) {
        return false;
    }
    if (mLevel.walls()[mSnake.head().x][mSnake.head().y]) {
        return false;
    }
    if (mSnake.hasToEatApple(mApple)) {
        mSnake.eat(mApple);
        mApple.reposition(mLevel.walls());
        mState.applesEaten++;
        mState.score += mState.difficultyLevel;
        if (mState.applesEaten % 10 == 0) {
            if (mState.difficultyLevel < 15) {
                mState.difficultyLevel++;
            }
        }
    }
    return true;
}

void Game::render() const
{
    BeginDrawing();
    ClearBackground(BLACK);

    mLevel.draw();
    mApple.draw();
    mSnake.draw();

    DrawText(TextFormat("Score: %08i", mState.score), 10, screenHeight-18, 14, WHITE);
    EndDrawing();
}

double Game::tickDuration() const
{
    return 0.25 / mState.difficultyLevel;
}
