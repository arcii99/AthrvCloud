//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 25

typedef struct {
    int x;
    int y;
} Point;

Point player;
char map[HEIGHT][WIDTH];

void generateMap();
void placePlayer();
void printMap();

int main() {
    generateMap();
    placePlayer();
    printMap();

    return 0;
}

void generateMap() {
    srand(time(NULL));

    // Generate walls
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (rand() % 100 < 35) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }

    // Generate doors
    for (i = 1; i < HEIGHT - 1; i++) {
        for (j = 1; j < WIDTH - 1; j++) {
            if (map[i][j] == '#') {
                int adjacentWalls = 0;
                if (map[i-1][j] == '#') adjacentWalls++;
                if (map[i+1][j] == '#') adjacentWalls++;
                if (map[i][j-1] == '#') adjacentWalls++;
                if (map[i][j+1] == '#') adjacentWalls++;
                if (adjacentWalls == 1 && rand() % 100 < 20) {
                    map[i][j] = '+';
                }
            }
        }
    }
}

void placePlayer() {
    player.x = WIDTH / 2;
    player.y = HEIGHT / 2;

    while (map[player.y][player.x] == '#') {
        player.x = rand() % WIDTH;
        player.y = rand() % HEIGHT;
    }

    map[player.y][player.x] = '@';
}

void printMap() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}