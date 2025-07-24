//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// This function prints the given percolation matrix
void print_percolation(int perc[SIZE][SIZE]) {
    printf("Percolation Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", perc[i][j]);
        }
        printf("\n");
    }
}

// This function initializes the percolation matrix randomly
void init_percolation(int perc[SIZE][SIZE]) {
    srand(time(0)); // initializing random number generator
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (rand() % 2 == 0) {
                perc[i][j] = 1;
            } else {
                perc[i][j] = 0;
            }
        }
    }
    print_percolation(perc); // printing the initialized matrix
}

// This function checks if the percolation has occurred
int has_percolated(int perc[SIZE][SIZE]) {
    int top_count = 0, bottom_count = 0;
    for (int i = 0; i < SIZE; i++) {
        // Check if there is a connected path from top to bottom
        if (perc[0][i] == 1) {
            dfs(perc, 0, i, &top_count);
        }
        if (perc[SIZE-1][i] == 1) {
            dfs(perc, SIZE-1, i, &bottom_count);
        }
    }
    return top_count > 0 && bottom_count > 0;
}

// This function implements the depth first search algorithm
void dfs(int perc[SIZE][SIZE], int row, int col, int *count) {
    perc[row][col] = 2; // mark visited cell as 2
    (*count)++;
    if (row > 0 && perc[row-1][col] == 1) { // check north cell
        dfs(perc, row-1, col, count);
    }
    if (row < SIZE-1 && perc[row+1][col] == 1) { // check south cell
        dfs(perc, row+1, col, count);
    }
    if (col > 0 && perc[row][col-1] == 1) { // check west cell
        dfs(perc, row, col-1, count);
    }
    if (col < SIZE-1 && perc[row][col+1] == 1) { // check east cell
        dfs(perc, row, col+1, count);
    }
}

int main() {
    int perc[SIZE][SIZE];
    init_percolation(perc);
    if (has_percolated(perc)) {
        printf("Percolation has occurred!\n");
    } else {
        printf("Percolation has not occurred :(\n");
    }
    return 0;
}