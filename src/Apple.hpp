#pragma once

#include "Common.hpp"

class Apple
{
friend class TextureManager;

private:
    static Texture sTexture;

    point mPos;

public:
    Apple();

    const point &position() const { return mPos; }

    void reposition(const walls_t &walls);
    void reset();
    void draw() const;
};
