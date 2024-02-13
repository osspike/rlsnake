#include "Level.hpp"

#include <stdio.h>

Texture2D Level::sTextureWall = {};
Texture2D Level::sTextureGround = {};

Level::Level()
    : mWalls{}
{}

bool Level::loadFromFile(const char *filePath)
{
    if (!FileExists(filePath)) {
        fprintf(stderr, "Level file doesn't exist: %s\n", filePath);
        return false;
    }

    const int levelSize = levelWidth * levelHeight;
    int dataSize = 0;
    unsigned char *contents = LoadFileData(filePath, &dataSize);
    if (dataSize != levelSize) {
        fprintf(stderr, 
                "Level file is too %s: %s\n", 
                dataSize > levelSize ? "big" : "small", 
                filePath);
        return false;
    }

    for(int y = 0; y < levelHeight; y++) {
        for(int x = 0; x < levelWidth; x++) {
            mWalls[x][y] = contents[x + (y * levelWidth)] == '1';
        }
    }

    UnloadFileData(contents);
    return true;
}

void Level::draw() const {
    DrawTextureRec(
        sTextureGround,
        Rectangle { 0.0f, 0.0f, screenWidth, screenHeight },
        Vector2 { 0.0f, 0.0f },
        WHITE);

    for(int y = 0; y < levelHeight; y++) {
        for(int x = 0; x < levelWidth; x++) {
            if(mWalls[x][y]){
                DrawTexture(sTextureWall, x * tileSize, y * tileSize, WHITE);
            }
        }
    }
}