//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

char grid[WIDTH][HEIGHT];

// function to generate random integers from a to b
int randomInt(int a, int b) {
    return rand() % (b - a + 1) + a;
}

// function to clear the grid
void clearGrid() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            grid[x][y] = ' ';
        }
    }
}

// function to print the grid
void printGrid() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", grid[x][y]);
        }
        printf("\n");
    }
}

// function to generate procedural dungeon
void generateDungeon() {
    // generate random seed
    srand(time(NULL));

    // randomize room count
    int roomCount = randomInt(5, 10);

    // initialize room array
    int roomX[roomCount];
    int roomY[roomCount];
    int roomWidth[roomCount];
    int roomHeight[roomCount];

    // generate rooms
    for (int i = 0; i < roomCount; i++) {
        // randomize room size
        roomWidth[i] = randomInt(3, 7);
        roomHeight[i] = randomInt(3, 7);

        // randomize room position
        roomX[i] = randomInt(1, WIDTH - roomWidth[i] - 1);
        roomY[i] = randomInt(1, HEIGHT - roomHeight[i] - 1);

        // draw room on grid
        for (int x = roomX[i]; x < roomX[i] + roomWidth[i]; x++) {
            for (int y = roomY[i]; y < roomY[i] + roomHeight[i]; y++) {
                if (x == roomX[i] || x == roomX[i] + roomWidth[i] - 1 || y == roomY[i] || y == roomY[i] + roomHeight[i] - 1) {
                    grid[x][y] = '#';
                } else {
                    grid[x][y] = '.';
                }
            }
        }
    }

    // generate corridors
    for (int i = 0; i < roomCount - 1; i++) {
        int x1 = roomX[i] + roomWidth[i] / 2;
        int y1 = roomY[i] + roomHeight[i] / 2;
        int x2 = roomX[i + 1] + roomWidth[i + 1] / 2;
        int y2 = roomY[i + 1] + roomHeight[i + 1] / 2;

        while (x1 != x2 || y1 != y2) {
            if (x1 < x2) {
                x1++;
            } else if (x1 > x2) {
                x1--;
            } else if (y1 < y2) {
                y1++;
            } else if (y1 > y2) {
                y1--;
            }

            if (grid[x1][y1] == ' ') {
                grid[x1][y1] = '#';
            }
        }
    }
}

int main() {
    clearGrid();
    generateDungeon();
    printGrid();

    return 0;
}