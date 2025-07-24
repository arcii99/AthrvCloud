//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void display_grid(int grid[SIZE][SIZE], int size);
void percolate(int grid[SIZE][SIZE], int size);
int is_percolated(int grid[SIZE][SIZE], int size);
int neighbours_percolated(int grid[SIZE][SIZE], int size, int row, int col);

int main() {
    int grid[SIZE][SIZE] = {0};
    
    srand(time(NULL));
    
    // randomly assign open and closed sites
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int r = rand() % 100;
            if (r < 60) {
                grid[i][j] = 1; // open site
            } else {
                grid[i][j] = 0; // closed site
            }
        }
    }
    
    // display initial grid
    display_grid(grid, SIZE);
    
    // run percolation simulation
    percolate(grid, SIZE);
    
    // display final grid
    display_grid(grid, SIZE);
    
    // check if percolated and print result
    if (is_percolated(grid, SIZE)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    
    return 0;
}

void display_grid(int grid[SIZE][SIZE], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 1) {
                printf("| |");
            } else {
                printf("###");
            }
        }
        printf("\n");
    }
}

void percolate(int grid[SIZE][SIZE], int size) {
    int changed = 1;
    while (changed) {
        changed = 0;
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (grid[i][j] == 0 && neighbours_percolated(grid, size, i, j)) {
                    grid[i][j] = 1;
                    changed = 1;
                }
            }
        }
    }
}

int is_percolated(int grid[SIZE][SIZE], int size) {
    // check if any cell on the bottom row is filled
    for (int j = 0; j < size; j++) {
        if (grid[size-1][j] == 1) {
            return 1;
        }
    }
    
    return 0;
}

int neighbours_percolated(int grid[SIZE][SIZE], int size, int row, int col) {
    // get neighbouring cells
    int top = row > 0 ? grid[row-1][col] : 0;
    int left = col > 0 ? grid[row][col-1] : 0;
    int right = col < size-1 ? grid[row][col+1] : 0;
    int bottom = row < size-1 ? grid[row+1][col] : 0;
    
    // check if any neighbouring cells are filled
    if (top == 1 || left == 1 || right == 1 || bottom == 1) {
        return 1;
    } else {
        return 0;
    }
}