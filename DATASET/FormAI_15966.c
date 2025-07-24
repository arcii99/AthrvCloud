//FormAI DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 30
#define MAX_COLS 100

char map[MAX_ROWS][MAX_COLS];

void generateMap(int rows, int cols) {
    // Randomly generate map
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int randNum = rand() % 100;
            if (randNum < 30) {
                map[i][j] = '#'; // Wall
            } else if (randNum < 60) {
                map[i][j] = '.'; // Floor
            } else {
                map[i][j] = '*'; // Treasure
            }
        }
    }
}

void printMap(int rows, int cols) {
    // Print out map
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(0)); // Seed random number generator with current time

    generateMap(MAX_ROWS, MAX_COLS);
    printMap(MAX_ROWS, MAX_COLS);

    return 0;
}