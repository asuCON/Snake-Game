#include "raylib.h"
#include "renderer.h"
#include "game.h"

int main(void) {
    // 1. Initialize Raylib Game Window
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Neon Arcade Snake");
    SetTargetFPS(60);

    // 2. Initialize Subsystems & Game State
    InitRenderer();
    
    GameState game;
    InitGame(&game);

    // 3. Main Game Loop
    while (!WindowShouldClose()) {
        // Frame Update
        UpdateGame(&game);

        // Frame Render
        RenderGame(&game);
    }

    // 4. Clean Shutdown
    CloseRenderer();
    CloseWindow();

    return 0;
}
