//FormAI DATASET v1.0 Category: Game of Life ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void initialize(int grid[SIZE][SIZE]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

int countNeighbors(int grid[SIZE][SIZE], int i, int j) {
    int x, y, count = 0;
    for (x = i-1; x <= i+1; x++) {
        for (y = j-1; y <= j+1; y++) {
            if (x == i && y == j) continue;
            if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) continue;
            count += grid[x][y];
        }
    }
    return count;
}

void nextGeneration(int grid[SIZE][SIZE]) {
    int i, j, neighbors;
    int next[SIZE][SIZE];
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            neighbors = countNeighbors(grid, i, j);
            if (grid[i][j]) {
                if (neighbors < 2 || neighbors > 3) next[i][j] = 0;
                else next[i][j] = 1;
            } else {
                if (neighbors == 3) next[i][j] = 1;
                else next[i][j] = 0;
            }
        }
    }
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = next[i][j];
        }
    }
}

void print(int grid[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}

int main() {
    int grid[SIZE][SIZE];
    initialize(grid);
    print(grid);
    printf("\n");
    nextGeneration(grid);
    print(grid);
    return 0;
}