//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int grid[N][N];
int isOpen[N][N];
int isFull[N][N];

void initializeGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
            isOpen[i][j] = 0;
            isFull[i][j] = 0;
        }
    }
}

void open(int i, int j) {
    if (!isOpen[i][j]) {
        isOpen[i][j] = 1;
        if (grid[i][j] == 0) {
            if (i > 0) {
                if (isOpen[i-1][j]) {
                    isFull[i][j] = 1;
                }
            }
            if (i < N-1) {
                if (isOpen[i+1][j]) {
                    isFull[i][j] = 1;
                }
            }
            if (j > 0) {
                if (isOpen[i][j-1]) {
                    isFull[i][j] = 1;
                }
            }
            if (j < N-1) {
                if (isOpen[i][j+1]) {
                    isFull[i][j] = 1;
                }
            }
        }
    }
}

int percolates() {
    for (int j = 0; j < N; j++) {
        if (isFull[0][j]) {
            for (int i = 0; i < N; i++) {
                if (isFull[i][j] && isOpen[i][j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void printGrid() {
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) {
                printf("# ");
            } else if (isFull[i][j]) {
                printf("* ");
            } else if (isOpen[i][j]) {
                printf("  ");
            } else {
                printf("? ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initializeGrid();
    int i, j;
    while (!percolates()) {
        i = rand() % N;
        j = rand() % N;
        open(i, j);
    }
    printGrid();
    return 0;
}