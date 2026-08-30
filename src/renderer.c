#include "renderer.h"
#include <stdio.h>

void InitRenderer(void) {
    // Configurable initialization if custom fonts/shaders are added later
}

void CloseRenderer(void) {
    // Cleanup resources if allocated
}

void DrawTopHUD(int score, int highScore) {
    // Top HUD background area
    DrawRectangle(0, 0, WINDOW_WIDTH, HUD_HEIGHT, (Color){ 15, 20, 30, 255 });
    
    // Top separator line with neon cyan glow
    DrawRectangle(0, HUD_HEIGHT - 3, WINDOW_WIDTH, 3, COLOR_NEON_CYAN);
    DrawRectangle(0, HUD_HEIGHT - 1, WINDOW_WIDTH, 1, COLOR_TEXT_WHITE);

    // 1. GAME TITLE / BRANDING (Left aligned)
    int titleX = 50;
    int titleY = 25;
    
    // Logo Badge Box
    DrawRectangleRounded((Rectangle){ titleX, titleY - 5, 140, 42 }, 0.3f, 6, COLOR_BOARD_BG);
    DrawRectangleRoundedLines((Rectangle){ titleX, titleY - 5, 140, 42 }, 0.3f, 6, 2, COLOR_NEON_GREEN);
    DrawText("NEON", titleX + 12, titleY + 4, 16, COLOR_NEON_GREEN);
    DrawText("SNAKE", titleX + 60, titleY + 2, 22, COLOR_TEXT_WHITE);

    // Subtitle / Version tag
    DrawText("ARCADE EDITION v1.0", titleX + 2, titleY + 42, 10, COLOR_TEXT_MUTED);

    // 2. CURRENT SCORE (Center-right aligned)
    int scoreCardX = 550;
    int scoreCardY = 18;
    int cardWidth = 170;
    int cardHeight = 54;

    // Score Container Card
    DrawRectangleRounded((Rectangle){ scoreCardX, scoreCardY, cardWidth, cardHeight }, 0.25f, 6, COLOR_BOARD_BG);
    DrawRectangleRoundedLines((Rectangle){ scoreCardX, scoreCardY, cardWidth, cardHeight }, 0.25f, 6, 1, COLOR_NEON_CYAN);
    
    // Score Labels
    DrawText("CURRENT SCORE", scoreCardX + 15, scoreCardY + 8, 10, COLOR_TEXT_MUTED);
    char scoreStr[16];
    snprintf(scoreStr, sizeof(scoreStr), "%05d", score);
    DrawText(scoreStr, scoreCardX + 15, scoreCardY + 22, 24, COLOR_NEON_CYAN);

    // 3. HIGH SCORE (Far-right aligned)
    int highScoreX = 750;
    int highScoreY = 18;

    // High Score Container Card
    DrawRectangleRounded((Rectangle){ highScoreX, highScoreY, cardWidth, cardHeight }, 0.25f, 6, COLOR_BOARD_BG);
    DrawRectangleRoundedLines((Rectangle){ highScoreX, highScoreY, cardWidth, cardHeight }, 0.25f, 6, 1, COLOR_NEON_AMBER);
    
    // High Score Labels
    DrawText("HIGH SCORE", highScoreX + 15, highScoreY + 8, 10, COLOR_TEXT_MUTED);
    char highScoreStr[16];
    snprintf(highScoreStr, sizeof(highScoreStr), "%05d", highScore);
    DrawText(highScoreStr, highScoreX + 15, highScoreY + 22, 24, COLOR_NEON_AMBER);

    // Trophy icon text indicator
    DrawText("TOP", highScoreX + cardWidth - 35, highScoreY + 20, 14, COLOR_NEON_AMBER);
}

