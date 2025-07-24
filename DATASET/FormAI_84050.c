//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define SIZE 20
#define MAX_ITER 100
#define PERC_THRESHOLD 0.6
#define NEIGHBORS 4

// Define struct for cell
typedef struct {
    int x;
    int y;
    int id;
    int state; // 0 for blocked, 1 for open
} cell;

// Function to create grid
void createGrid(cell grid[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].id = i * SIZE + j;
            grid[i][j].state = rand() < RAND_MAX * PERC_THRESHOLD ? 1 : 0;
        }
    }
}

// Function to find root of cluster using path compression
cell findRoot(cell grid[][SIZE], int idx) {
    cell temp = grid[idx/SIZE][idx%SIZE];
    if (temp.id != idx) {
        temp = findRoot(grid, temp.id);
    }
    grid[idx/SIZE][idx%SIZE] = temp;
    return temp;
}

// Function to connect two clusters
void connect(cell grid[][SIZE], cell c1, cell c2) {
    cell root1 = findRoot(grid, c1.id);
    cell root2 = findRoot(grid, c2.id);
    if (root1.id != root2.id) {
        root2.id = root1.id;
        root2.state = root1.state;
    }
}

// Function to check if grid is percolating
int isPercolating(cell grid[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[0][i].state && grid[SIZE-1][j].state) {
                if (findRoot(grid, SIZE*i).id == findRoot(grid, SIZE*(SIZE-1)+j).id) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Main function
int main() {
    // Declare variables
    int i, j, k, iter, c1, c2;
    cell grid[SIZE][SIZE];
    srand(time(NULL));

    // Create grid
    createGrid(grid);

    // Perform Monte Carlo simulation 
    for (iter = 0; iter < MAX_ITER; iter++) {
        // Connect neighboring cells
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (grid[i][j].state == 1) {
                    for (k = 0; k < NEIGHBORS; k++) {
                        if (k == 0 && i > 0) { // check north
                            if (grid[i-1][j].state == 1) {
                                connect(grid, grid[i-1][j], grid[i][j]);
                            }
                        }
                        if (k == 1 && j < SIZE-1) { // check east
                            if (grid[i][j+1].state == 1) {
                                connect(grid, grid[i][j+1], grid[i][j]);
                            }
                        }
                        if (k == 2 && i < SIZE-1) { // check south
                            if (grid[i+1][j].state == 1) {
                                connect(grid, grid[i+1][j], grid[i][j]);
                            }
                        }
                        if (k == 3 && j > 0) { // check west
                            if (grid[i][j-1].state == 1) {
                                connect(grid, grid[i][j-1], grid[i][j]);
                            }
                        }
                    }
                }
            }
        }
        // Check if percolating
        if (isPercolating(grid)) {
            printf("Percolating after %d iterations\n", iter+1);
            break;
        }
    }

    return 0;
}