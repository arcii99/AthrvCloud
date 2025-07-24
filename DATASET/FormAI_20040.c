//FormAI DATASET v1.0 Category: Game of Life ; Style: Cryptic
// Welcome to my cryptic C Game of Life example program!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int main() {
    // initialize the grid with random 0's and 1's
    int grid[ROWS][COLS];
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    
    // print the initial grid
    printf("Initial Grid:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j] == 1 ? '#' : ' ');
        }
        printf("\n");
    }
    
    // simulate the game of life
    int newGrid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            
            // count the number of live neighbors
            if (i > 0 && grid[i-1][j] == 1) neighbors++;
            if (i < ROWS-1 && grid[i+1][j] == 1) neighbors++;
            if (j > 0 && grid[i][j-1] == 1) neighbors++;
            if (j < COLS-1 && grid[i][j+1] == 1) neighbors++;
            if (i > 0 && j > 0 && grid[i-1][j-1] == 1) neighbors++;
            if (i > 0 && j < COLS-1 && grid[i-1][j+1] == 1) neighbors++;
            if (i < ROWS-1 && j > 0 && grid[i+1][j-1] == 1) neighbors++;
            if (i < ROWS-1 && j < COLS-1 && grid[i+1][j+1] == 1) neighbors++;
            
            // apply the rules of the game of life
            if (grid[i][j] == 1 && neighbors < 2) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                newGrid[i][j] = 1;
            } else if (grid[i][j] == 1 && neighbors > 3) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                newGrid[i][j] = 1;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    
    // print the new grid
    printf("New Grid:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", newGrid[i][j] == 1 ? '#' : ' ');
        }
        printf("\n");
    }
    
    return 0;
}