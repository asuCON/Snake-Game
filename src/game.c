#include "game.h"
#include "renderer.h"
#include "raylib.h"

void InitGame(GameState *game) {
    if (!game) return;
    game->score = 0;
    game->highScore = 150; // Demo initial high score
    game->isPaused = false;
    game->isGameOver = false;
}

void UpdateGame(GameState *game) {
    if (!game) return;

    // Toggle Pause on SPACE key press
    if (IsKeyPressed(KEY_SPACE)) {
        game->isPaused = !game->isPaused;
    }

    // Reset game state on R key press
    if (IsKeyPressed(KEY_R)) {
        game->score = 0;
        game->isPaused = false;
        game->isGameOver = false;
    }
}

void RenderGame(const GameState *game) {
    if (!game) return;
    RenderFrame(game->score, game->highScore, game->isPaused);
}
