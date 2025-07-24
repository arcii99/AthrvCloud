//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the grid
#define N 10

// Define the probability of a site being open
#define P 0.5

// Define the colors to represent open and closed sites
#define OPEN_COLOR "\033[0;107m"
#define CLOSED_COLOR "\033[0;40m"

// Array that holds the status of each site in the grid
int grid[N][N];

// Function to initialize the grid
void initialize_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double) rand() / (RAND_MAX) < P) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

// Function to print the grid in the console using colors
void print_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf(OPEN_COLOR "  \033[0m");
            } else {
                printf(CLOSED_COLOR "  \033[0m");
            }
        }
        printf("\n");
    }
}

// Function to check if the top and bottom of the grid are connected
int is_percolating() {
    int top[N], bottom[N];
    for (int i = 0; i < N; i++) {
        top[i] = 0;
        bottom[i] = 0;
    }
    // Check the top row
    for (int i = 0; i < N; i++) {
        if (grid[0][i] == 1) {
            top[i] = 1;
        }
    }
    // Check the bottom row
    for (int i = 0; i < N; i++) {
        if (grid[N-1][i] == 1) {
            bottom[i] = 1;
        }
    }
    // Check if there is a path from the top to the bottom
    for (int i = 0; i < N; i++) {
        if (top[i] == 1) {
            for (int j = 0; j < N; j++) {
                if (bottom[j] == 1) {
                    if (is_connected(i, j)) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// Function to check if two sites are connected
int is_connected(int i, int j) {
    if (grid[i][j] == 0) {
        return 0;
    }
    if (i == 0 || i == N-1 || j == 0 || j == N-1) {
        return 1;
    }
    if (is_connected(i-1, j) || is_connected(i+1, j) || is_connected(i, j-1) || is_connected(i, j+1)) {
        return 1;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    initialize_grid();
    print_grid();
    if (is_percolating()) {
        printf("The grid is percolating\n");
    } else {
        printf("The grid is not percolating\n");
    }
    return 0;
}