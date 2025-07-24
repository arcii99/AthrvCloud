//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

// Structure to store the state of the game
typedef struct Game {
    int playerX;
    int playerY;
    int level;
    char world[ROWS][COLS];
} Game;

// Function to generate random world
void generateWorld(char world[ROWS][COLS]) {
    srand(time(NULL));
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (rand() % 10 < 8) {
                world[row][col] = '.';
            } else {
                world[row][col] = '#';
            }
        }
    }
}

// Function to print the world
void printWorld(char world[ROWS][COLS], int playerX, int playerY) {
    system("clear");
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (row == playerY && col == playerX) {
                printf("@");
            } else {
                printf("%c", world[row][col]);
            }
        }
        printf("\n");
    }
}

// Function to move the player
void movePlayer(Game* game, int deltaX, int deltaY) {
    int newPlayerX = game->playerX + deltaX;
    int newPlayerY = game->playerY + deltaY;
    if (newPlayerX < 0 || newPlayerX >= COLS) {
        return;
    }
    if (newPlayerY < 0 || newPlayerY >= ROWS) {
        return;
    }
    if (game->world[newPlayerY][newPlayerX] == '#') {
        return;
    }
    game->playerX = newPlayerX;
    game->playerY = newPlayerY;
}

// Function to play the game
void playGame() {
    Game game;
    game.level = 1;
    generateWorld(game.world);
    game.playerX = COLS / 2;
    game.playerY = ROWS / 2;
    while (1) {
        printWorld(game.world, game.playerX, game.playerY);
        int deltaX = 0;
        int deltaY = 0;
        char input = getchar();
        switch (input) {
            case 'w':
                deltaY = -1;
                break;
            case 's':
                deltaY = 1;
                break;
            case 'a':
                deltaX = -1;
                break;
            case 'd':
                deltaX = 1;
                break;
        }
        movePlayer(&game, deltaX, deltaY);
    }
}

int main() {
    playGame();
    return 0;
}