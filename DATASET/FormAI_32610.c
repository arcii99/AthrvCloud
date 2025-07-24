//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int grid[SIZE][SIZE]; // our percolation grid

void initializeGrid() {
    // initialize the grid with 0's (meaning the site is blocked)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}

void printGrid() {
    // print the grid to the console
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int percolates() {
    // check if the top row is connected to the bottom row
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j] == 1) {
            // we found a site that is open at the top row
            // let's explore its neighbors
            int visited[SIZE][SIZE] = {0}; // to keep track of visited sites
            visited[0][j] = 1;
            int stack[SIZE*SIZE][2];
            int top = 0;
            stack[top][0] = 0;
            stack[top][1] = j;
            while (top >= 0) {
                int i = stack[top][0];
                int j = stack[top][1];
                top--;
                if (i > 0 && grid[i-1][j] == 1 && !visited[i-1][j]) {
                    visited[i-1][j] = 1;
                    stack[++top][0] = i-1;
                    stack[top][1] = j;
                }
                if (i < SIZE-1 && grid[i+1][j] == 1 && !visited[i+1][j]) {
                    visited[i+1][j] = 1;
                    stack[++top][0] = i+1;
                    stack[top][1] = j;
                }
                if (j > 0 && grid[i][j-1] == 1 && !visited[i][j-1]) {
                    visited[i][j-1] = 1;
                    stack[++top][0] = i;
                    stack[top][1] = j-1;
                }
                if (j < SIZE-1 && grid[i][j+1] == 1 && !visited[i][j+1]) {
                    visited[i][j+1] = 1;
                    stack[++top][0] = i;
                    stack[top][1] = j+1;
                }
            }
            // check if there is an open site in the bottom row that we visited
            for (int j = 0; j < SIZE; j++) {
                if (grid[SIZE-1][j] == 1 && visited[SIZE-1][j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    initializeGrid();
    srand(time(NULL)); // set the seed for random number generation
    int openSitesCount = 0;
    while (!percolates()) {
        // keep opening sites randomly until the grid percolates
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        if (grid[i][j] == 0) {
            grid[i][j] = 1;
            openSitesCount++;
        }
    }
    printf("Percolation complete! Total open sites: %d\n", openSitesCount);
    printGrid();
    return 0;
}