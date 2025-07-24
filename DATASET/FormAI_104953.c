//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 50 // size of the grid
#define PROBABILITY 0.6 // probability of a cell being open

// function to generate random number between 0 and 1
double frand() {
    return (double)rand() / (double)RAND_MAX;
}

// function to initialize grid with closed cells
void initialize(int grid[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}

// function to randomly open cells in the grid based on probability
void generate(int grid[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (frand() < PROBABILITY) {
                grid[i][j] = 1;
            }
        }
    }
}

// function to print the grid
void print_grid(int grid[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if a cell is connected to the top row
bool is_percolating(int grid[][SIZE]) {
    bool connected = false;
    bool visited[SIZE][SIZE] = {{false}};
    
    // mark cells in top row as visited and check if any of them are open
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j] == 1) {
            visited[0][j] = true;
            connected = true;
        }
    }
    
    // check if any neighboring cells are open and unvisited
    while (connected) {
        bool new_connected = false;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (visited[i][j] && grid[i][j] == 1) {
                    if (i > 0 && !visited[i-1][j]) {
                        visited[i-1][j] = true;
                        new_connected = true;
                    }
                    if (i < SIZE-1 && !visited[i+1][j]) {
                        visited[i+1][j] = true;
                        new_connected = true;
                    }
                    if (j > 0 && !visited[i][j-1]) {
                        visited[i][j-1] = true;
                        new_connected = true;
                    }
                    if (j < SIZE-1 && !visited[i][j+1]) {
                        visited[i][j+1] = true;
                        new_connected = true;
                    }
                }
            }
        }
        if (!new_connected) {
            break;
        }
    }
    
    // check if any cells in bottom row are connected
    for (int j = 0; j < SIZE; j++) {
        if (visited[SIZE-1][j] && grid[SIZE-1][j] == 1) {
            return true;
        }
    }
    
    return false;
}

// main function
int main() {
    int grid[SIZE][SIZE];
    
    // seed random number generator
    srand(time(NULL));
    
    initialize(grid);
    generate(grid);
    
    printf("Initial Grid:\n");
    print_grid(grid);
    
    // check if grid percolates
    if (is_percolating(grid)) {
        printf("Grid Percolates!\n");
    } else {
        printf("Grid Does Not Percolate.\n");
    }
    
    return 0;
}