void DrawGameBoard(void) {
    // 1. Outer Glow Border Effect
    DrawRectangleLinesEx((Rectangle){ BOARD_X - 6, BOARD_Y - 6, BOARD_WIDTH + 12, BOARD_HEIGHT + 12 }, 1, (Color){ 0, 229, 255, 40 });
    DrawRectangleLinesEx((Rectangle){ BOARD_X - 4, BOARD_Y - 4, BOARD_WIDTH + 8, BOARD_HEIGHT + 8 }, 1, (Color){ 0, 229, 255, 80 });
    DrawRectangleLinesEx((Rectangle){ BOARD_X - 2, BOARD_Y - 2, BOARD_WIDTH + 4, BOARD_HEIGHT + 4 }, 2, COLOR_NEON_CYAN);

    // 2. Board Main Background Container
    DrawRectangle(BOARD_X, BOARD_Y, BOARD_WIDTH, BOARD_HEIGHT, COLOR_BOARD_BG);

    // 3. Grid Lines (32 cols x 20 rows)
    // Vertical Grid Lines
    for (int col = 0; col <= GRID_COLS; col++) {
        int x = BOARD_X + (col * TILE_SIZE);
        DrawLine(x, BOARD_Y, x, BOARD_Y + BOARD_HEIGHT, COLOR_GRID);
    }
    // Horizontal Grid Lines
    for (int row = 0; row <= GRID_ROWS; row++) {
        int y = BOARD_Y + (row * TILE_SIZE);
        DrawLine(BOARD_X, y, BOARD_X + BOARD_WIDTH, y, COLOR_GRID);
    }

    // 4. Subtle Inner Grid Border
    DrawRectangleLinesEx((Rectangle){ BOARD_X, BOARD_Y, BOARD_WIDTH, BOARD_HEIGHT }, 1, COLOR_GRID_BORDER);

    // 5. Stylized Corner Accents for Arcade Look
    int accentLen = 15;
    // Top-Left Corner
    DrawLineEx((Vector2){ BOARD_X, BOARD_Y }, (Vector2){ BOARD_X + accentLen, BOARD_Y }, 3.0f, COLOR_NEON_CYAN);
    DrawLineEx((Vector2){ BOARD_X, BOARD_Y }, (Vector2){ BOARD_X, BOARD_Y + accentLen }, 3.0f, COLOR_NEON_CYAN);
    // Top-Right Corner
    DrawLineEx((Vector2){ BOARD_X + BOARD_WIDTH, BOARD_Y }, (Vector2){ BOARD_X + BOARD_WIDTH - accentLen, BOARD_Y }, 3.0f, COLOR_NEON_CYAN);
    DrawLineEx((Vector2){ BOARD_X + BOARD_WIDTH, BOARD_Y }, (Vector2){ BOARD_X + BOARD_WIDTH, BOARD_Y + accentLen }, 3.0f, COLOR_NEON_CYAN);
    // Bottom-Left Corner
    DrawLineEx((Vector2){ BOARD_X, BOARD_Y + BOARD_HEIGHT }, (Vector2){ BOARD_X + accentLen, BOARD_Y + BOARD_HEIGHT }, 3.0f, COLOR_NEON_CYAN);
    DrawLineEx((Vector2){ BOARD_X, BOARD_Y + BOARD_HEIGHT }, (Vector2){ BOARD_X, BOARD_Y + BOARD_HEIGHT - accentLen }, 3.0f, COLOR_NEON_CYAN);
    // Bottom-Right Corner
    DrawLineEx((Vector2){ BOARD_X + BOARD_WIDTH, BOARD_Y + BOARD_HEIGHT }, (Vector2){ BOARD_X + BOARD_WIDTH - accentLen, BOARD_Y + BOARD_HEIGHT }, 3.0f, COLOR_NEON_CYAN);
    DrawLineEx((Vector2){ BOARD_X + BOARD_WIDTH, BOARD_Y + BOARD_HEIGHT }, (Vector2){ BOARD_X + BOARD_WIDTH, BOARD_Y + BOARD_HEIGHT - accentLen }, 3.0f, COLOR_NEON_CYAN);
}

