#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

typedef struct GameState {
    int score;
    int highScore;
    bool isPaused;
    bool isGameOver;
} GameState;

void InitGame(GameState *game);
void UpdateGame(GameState *game);
void RenderGame(const GameState *game);

#endif // GAME_H
