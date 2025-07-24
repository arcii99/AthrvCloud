//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void print_grid(char grid[][SIZE], int size);
void percolate(char grid[][SIZE], int size);

int main() {
    srand(time(NULL));
    char grid[SIZE][SIZE];

    // initialize grid randomly with blocked (X) or open (.)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (rand() % 2 == 0)
                grid[i][j] = 'X';
            else
                grid[i][j] = '.';
        }
    }

    percolate(grid, SIZE);
    print_grid(grid, SIZE);

    return 0;
}

// print the grid in the console
void print_grid(char grid[][SIZE], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// percolate the grid using depth-first search
void percolate(char grid[][SIZE], int size) {
    int top_row[SIZE] = {0};

    // start with a DFS from every cell in the top row
    for (int j = 0; j < size; j++) {
        if (grid[0][j] == '.') {
            grid[0][j] = 'O'; // mark as open
            top_row[j] = 1; // mark as connected to top
            percolate_helper(grid, size, 0, j, top_row);
        }
    }

    // mark cells in the bottom row as connected to bottom if they are open
    for (int j = 0; j < size; j++) {
        if (grid[size-1][j] == 'O') {
            percolate_helper(grid, size, size-1, j, top_row);
        }
    }

    // mark all cells connected to top and bottom as percolating
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (grid[i][j] == 'O' && top_row[j] == 1) {
                grid[i][j] = 'P'; // mark as percolating
            }
        }
    }
}

// helper function for DFS
void percolate_helper(char grid[][SIZE], int size, int i, int j, int top_row[]) {
    if (i < 0 || i >= size || j < 0 || j >= size) {
        return;
    }
    if (grid[i][j] == 'X') {
        return;
    }
    if (grid[i][j] == 'O') {
        return;
    }

    grid[i][j] = 'O'; // mark as open

    if (i == size-1) {
        return;
    }

    // mark as connected to top if in top row
    if (top_row[j] == 1) {
        percolate_helper(grid, size, i, j-1, top_row);
        percolate_helper(grid, size, i, j+1, top_row);
    }

    percolate_helper(grid, size, i-1, j, top_row);
    percolate_helper(grid, size, i+1, j, top_row);
}