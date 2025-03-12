#include "raylib.h"

#include <iostream>

#include "panel2d.hpp"


int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "CETV");

    Panel2d panel(150, 150, 500, 500);

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        ClearBackground(RAYWHITE);

        // Draw
        BeginDrawing();
            panel.draw();

        EndDrawing();
    }

    // De-Initialization
    panel.unloadTexture();

    CloseWindow();                // Close window and OpenGL context

    return 0;
}
