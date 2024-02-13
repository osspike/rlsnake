#include "TextureManager.hpp"

#include <raylib.h>

#include "Apple.hpp"
#include "Level.hpp"
#include "Snake.hpp"

const char *TEXTURES_FOLDER = "./assets/";
const char *TEXTURES_EXT = ".png";

Texture2D loadTexture(const char *name)
{
    char path[PATH_MAX];
    snprintf(path, sizeof(path), "%s%s%s", TEXTURES_FOLDER, name, TEXTURES_EXT);
    return LoadTexture(path);
}

void unloadTexture(Texture2D &texture)
{
    UnloadTexture(texture);
    texture = {};
}

void TextureManager::loadTextures()
{
    Apple::sTexture = loadTexture("apple");
    Snake::sTextureBody = loadTexture("snake_thin");
    Snake::sTextureHead = loadTexture("snake_head");
    Snake::sTextureCorner = loadTexture("snake_angle_thin");
    Snake::sTextureTail = loadTexture("snake_tail_thin");
    Level::sTextureWall = loadTexture("wall");
    Level::sTextureGround = loadTexture("mud");
}

void TextureManager::unloadTextures()
{
    unloadTexture(Apple::sTexture);
    unloadTexture(Snake::sTextureBody);
    unloadTexture(Snake::sTextureHead);
    unloadTexture(Snake::sTextureCorner);
    unloadTexture(Snake::sTextureTail);
    unloadTexture(Level::sTextureWall);
    unloadTexture(Level::sTextureGround);
}