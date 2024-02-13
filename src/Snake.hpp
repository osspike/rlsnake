#pragma once

#include <vector>

#include "Common.hpp"
#include "Apple.hpp"

class Snake
{
friend class TextureManager;

private:
    static Texture2D sTextureBody;
    static Texture2D sTextureHead;
    static Texture2D sTextureCorner;
    static Texture2D sTextureTail;

public:
    enum Direction
    {
        UP, DOWN, LEFT, RIGHT
    };

private:
    std::vector<point> mBody;
    Direction mDirection;

    point directionVector() const;
    float directionAngle() const;
    
public:
    Snake();

    const Direction &direction() const { return mDirection; }
    Direction &direction() { return mDirection; }
    const point &head() const;
    const point &tail() const;

    void reset();
    void grow(const point &p);
    void handleInput(int key);
    void update();
    void draw() const;
    bool isSelfCollided() const;
    bool hasToEatApple(const Apple &apple) const;
    void eat(Apple &apple);
};
