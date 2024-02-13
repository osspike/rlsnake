#pragma once

#include "Common.hpp"

class Level
{
friend class TextureManager;

private:
    static Texture2D sTextureWall;
    static Texture2D sTextureGround;

    walls_t mWalls;

public:
    Level();

    bool loadFromFile(const char *filePath);
    const walls_t &walls() const { return mWalls; }
    void draw() const;
};
