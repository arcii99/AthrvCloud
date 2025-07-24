//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

// Function to print the current state of the percolation system
void printGrid(char grid[SIZE][SIZE]) {
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the percolation system has percolated (i.e. the top and bottom grids are connected)
int isPercolated(char grid[SIZE][SIZE]) {
    // Check if any cell in the bottom row is connected to any cell in the top row
    for(int i = 0; i < SIZE; i++) {
        if(grid[SIZE-1][i] == '#' && grid[0][i] == '#') {
            return 1;
        }
    }
    return 0;
}

// Function to simulate the percolation process
void percolate(char grid[SIZE][SIZE]) {
    // Generate random values for the top row of the percolation system
    srand(time(0));
    for(int i = 0; i < SIZE; i++) {
        int randNum = rand() % 2;
        if(randNum == 0) {
            grid[0][i] = ' ';
        } else {
            grid[0][i] = '#';
        }
    }
    
    // Loop through the rest of the cells in the grid
    for(int i = 1; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            // If the cell is already blocked, skip to the next cell
            if(grid[i][j] == '#') {
                continue;
            }
            // Check if any of the neighboring cells are open (i.e. not blocked)
            if(j > 0 && grid[i][j-1] == ' ') {
                grid[i][j] = ' ';
            } else if(j < SIZE-1 && grid[i][j+1] == ' ') {
                grid[i][j] = ' ';
            } else if(i < SIZE-1 && grid[i+1][j] == ' ') {
                grid[i][j] = ' ';
            }
        }
        printGrid(grid);
        // Check if the percolation system has percolated
        if(isPercolated(grid)) {
            printf("\n\nThe percolation system has percolated!\n");
            return;
        }
    }
    // If the percolation system has not percolated after all cells have been checked, print a message and exit
    printf("\n\nThe percolation system did not percolate :(\n");
}

int main() {
    char grid[SIZE][SIZE];
    // Initialize the grid to all blocked cells (#)
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            grid[i][j] = '#';
        }
    }
    // Print the initial state of the percolation system
    printGrid(grid);
    // Call the percolate function to simulate the process
    percolate(grid);
    return 0;
}