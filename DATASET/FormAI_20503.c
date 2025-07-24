//FormAI DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROWS 20
#define COLS 40

// Function to print the current generation
void printGeneration(char grid[][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to generate the next generation based on the previous generation
void generateNextGeneration(char grid[][COLS], char newGrid[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if ((k == 0 && l == 0) || i + k < 0 || i + k >= ROWS || j + l < 0 || j + l >= COLS) {
                        continue;
                    }
                    if (grid[i + k][j + l] == '*') {
                        neighbors++;
                    }
                }
            }
            if (grid[i][j] == '*' && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = ' ';
            } else if (grid[i][j] == ' ' && neighbors == 3) {
                newGrid[i][j] = '*';
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
}

int main() {
    // seed the random number generator
    srand(time(NULL));

    // initialize the grid with random values
    char grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2 ? '*' : ' ';
        }
    }

    // print initial generation
    printGeneration(grid);

    // loop through generations
    for (int gen = 1;;gen++) {
        char newGrid[ROWS][COLS];
        generateNextGeneration(grid, newGrid);

        // clear the console and print the new generation
        printf("\033[2J");
        printf("\033[%d;%dH",0,0);
        printGeneration(newGrid);

        // copy the new grid to the old grid for the next iteration
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }

        // sleep for 100ms between generations
        usleep(100000);
    }

    return 0;
}