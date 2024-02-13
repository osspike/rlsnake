#include "Common.hpp"
#include "Engine.hpp"

#define WINDOW_TITLE "My awesome snake"

int main()
{
    InitWindow(screenWidth, screenHeight, WINDOW_TITLE);
    Engine engine;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        engine.handleInput();
        engine.update();
        engine.render();
    }

    return 0;
}
