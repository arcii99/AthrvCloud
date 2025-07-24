//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

// Generate random pixel art grid
void generateGrid(char grid[][GRID_SIZE]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            int randomInt = rand() % 2;
            grid[i][j] = (randomInt == 1) ? '#' : ' ';
        }
    }
}

// Print pixel art grid
void printGrid(char grid[][GRID_SIZE]) {
    int i, j;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    generateGrid(grid);
    printGrid(grid);
    return 0;
}