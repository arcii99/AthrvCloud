//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int percolates(int grid[SIZE][SIZE]) {
    int topConnected = 0, bottomConnected = 0;
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j]) {
            topConnected = 1;
        }
        if (grid[SIZE-1][j]) {
            bottomConnected = 1;
        }
    }
    return (topConnected && bottomConnected);
}

int main() {
    int grid[SIZE][SIZE] = {0};
    srand(time(NULL));
    int count = 0;
    while (!percolates(grid)) {
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        if (!grid[i][j]) {
            grid[i][j] = 1;
            count++;
        }
    }
    printf("Percolated after %d attempts.\n", count);
    printGrid(grid);
    return 0;
}