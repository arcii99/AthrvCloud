//FormAI DATASET v1.0 Category: Game of Life ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void displayGrid(char grid[ROWS][COLS]);
void updateGrid(char grid[ROWS][COLS]);

int main() {
    // Create grid and randomly populate it
    char grid[ROWS][COLS];
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = (rand() % 2) ? 'X' : '.';
        }
    }
    
    // Display initial grid and wait for user input to continue
    displayGrid(grid);
    printf("\n\nPress enter to start the game of life.\n");
    getchar();
    
    // Loop through the game of life until all cells are dead or the user terminates
    while (1) {
        // Clear the screen and update the grid
        system("clear");
        updateGrid(grid);

        // Check if all cells are dead or wait for user input to continue
        int aliveCells = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 'X') aliveCells++;
            }
        }
        if (aliveCells == 0) {
            printf("\n\nAll cells are dead. Game over.\n");
            break;
        }
        printf("\n\nPress q to quit or enter to continue.\n");
        char input = getchar();
        if (input == 'q' || input == 'Q') break;
    }
    
    return 0;
}

void displayGrid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void updateGrid(char grid[ROWS][COLS]) {
    int nNeighbors;
    char newGrid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            nNeighbors = 0;
            
            // Count the number of neighbors
            if ((i > 0 && j > 0) && grid[i-1][j-1] == 'X') nNeighbors++;
            if ((i > 0) && grid[i-1][j] == 'X') nNeighbors++;
            if ((i > 0 && j < COLS-1) && grid[i-1][j+1] == 'X') nNeighbors++;
            if ((j > 0) && grid[i][j-1] == 'X') nNeighbors++;
            if ((j < COLS-1) && grid[i][j+1] == 'X') nNeighbors++;
            if ((i < ROWS-1 && j > 0) && grid[i+1][j-1] == 'X') nNeighbors++;
            if ((i < ROWS-1) && grid[i+1][j] == 'X') nNeighbors++;
            if ((i < ROWS-1 && j < COLS-1) && grid[i+1][j+1] == 'X') nNeighbors++;
            
            // Update cell based on the number of neighbors
            if (grid[i][j] == 'X') {
                if (nNeighbors == 2 || nNeighbors == 3) newGrid[i][j] = 'X';
                else newGrid[i][j] = '.';
            } else {
                if (nNeighbors == 3) newGrid[i][j] = 'X';
                else newGrid[i][j] = '.';
            }
        }
    }
    // Copy the new grid to the old grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
    // Display the updated grid
    displayGrid(grid);
}