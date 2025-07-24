//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
    int grid[SIZE][SIZE];
    int visited[SIZE][SIZE] = {0}; // initialize as all unvisited
    int open_count = 0; // number of open sites
    int i, j;

    // initializes random number generator
    srand(time(NULL));

    // initialize all sites as blocked
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    // randomly open some sites
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (rand() % 2 == 0) {
                grid[i][j] = 1;
                open_count++;
            }
        }
    }

    // print initial grid
    printf("Initial grid:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 1) printf("O ");
            else printf("X ");
        }
        printf("\n");
    }

    // check if any site is connected to top row
    for (j = 0; j < SIZE; j++) {
        if (grid[0][j] == 1) {
            visited[0][j] = 1;
            open_count++; // increase open_count for the site already opened at row 0
            dfs(0, j, grid, visited, &open_count);
        }
    }

    // print final grid
    printf("\nFinal grid:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j] == 1 && visited[i][j] == 0) printf("X "); // closed and disconnected sites
            else if (grid[i][j] == 1 && visited[i][j] == 1) printf("O "); // open and connected sites
            else printf("X "); // blocked sites
        }
        printf("\n");
    }

    printf("\nNumber of open sites: %d\n", open_count);

    return 0;
}

void dfs(int row, int col, int grid[][SIZE], int visited[][SIZE], int *count) {
    visited[row][col] = 1;

    int i, j;
    int delta_i[4] = {-1, 0, 1, 0};
    int delta_j[4] = {0, 1, 0, -1};

    for (i = 0; i < 4; i++) {
        int ii = row + delta_i[i];
        int jj = col + delta_j[i];
        if (ii >= 0 && ii < SIZE && jj >= 0 && jj < SIZE) {
            if (grid[ii][jj] == 1 && visited[ii][jj] == 0) {
                (*count)++;
                dfs(ii, jj, grid, visited, count);
            }
        }
    }
}