void DrawBottomFooter(void) {
    int footerY = FOOTER_Y;
    
    // Top separator glow line for footer
    DrawLine(BOARD_X, footerY - 5, BOARD_X + BOARD_WIDTH, footerY - 5, COLOR_GRID_BORDER);

    // Footer Container
    int keyY = footerY + 12;

    // Helper macro / logic for key badge rendering
    // Badge 1: WASD / ARROWS
    int b1X = BOARD_X + 20;
    DrawRectangleRounded((Rectangle){ b1X, keyY, 185, 32 }, 0.3f, 4, COLOR_BOARD_BG);
    DrawRectangleRoundedLines((Rectangle){ b1X, keyY, 185, 32 }, 0.3f, 4, 1, COLOR_NEON_CYAN);
    DrawText("WASD / ARROWS", b1X + 12, keyY + 9, 11, COLOR_NEON_CYAN);
    DrawText("MOVE", b1X + 135, keyY + 9, 11, COLOR_TEXT_WHITE);

    // Badge 2: SPACE: PAUSE
    int b2X = BOARD_X + 225;
    DrawRectangleRounded((Rectangle){ b2X, keyY, 145, 32 }, 0.3f, 4, COLOR_BOARD_BG);
    DrawRectangleRoundedLines((Rectangle){ b2X, keyY, 145, 32 }, 0.3f, 4, 1, COLOR_NEON_GREEN);
    DrawText("SPACE", b2X + 12, keyY + 9, 11, COLOR_NEON_GREEN);
    DrawText("PAUSE", b2X + 85, keyY + 9, 11, COLOR_TEXT_WHITE);

    // Badge 3: R: RESTART
    int b3X = BOARD_X + 390;
    DrawRectangleRounded((Rectangle){ b3X, keyY, 130, 32 }, 0.3f, 4, COLOR_BOARD_BG);
    DrawRectangleRoundedLines((Rectangle){ b3X, keyY, 130, 32 }, 0.3f, 4, 1, COLOR_NEON_AMBER);
    DrawText("R KEY", b3X + 12, keyY + 9, 11, COLOR_NEON_AMBER);
    DrawText("RESET", b3X + 75, keyY + 9, 11, COLOR_TEXT_WHITE);

    // Right-aligned status indicator
    int statusX = BOARD_X + BOARD_WIDTH - 200;
    DrawRectangleRounded((Rectangle){ statusX, keyY, 180, 32 }, 0.3f, 4, (Color){ 16, 24, 38, 255 });
    DrawRectangleRoundedLines((Rectangle){ statusX, keyY, 180, 32 }, 0.3f, 4, 1, COLOR_GRID_BORDER);
    DrawText("SYSTEM:", statusX + 15, keyY + 9, 11, COLOR_TEXT_MUTED);
    DrawText("FOUNDATION READY", statusX + 72, keyY + 9, 10, COLOR_NEON_GREEN);
}

void RenderFrame(int score, int highScore, bool isPaused) {
    BeginDrawing();
    
    // Clear whole background with deep dark arcade charcoal
    ClearBackground(COLOR_BG);

    // Draw Major Layout Areas
    DrawTopHUD(score, highScore);
    DrawGameBoard();
    DrawBottomFooter();

    // If Paused, overlay visual banner on board
    if (isPaused) {
        DrawRectangle(BOARD_X, BOARD_Y, BOARD_WIDTH, BOARD_HEIGHT, (Color){ 11, 14, 20, 200 });
        
        int boxW = 320;
        int boxH = 100;
        int boxX = BOARD_X + (BOARD_WIDTH - boxW) / 2;
        int boxY = BOARD_Y + (BOARD_HEIGHT - boxH) / 2;

        DrawRectangleRounded((Rectangle){ boxX, boxY, boxW, boxH }, 0.2f, 6, COLOR_BOARD_BG);
        DrawRectangleRoundedLines((Rectangle){ boxX, boxY, boxW, boxH }, 0.2f, 6, 2, COLOR_NEON_AMBER);

        DrawText("GAME PAUSED", boxX + (boxW - MeasureText("GAME PAUSED", 26)) / 2, boxY + 25, 26, COLOR_NEON_AMBER);
        DrawText("Press SPACE to Resume", boxX + (boxW - MeasureText("Press SPACE to Resume", 14)) / 2, boxY + 62, 14, COLOR_TEXT_MUTED);
    }

    EndDrawing();
}
