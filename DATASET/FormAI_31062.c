//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

bool grid[ROWS][COLS];

void display_grid() {
    /* Display the grid */
    printf("Grid:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j]) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

bool is_percolating() {
    /* Check if the top row is connected to the bottom row */
    for(int j = 0; j < COLS; j++) {
        if(grid[0][j] && grid[ROWS-1][j]) {
            return true;
        }
    }
    return false;
}

void percolate(int i, int j) {
    /* Mark the cell as open */
    grid[i][j] = true;

    /* Recursively percolate in all directions */
    if(i > 0 && !grid[i-1][j]) {
        percolate(i-1, j);
    }
    if(i < ROWS-1 && !grid[i+1][j]) {
        percolate(i+1, j);
    }
    if(j > 0 && !grid[i][j-1]) {
        percolate(i, j-1);
    }
    if(j < COLS-1 && !grid[i][j+1]) {
        percolate(i, j+1);
    }
}

int main() {
    /* Initialize the grid with closed cells */
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = false;
        }
    }

    /* Open random cells until the grid percolates */
    int count = 0;
    while(!is_percolating()) {
        int i = rand() % ROWS;
        int j = rand() % COLS;

        if(!grid[i][j]) {
            percolate(i, j);
            count++;
        }
    }

    /* Display the percolating grid and the number of open cells */
    display_grid();
    printf("Percolating grid with %d open cells\n", count);

    return 0;
}