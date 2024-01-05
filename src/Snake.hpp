#pragma once
#include "main.hpp"

class Apple;

class Snake
{
private:
    struct point *body{};
    struct point direction;
    uint16_t length;

public:
    Snake(struct point head, struct point direction);
    ~Snake();
    void grow(struct point p);
    void draw();
    void setDirection(struct point p);
    void update();
    void changeDirection(struct point p);
    struct point getHead();
    struct point getTail();
    bool hasToEatApple(Apple *apple);
    bool isSelfCollided();
    void eat(Apple *apple);
    void respawn();
};