//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
 
int grid[SIZE][SIZE];
int visited[SIZE][SIZE];
int openSites = 0;
 
void initializeGrid() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
            visited[i][j] = 0;
        }
    }
}
 
int hasPathToTop(int row, int col) {
    if (row <= 0) {
        return 1;
    } else if (grid[row-1][col]) {
        return 1;
    } else {
        return 0;
    }
}
 
void markNeighbors(int row, int col) {
    if (row > 0) {
        if (grid[row-1][col] && !visited[row-1][col]) {
            visited[row-1][col] = 1;
            markNeighbors(row-1, col);
        }
    }
    if (row < SIZE-1) {
        if (grid[row+1][col] && !visited[row+1][col]) {
            visited[row+1][col] = 1;
            markNeighbors(row+1, col);
        }
    }
    if (col > 0) {
        if (grid[row][col-1] && !visited[row][col-1]) {
            visited[row][col-1] = 1;
            markNeighbors(row, col-1);
        }
    }
    if (col < SIZE-1) {
        if (grid[row][col+1] && !visited[row][col+1]) {
            visited[row][col+1] = 1;
            markNeighbors(row, col+1);
        }
    }
}
 
int hasPercolation() {
    int i;
    for (i = 0; i < SIZE; i++) {
        if (visited[SIZE-1][i]) {
            return 1;
        }
    }
    return 0;
}
 
void printGrid() {
    printf("  ");
    int i;
    for (i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
 
    int j;
    for (i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (j = 0; j < SIZE; j++) {
            if (grid[i][j]) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
 
int main() {
    srand(time(NULL));
    initializeGrid();
    int row, col;
    while (!hasPercolation()) {
        row = rand() % SIZE;
        col = rand() % SIZE;
 
        if (grid[row][col]) {
            continue;
        }
 
        grid[row][col] = 1;
        visited[row][col] = 1;
        markNeighbors(row, col);
        openSites++;
    }
 
    printGrid();
    printf("\nNumber of open sites: %d\n", openSites);
 
    if (hasPercolation()) {
        printf("Percolates!\n");
    } else {
        printf("Does not percolate.\n");
    }
 
    return 0;
}