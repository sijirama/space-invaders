#include "raylib.h"
#include "src/game.hpp"

int main() {
    const int screenWidth = 750;
    const int screenHeight = 800;

    Color grey = Color{29, 29, 27, 255};

    InitWindow(screenWidth, screenHeight, "Space Invaders.");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose()) {

        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(grey);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
