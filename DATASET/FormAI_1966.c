//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 20

typedef struct {
    int x;
    int y;
} Point;

char grid[HEIGHT][WIDTH];
Point playerPos;

void initGrid() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = '#';
        }
    }
}

void printGrid() {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void placePlayer() {
    srand(time(NULL));
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;
    while (grid[y][x] != '#') {
        x = rand() % WIDTH;
        y = rand() % HEIGHT;
    }
    playerPos.x = x;
    playerPos.y = y;
    grid[y][x] = '@';
}

void movePlayer(int x, int y) {
    int newX = playerPos.x + x;
    int newY = playerPos.y + y;
    if (grid[newY][newX] == '#') {
        grid[playerPos.y][playerPos.x] = '#';
        playerPos.x = newX;
        playerPos.y = newY;
        grid[newY][newX] = '@';
    }
}

void generateLevel() {
    srand(time(NULL));
    int numWalls = rand() % ((WIDTH * HEIGHT) / 4); // 25% of total cells
    for (int i = 0; i < numWalls; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        while (grid[y][x] != '#') {
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        }
        grid[y][x] = '#';
    }
}

int main() {
    initGrid();
    placePlayer();
    generateLevel();
    printGrid();
    char input;
    while (input != 'q') {
        printf("Move with arrow keys, q to quit\n");
        input = getchar();
        switch(input) {
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
        printGrid();
    }
    return 0;
}