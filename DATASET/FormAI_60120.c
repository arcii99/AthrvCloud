//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 50
#define MAP_HEIGHT 20

typedef enum {
    EMPTY = '.',
    WALL = '#',
    PLAYER = '@',
    ENEMY = 'E',
    ITEM = '+'
}
MapTiles;

char map[MAP_HEIGHT][MAP_WIDTH];
int playerX, playerY;

// Generates a random map with walls and items placed randomly
void generateMap() {
    srand(time(NULL));

    // Initialize everything to empty tiles first
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = EMPTY;
        }
    }

    // Place walls randomly
    for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT / 3; i++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        map[y][x] = WALL;
    }

    // Place items randomly
    for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT / 10; i++) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;
        map[y][x] = ITEM;
    }

    // Place the player and an enemy randomly
    int playerPlaced = 0;
    int enemyPlaced = 0;

    while (!playerPlaced || !enemyPlaced) {
        int x = rand() % MAP_WIDTH;
        int y = rand() % MAP_HEIGHT;

        if (map[y][x] == EMPTY) {
            if (!playerPlaced) {
                map[y][x] = PLAYER;
                playerX = x;
                playerY = y;
                playerPlaced = 1;
            }
            else if (!enemyPlaced) {
                map[y][x] = ENEMY;
                enemyPlaced = 1;
            }
        }
    }
}

// Moves the player in the given direction if possible
void movePlayer(int dx, int dy) {
    int newX = playerX + dx;
    int newY = playerY + dy;

    if (newX >= 0 && newX < MAP_WIDTH && newY >= 0 && newY < MAP_HEIGHT &&
        map[newY][newX] != WALL && map[newY][newX] != ENEMY) {
        map[playerY][playerX] = EMPTY;
        playerX = newX;
        playerY = newY;
        map[playerY][playerX] = PLAYER;
    }
}

int main() {
    generateMap();

    // Game loop
    int gameOver = 0;

    while (!gameOver) {
        system("clear");

        // Print the map
        for (int y = 0; y < MAP_HEIGHT; y++) {
            for (int x = 0; x < MAP_WIDTH; x++) {
                putchar(map[y][x]);
            }
            putchar('\n');
        }

        // Get player input and move the player
        char input;

        do {
            printf("Enter a movement direction (WASD): ");
            input = getchar();
        } while (input != 'w' && input != 'a' && input != 's' && input != 'd');

        switch (input) {
            case 'w':
                movePlayer(0, -1);
                break;
            case 'a':
                movePlayer(-1, 0);
                break;
            case 's':
                movePlayer(0, 1);
                break;
            case 'd':
                movePlayer(1, 0);
                break;
        }

        // Check if the player has won or lost
        if (map[playerY][playerX] == ENEMY) {
            printf("Game over! You were killed by an enemy.\n");
            gameOver = 1;
        }
        else if (map[playerY][playerX] == ITEM) {
            printf("You found a valuable item!\n");
            map[playerY][playerX] = EMPTY;
        }
        else if (map[playerY][playerX] == MAP_HEIGHT - 1) {
            printf("Congratulations! You have escaped the dungeon.\n");
            gameOver = 1;
        }
    }

    return 0;
}