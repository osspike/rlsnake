#pragma once

#include <raylib.h>

struct point
{
    int x;
    int y;
};

inline bool operator==(const point &l, const point &r) { return l.x == r.x && l.y == r.y; }

constexpr int levelWidth  = 50;
constexpr int levelHeight = 30;
constexpr int tileSize = 16;
constexpr int screenWidth = levelWidth * tileSize;
constexpr int screenHeight = levelHeight * tileSize;

typedef bool walls_t[levelWidth][levelHeight];

inline bool isOnLevel(const point &pos)
{
    return pos.x >= 0 && pos.y >= 0 && pos.x < levelWidth && pos.y < levelHeight;
}
