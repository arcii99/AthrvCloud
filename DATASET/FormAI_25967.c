//FormAI DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 20
#define COLS 40
#define GENERATIONS 100

// Function prototypes
void initialize(int grid[ROWS][COLS]);
void printGrid(int grid[ROWS][COLS]);
void nextGeneration(int currentGen[ROWS][COLS], int nextGen[ROWS][COLS]);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    int currentGen[ROWS][COLS];
    int nextGen[ROWS][COLS];

    // Initialize the current generation
    initialize(currentGen);

    // Print the initial grid
    printf("Initial Generation:\n");
    printGrid(currentGen);

    // Run the simulation through multiple generations
    for (int i = 0; i < GENERATIONS; i++) {
        // Generate the next generation
        nextGeneration(currentGen, nextGen);

        // Print the generation number and the grid
        printf("Generation %d:\n", i + 1);
        printGrid(nextGen);

        // Copy the next generation to the current generation
        for (int j = 0; j < ROWS; j++) {
            for (int k = 0; k < COLS; k++) {
                currentGen[j][k] = nextGen[j][k];
            }
        }
    }

    return 0;
}

void initialize(int grid[ROWS][COLS]) {
    // Initialize the grid with random cells
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid(int grid[ROWS][COLS]) {
    // Print the grid to the console
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

void nextGeneration(int currentGen[ROWS][COLS], int nextGen[ROWS][COLS]) {
    // Calculate the next generation according to the rules of the Game of Life
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Count the number of neighboring cells that are alive
            int numNeighbors = 0;
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (k >= 0 && k < ROWS && l >= 0 && l < COLS) {
                        if (currentGen[k][l] == 1 && !(k == i && l == j)) {
                            numNeighbors++;
                        }
                    }
                }
            }
            // Apply the rules of the Game of Life
            if (currentGen[i][j] == 1 && numNeighbors < 2) {
                nextGen[i][j] = 0; // Cell dies from underpopulation
            } else if (currentGen[i][j] == 1 && (numNeighbors == 2 || numNeighbors == 3)) {
                nextGen[i][j] = 1; // Cell stays alive
            } else if (currentGen[i][j] == 1 && numNeighbors > 3) {
                nextGen[i][j] = 0; // Cell dies from overpopulation
            } else if (currentGen[i][j] == 0 && numNeighbors == 3) {
                nextGen[i][j] = 1; // Cell is born
            } else {
                nextGen[i][j] = 0; // Cell stays dead
            }
        }
    }
}