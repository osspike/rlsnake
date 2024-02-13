#include "Apple.hpp"

Texture Apple::sTexture = {};

Apple::Apple()
{
    reset();
}

void Apple::reset()
{
    mPos.x = -1;
    mPos.y = -1;
}

void Apple::reposition(const walls_t &walls)
{
    do {
        mPos.x = GetRandomValue(0, levelWidth);
        mPos.y = GetRandomValue(0, levelHeight);
    } while (walls[mPos.x][mPos.y]);
}

void Apple::draw() const
{
    if (isOnLevel(mPos)) {
        DrawTexture(sTexture, mPos.x * tileSize, mPos.y * tileSize, WHITE);
    }
}
