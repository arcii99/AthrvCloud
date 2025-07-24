//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 10

bool grid[N][N];
bool full[N][N];
bool visited[N][N];

// Initialize grid with random values
void initGrid() {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            grid[i][j] = rand() % 2 == 0;
            full[i][j] = false;
            visited[i][j] = false;
        }
    }
}

// Print the grid
void printGrid() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j]) printf("X ");
            else printf("O ");
        }
        printf("\n");
    }
}

// Check if the cell is within the bounds of the grid and is not visited yet
bool isValid(int row, int col) {
    return (row >= 0) && (row < N) && (col >= 0) && (col < N) && !visited[row][col];
}

// Check if there is a path from top to the bottom of the grid
void percolate() {
    int i, j;
    for (j = 0; j < N; j++) {
        if (grid[0][j]) {
            visited[0][j] = true;
            full[0][j] = true;
        }
    }
    for (i = 1; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] && full[i-1][j]) {
                visited[i][j] = true;
                full[i][j] = true;
                if (i == N-1) {
                    printf("Percolation achieved!\n");
                    return;
                }
            }
        }
    }
    printf("Percolation not achieved...\n");
}

int main() {
    initGrid();
    printGrid();
    percolate();
    return 0;
}