CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
LDFLAGS = -Llib -lraylib -lopengl32 -lgdi32 -lwinmm -mconsole

SRC = src/main.c src/game.c src/renderer.c src/snake.c src/food.c src/menu.c src/audio.c
OBJ = $(SRC:.c=.o)
TARGET = SnakeGame.exe

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	del /Q $(TARGET) *.o 2>NUL || rm -f $(TARGET) *.o

.PHONY: all clean

