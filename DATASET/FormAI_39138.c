//FormAI DATASET v1.0 Category: Game of Life ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the grid size
#define ROWS 20
#define COLS 50

// Define function to randomly initialize the grid
void initGrid(int grid[][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Define function to print the grid
void printGrid(int grid[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

// Define function to count the number of alive neighbors
int countNeighbors(int grid[][COLS], int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int row = (x + i + ROWS) % ROWS;
            int col = (y + j + COLS) % COLS;
            count += grid[row][col];
        }
    }
    return count;
}

// Define function to update the grid based on the rules of the game
void updateGrid(int grid[][COLS], int newGrid[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

// Define the main function
int main() {
    int grid[ROWS][COLS];
    int newGrid[ROWS][COLS];

    // Initialize the grid
    initGrid(grid);

    // Loop through the generations of the game
    for (int i = 0; i < 100; i++) {
        // Clear the screen
        system("cls");

        // Print the current generation
        printf("Generation: %d\n", i);
        printGrid(grid);

        // Update the grid
        updateGrid(grid, newGrid);

        // Wait for a short time
        printf("\nPress any key to continue...\n");
        getchar();
    }

    // Exit the program
    return 0;
}