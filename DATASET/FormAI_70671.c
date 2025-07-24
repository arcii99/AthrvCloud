//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int grid[N][N], visited[N][N];

// Function to check if a site is open or not
int is_open(int i, int j) {
    if (grid[i][j] == 0) {
        return 0;
    } else {
        return 1;
    }
}

// Function to open a site
void open(int i, int j) {
    if (grid[i][j] == 0) {
        grid[i][j] = 1;
    }
}

// Function to initialize the grid
void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}

// Function to print the grid
void print_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Function to check if percolation has occured
int percolates() {
    int bottom_open = 0;

    for (int i = 0; i < N; i++) {
        if (grid[N-1][i] == 1 && visited[N-1][i] == 0) {
            visited[N-1][i] = 1;
            bottom_open = 1;
            break;
        }
    }

    if (bottom_open == 0) {
        return 0;
    }

    for (int i = N-2; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = 1;
                if (visited[i+1][j] == 1 || 
                    (j < N-1 && visited[i][j+1] == 1) || 
                    (j > 0 && visited[i][j-1] == 1)) {
                    if (i == 0) {
                        return 1;
                    }
                    continue;
                }
            }
        }
    }

    return 0;
}

// Function to randomly open sites
void generate() {
    srand(time(NULL));    

    while (1) {
        int i = rand() % N;
        int j = rand() % N;
        if (grid[i][j] == 0) {
            open(i, j);
        }
        if (percolates() == 1) {
            break;
        }
    }
}

// Main function to run the program
int main() {
    init();
    generate();
    print_grid();
    return 0;
}