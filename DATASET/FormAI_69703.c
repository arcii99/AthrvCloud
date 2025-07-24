//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 40
#define MAP_HEIGHT 20

char map[MAP_HEIGHT][MAP_WIDTH];

typedef struct {
    int x;
    int y;
} Position;

void generateMap() {
    int i, j;
    srand(time(NULL));

    // Initialize the map with walls
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            map[i][j] = '#';
        }
    }

    // Set a random starting point
    Position currentPos = {rand() % MAP_WIDTH, rand() % MAP_HEIGHT};
    map[currentPos.y][currentPos.x] = '@';

    // Generate the rest of the map
    while (1) {
        // Generate a random direction
        int direction = rand() % 4;
        Position newPos;

        // Move in the chosen direction
        switch (direction) {
            case 0:
                newPos = (Position){currentPos.x, currentPos.y - 1};
                break;
            case 1:
                newPos = (Position){currentPos.x, currentPos.y + 1};
                break;
            case 2:
                newPos = (Position){currentPos.x - 1, currentPos.y};
                break;
            case 3:
                newPos = (Position){currentPos.x + 1, currentPos.y};
                break;
        }

        // Check if we can move to the new position
        if(newPos.x >= 0 && newPos.x < MAP_WIDTH &&
           newPos.y >= 0 && newPos.y < MAP_HEIGHT &&
           map[newPos.y][newPos.x] == '#') {
            // Open the path and move to the new position
            map[newPos.y][newPos.x] = '.';
            currentPos = newPos;
        }

        // Exit when we can't move anymore
        if(map[currentPos.y - 1][currentPos.x] != '#' &&
           map[currentPos.y + 1][currentPos.x] != '#' &&
           map[currentPos.y][currentPos.x - 1] != '#' &&
           map[currentPos.y][currentPos.x + 1] != '#') {
            break;
        }
    }

    // Set the exit
    while (1) {
        int exitX = rand() % MAP_WIDTH;
        int exitY = rand() % MAP_HEIGHT;
        if(map[exitY][exitX] == '.') {
            map[exitY][exitX] = '>';
            break;
        }
    }
}

void displayMap() {
    int i, j;
    printf("\033[2J"); // Clear the screen
    printf("\033[%d;%dH", 0, 0); // Move cursor to the top-left position
    for (i = 0; i < MAP_HEIGHT; i++) {
        for (j = 0; j < MAP_WIDTH; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generateMap();
    displayMap();
    return 0;
}