//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // size of grid
#define PERC 0.6 // probability of site being open
#define BLOCKED 0
#define OPEN 1
#define FULL 2

int grid[SIZE][SIZE];
int openSites = 0;

void initGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((float) rand() / RAND_MAX <= PERC) {
                grid[i][j] = OPEN;
                openSites++;
            } else {
                grid[i][j] = BLOCKED;
            }
        }
    }
}

void printGrid() {
    printf("   ");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i);
        for (int j = 0; j < SIZE; j++) {
            switch (grid[i][j]) {
                case BLOCKED:
                    printf("  X");
                    break;
                case OPEN:
                    printf("  O");
                    break;
                case FULL:
                    printf("  +");
                    break;
            }
        }
        printf("\n");
    }
}

void openSite(int i, int j) {
    if (i < 0 || i >= SIZE || j < 0 || j >= SIZE) {
        return;
    }
    if (grid[i][j] != OPEN) {
        return;
    }
    grid[i][j] = FULL;
    openSites--;
    openSite(i - 1, j);
    openSite(i + 1, j);
    openSite(i, j - 1);
    openSite(i, j + 1);
}

int main() {
    srand(time(NULL));
    initGrid();
    printGrid();
    while (openSites > 0) {
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        if (grid[i][j] == OPEN) {
            openSite(i, j);
        }
    }
    printGrid();
    return 0;
}