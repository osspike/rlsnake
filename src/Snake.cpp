#include "Snake.hpp"

#include <stdlib.h>

Texture2D Snake::sTextureBody   = {};
Texture2D Snake::sTextureHead   = {};
Texture2D Snake::sTextureCorner = {};
Texture2D Snake::sTextureTail   = {};

void drawTile(const Texture2D &tex, const point &pos, float rot)
{
    Vector2 origin = {tex.width / 2.0f, tex.height / 2.0f};
    Rectangle src =  {0.0f, 0.0f, float(tex.width), float(tex.height)};
    Rectangle dest = {float(pos.x * tileSize) + origin.x, float(pos.y * tileSize) + origin.y, float(tex.width), float(tex.height)};
    DrawTexturePro(tex, src, dest, origin, rot, WHITE);
}

Snake::Snake()
{
    reset();
}

void Snake::reset()
{
    mDirection = RIGHT;
    mBody.clear();
    grow(point{4, 1});
    grow(point{3, 1});
    grow(point{2, 1});
}

void Snake::grow(const point &p)
{
    mBody.push_back(p);
}

void Snake::handleInput(int key)
{
    switch (key) {
    case KEY_DOWN:
        mDirection = UP;
        break;
    case KEY_UP:
        mDirection = DOWN;
        break;
    case KEY_LEFT:
        mDirection = LEFT;
        break;
    case KEY_RIGHT:
        mDirection = RIGHT;
        break;
    }
}

void Snake::draw() const
{
    enum Orient { 
        HOR = 0,
        VERT = 1
    } orient = Orient(mDirection == UP || mDirection == DOWN);

    point pos = mBody.front();

    drawTile(sTextureHead, pos, directionAngle());

    point prev = pos;
    for (size_t i = 1; i < mBody.size() - 1; i++) {
        pos = mBody[i];
        switch (orient) {
            case HOR:
                if (pos.y != prev.y) {
                    orient = VERT;
                }
                break;
            case VERT:
                if (pos.x != prev.x) {
                    orient = HOR;
                }
                break;
        }
        prev = pos;

        drawTile(sTextureBody, pos, orient == VERT ? 90.0f : 0.0f);
    }

    if (mBody.size() > 1) {
        pos = mBody.back();
        float rot = 0.0f;
        switch (orient) {
            case HOR:
                if (pos.y == prev.y) {
                    rot = pos.x > prev.x ? 0.0f : 180.0f;
                } else {
                    rot = pos.y > prev.y ? 90.0f : 270.0f;
                }
                break;
            case VERT:
                if (pos.x == prev.x) {
                    rot = pos.y > prev.y ? 90.0f : 270.0f;
                } else {
                    rot = pos.x > prev.x ? 0.0f : 180.0f;
                }
                break;
        }

        drawTile(sTextureTail, pos, rot);
    }
}

point Snake::directionVector() const
{
    switch (mDirection) {
        case UP:    return point{0, 1};
        case DOWN:  return point{0, -1};
        case LEFT:  return point{-1, 0};
        case RIGHT: return point{1, 0};
    }
}

float Snake::directionAngle() const
{
    float ang = 0.0f;
    switch (mDirection) { // 😈😈😈
        case UP:    ang += 90.0f;
        case RIGHT: ang += 90.0f;
        case DOWN:  ang += 90.0f;
        case LEFT:  ang += 0.f;
    }
    return ang;
}

void Snake::update()
{
    for (int i = mBody.size() - 1; i > 0; i--) {
        mBody[i] = mBody[i - 1];
    }

    point &head = mBody.front();
    point dir = directionVector();

    head.x += dir.x % levelWidth;
    head.y += dir.y % levelHeight;

    if (head.x < 0) head.x = levelWidth - 1;
    if (head.y < 0) head.y = levelHeight - 1;
}

bool Snake::isSelfCollided() const
{
    const point &head = mBody.front();
    for (size_t i = 1; i < mBody.size(); i++) {
        if (head == mBody[i]) {
            return true;
        }
    }
    return false;
}

bool Snake::hasToEatApple(const Apple &apple) const
{
    return mBody.front() == apple.position();
}

void Snake::eat(Apple &apple)
{
    grow(apple.position());
    apple.reset();
}

const point &Snake::head() const
{
    return mBody.front();
}

const point &Snake::tail() const
{
    return mBody.back();
}
