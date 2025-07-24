//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIDE 20
#define PERCENTAGE 60

bool grid[SIDE][SIDE];
bool open[SIDE][SIDE];

int open_count = 0;
int num_iterations = 0;

// initialize grid with closed cells
void init_grid() {
    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++) {
            grid[i][j] = false;
        }
    }
}

// randomly open sites on the grid
void generate_random_sites() {
    for (int i = 0; i < SIDE; i++) {
        for (int j = 0; j < SIDE; j++) {
            int random = rand() % 100 + 1;
            if (random <= PERCENTAGE) {
                grid[i][j] = true;
            }
        }
    }
}

// helper function to print grid
void print_grid() {
    printf("+ ");
    for (int i = 0; i < SIDE; i++) {
        printf("--");
    }
    printf("+\n");

    for (int i = 0; i < SIDE; i++) {
        printf("| ");
        for (int j = 0; j < SIDE; j++) {
            if (grid[i][j]) {
                if (open[i][j]) {
                    printf(" ");
                } else {
                    printf("O");
                }
            } else {
                printf(" ");
            }
            printf(" ");
        }
        printf("|\n");
    }

    printf("+ ");
    for (int i = 0; i < SIDE; i++) {
        printf("--");
    }
    printf("+\n");
}

// helper function to check if a cell is valid
bool is_valid(int i, int j) {
    if (i < 0 || j < 0 || i >= SIDE || j >= SIDE) {
        return false;
    }
    return true;
}

// check if there is a path from the top to the bottom
void check_percolation() {
    for (int j = 0; j < SIDE; j++) {
        if (open[SIDE-1][j]) {
            printf("Percolation Reached!\n");
            return;
        }
    }
}

// depth-first search helper function
void dfs(int i, int j) {
    if (is_valid(i, j) && grid[i][j] && !open[i][j]) {
        open[i][j] = true;
        open_count++;
        dfs(i-1, j);
        dfs(i+1, j);
        dfs(i, j-1);
        dfs(i, j+1);
    }
}

// perform a single iteration of depth-first search
void iteration() {
    int i = rand() % SIDE;
    int j = rand() % SIDE;
    dfs(i, j);
    num_iterations++;
}

int main() {
    srand((unsigned) time(NULL));

    init_grid();
    generate_random_sites();

    while (true) {
        iteration();
        if (open_count >= SIDE) {
            check_percolation();
            break;
        }
    }

    printf("Number of iterations: %d\n", num_iterations);

    print_grid();

    return 0;
}