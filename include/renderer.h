#ifndef RENDERER_H
#define RENDERER_H

#include "raylib.h"
#include <stdbool.h>

// Window & Resolution Dimensions
#define WINDOW_WIDTH  1000
#define WINDOW_HEIGHT 700

// Board & Grid Dimensions
#define TILE_SIZE     25
#define GRID_COLS     32   // 32 * 25 = 800px width
#define GRID_ROWS     20   // 20 * 25 = 500px height

#define BOARD_WIDTH   (GRID_COLS * TILE_SIZE)  // 800px
#define BOARD_HEIGHT  (GRID_ROWS * TILE_SIZE)  // 500px

#define BOARD_X       ((WINDOW_WIDTH - BOARD_WIDTH) / 2)  // 100px
#define BOARD_Y       100                                 // 100px (leaves 90px for HUD, 100px for Footer)

#define HUD_HEIGHT    90
#define FOOTER_Y      (BOARD_Y + BOARD_HEIGHT + 10)       // 610px

// Visual Theme Color Palette (Modern Neon Arcade)
#define COLOR_BG          (Color){ 11,  14,  20, 255 }  // Dark Background (#0B0E14)
#define COLOR_BOARD_BG    (Color){ 20,  25,  35, 255 }  // Lighter Game Board Container (#141923)
#define COLOR_GRID        (Color){ 30,  41,  59, 140 }  // Translucent Subtle Grid Lines
#define COLOR_GRID_BORDER (Color){ 45,  58,  82, 255 }  // Inner Board Edge Line

// Neon Accents
#define COLOR_NEON_CYAN   (Color){   0, 229, 255, 255 }  // Primary Neon Accent (#00E5FF)
#define COLOR_NEON_GREEN  (Color){   0, 255, 136, 255 }  // Snake Accent (#00FF88)
#define COLOR_NEON_PINK   (Color){ 255,   0,  85, 255 }  // Food Accent (#FF0055)
#define COLOR_NEON_AMBER  (Color){ 255, 179,   0, 255 }  // High Score / Warning (#FFB300)

// Text Colors
#define COLOR_TEXT_WHITE  (Color){ 248, 250, 252, 255 }  // Main Header Text (#F8FAFC)
#define COLOR_TEXT_MUTED  (Color){ 148, 163, 184, 255 }  // Secondary Label Text (#94A3B8)
#define COLOR_TEXT_DARK   (Color){  15,  23,  42, 255 }  // Dark text on bright badges

// Function Declarations
void InitRenderer(void);
void CloseRenderer(void);
void RenderFrame(int score, int highScore, bool isPaused);

// Sub-rendering Functions
void DrawTopHUD(int score, int highScore);
void DrawGameBoard(void);
void DrawBottomFooter(void);

#endif // RENDERER_H
