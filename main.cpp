#include "raylib.h"
#include "src/game.hpp"
#include "src/obstacle.hpp"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    Color grey = Color{29, 29, 27, 255};

    InitWindow(screenWidth, screenHeight, "Space Invaders.");
    SetTargetFPS(60);

    Game game;
    Obstacle obstacle = Obstacle({100, 100});

    while (!WindowShouldClose()) {

        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(grey);
        game.Draw();
        obstacle.Draw();
        EndDrawing();
    }

    CloseWindow();
}
