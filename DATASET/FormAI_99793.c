//FormAI DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 25 //Number of Rows for the grid
#define COLS 25 //Number of Columns for the grid

// Function to create and initialize the grid randomly
void initGrid(bool grid[ROWS][COLS]) {
    srand(time(NULL)); // seeding the random generator with current time
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2; // Assigning 0 or 1 randomly to each cell
        }
    }
}

// Function to print the current grid
void printGrid(bool grid[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] ? '#' : ' '); //Printing '#' for live cells and ' ' for dead cells
        }
        printf("\n");
    }
}

// Function to update the grid based on the rules of Game of Life
void updateGrid(bool grid[ROWS][COLS]) {
    int i, j, liveNeighbors;
    bool newGrid[ROWS][COLS]; // Array to store the updated grid
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            liveNeighbors = 0;
            if (i > 0 && j > 0 && grid[i-1][j-1]) liveNeighbors++; //Top Left
            if (i > 0 && grid[i-1][j]) liveNeighbors++; //Top
            if (i > 0 && j < COLS-1 && grid[i-1][j+1]) liveNeighbors++; //Top Right
            if (j > 0 && grid[i][j-1]) liveNeighbors++; //Left
            if (j < COLS-1 && grid[i][j+1]) liveNeighbors++; //Right
            if (i < ROWS-1 && j > 0 && grid[i+1][j-1]) liveNeighbors++; //Bottom Left
            if (i < ROWS-1 && grid[i+1][j]) liveNeighbors++; //Bottom
            if (i < ROWS-1 && j < COLS-1 && grid[i+1][j+1]) liveNeighbors++; //Bottom Right
            
            if (grid[i][j]) { // If cell is alive
                if (liveNeighbors < 2 || liveNeighbors > 3) newGrid[i][j] = false; // Under-population or Overpopulation
                else newGrid[i][j] = true; // Survive
            }
            else { // If cell is dead
                if (liveNeighbors == 3) newGrid[i][j] = true; // Reproduction
                else newGrid[i][j] = false; // Stay dead
            }
        }
    }
    // Copying updated grid to main grid
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    bool grid[ROWS][COLS]; // Main grid to store the status of each cell
    initGrid(grid); // Initializing the grid
    printf("Game of Life\n\n");
    while(true) { // Running an infinite loop
        printf("Current Grid\n");
        printGrid(grid); // Printing the grid
        updateGrid(grid); // Updating the grid based on rules of Game of Life
        printf("\nPress Ctrl+C to Exit.\n");
        sleep(1); // Delaying by 1 second before updating grid
        system("clear"); // Clearing the console
    }
    return 0;
}