//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void printGrid(char grid[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int percolates(char grid[N][N]) {
    for (int i = 0; i < N; ++i) {
        if (grid[N-1][i] == 'X') {
            return 1; // It's percolating!
        }
    }
    return 0; // Not yet!
}

int main() {
    
    srand(time(0));
    
    char grid[N][N];
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            grid[i][j] = '*';
        }
    }
    
    int start = rand() % N;
    grid[0][start] = 'X';
    printGrid(grid);
    
    while (!percolates(grid)) {
        int i = rand() % N;
        int j = rand() % N;
        if (grid[i][j] == '*') {
            grid[i][j] = ' ';
            printGrid(grid);
        }
    }
    
    printf("It percolated!\n");
    printGrid(grid);
    
    return 0;
}