//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 20
#define P 0.6

int grid[SIZE][SIZE];
int visited[SIZE][SIZE];

// A function to simulate percolation
void percolate(int x, int y) {
    if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) return;

    if (visited[x][y] || grid[x][y] == 0) return;

    visited[x][y] = 1;

    percolate(x - 1, y);
    percolate(x + 1, y);
    percolate(x, y - 1);
    percolate(x, y + 1);
}

int main() {
    //Initialize random seed
    srand((unsigned int) time(NULL));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = rand() < P * RAND_MAX ? 1 : 0;
        }
    }

    // Run percolate algorithm
    for (int i = 0; i < SIZE; i++) {
        if (grid[0][i]) {
            percolate(0, i);
        }
    }

    bool percolates = false;
    for (int i = 0; i < SIZE; i++) {
        if (visited[SIZE - 1][i]) {
            percolates = true;
            break;
        }
    }

    // Print out results
    printf("C Percolation Simulator\n");
    printf("=======================\n\n");
    printf("Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    if (percolates) {
        printf("The grid percolates!\n\n");
    } else {
        printf("The grid does not percolate.\n\n");
    }

    return 0;
}