//FormAI DATASET v1.0 Category: Game of Life ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

// Function to print the grid
void printGrid(int grid[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

int main() {
    int grid[ROWS][COLS] = {0};
    srand(time(NULL));

    // Randomly set some cells as alive
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = (rand() % 2 == 1);
        }
    }

    // Display initial grid
    system("clear");
    printf("Welcome to the Game of Life!\n\n");
    printf("Press Ctrl+C to exit.\n\n");
    printGrid(grid);
    printf("\n");

    // Main game loop
    while(1) {
        int newGrid[ROWS][COLS] = {0};

        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                // Count surrounding live cells
                int neighbors = 0;
                for(int k = -1; k <= 1; k++) {
                    for(int l = -1; l <= 1; l++) {
                        if(i + k < 0 || i + k >= ROWS || j + l < 0 || j + l >= COLS) {
                            continue;
                        }
                        if(k == 0 && l == 0) {
                            continue;
                        }
                        if(grid[i+k][j+l]) {
                            neighbors++;
                        }
                    }
                }

                // Determine whether the cell lives or dies
                if(neighbors == 3) {
                    newGrid[i][j] = 1;
                } else if (grid[i][j] && neighbors == 2) {
                    newGrid[i][j] = 1;
                }
            }
        }

        // Update the grid and display it
        for(int i = 0; i < ROWS; i++) {
            for(int j = 0; j < COLS; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }
        usleep(500000);
        system("clear");
        printGrid(grid);
        printf("\n");
    }

    return 0;
}