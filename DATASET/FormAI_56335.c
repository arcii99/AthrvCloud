//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // size of the grid
#define P 0.6 // probability of each cell being open
#define MAXSTACK 400 // maximum size of the stack

// Declare struct to represent each site on grid
typedef struct {
    int row;
    int col;
} Site;

// Declare stack to keep track of open sites
Site stack[MAXSTACK];
int top = -1;

// Declare 2D array to represent the grid
int grid[SIZE][SIZE];

// Function to check if site is open
int is_open(Site s) {
    if (s.row < 0 || s.row >= SIZE || s.col < 0 || s.col >= SIZE) {
        return 0; // out of bounds
    }
    return grid[s.row][s.col];
}

// Function to open site
void open(Site s) {
    grid[s.row][s.col] = 1; // make site open
    stack[++top] = s; // push site onto stack
}

// Function to perform percolation
void percolate() {
    // Set random seed
    srand(time(NULL));
    
    // Initialize grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((double) rand() / (double) RAND_MAX < P) {
                grid[i][j] = 1; // open site with probability P
                stack[++top] = (Site) {i, j}; // push site onto stack
            }
            else {
                grid[i][j] = 0; // site closed
            }
        }
    }
    
    // Keep opening sites until percolation occurs
    while (!is_open((Site) {0, SIZE-1})) {
        // Pick a random site from the stack
        Site s = stack[top--];
        
        // Check neighboring sites and open them if they are closed
        Site neighbors[] = {{s.row-1, s.col}, {s.row+1, s.col}, {s.row, s.col-1}, {s.row, s.col+1}};
        for (int i = 0; i < 4; i++) {
            Site n = neighbors[i];
            if (is_open(n)) {
                continue;
            }
            else {
                open(n);
            }
        }
    }
    
    // Print percolation
    printf("Percolation occurred!\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", (grid[i][j] && is_open((Site) {0, SIZE-1})) ? 'O' : 'X');
        }
        printf("\n");
    }
}

// Main function
int main() {
    percolate();
    return 0;
}