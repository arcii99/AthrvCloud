//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int visited[N][N] = {0};

int percolate(int matrix[][N], int row, int col) {
    if (row < 0 || row >= N || col < 0 || col >= N) { // checking boundry
        return 0;
    }
    if (matrix[row][col] == 0) { // checking if cell is blocked
        return 0;
    }
    if (visited[row][col] == 1) { // checking if cell is already visited
        return 0;
    }
    
    visited[row][col] = 1; // marking cell as visited
    percolate(matrix, row - 1, col); // checking top cell
    percolate(matrix, row + 1, col); // checking bottom cell
    percolate(matrix, row, col - 1); // checking left cell
    percolate(matrix, row, col + 1); // checking right cell

    return 1; // if reached here, cell is connected
}

int main() {
    int matrix[N][N];
    int i, j, count = 0;

    srand(time(0)); // seeding random number generator

    // initializing matrix randomly
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matrix[i][j] = rand() % 2;
        }
    }

    // printing matrix
    printf("Matrix:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // calling percolate function for top row
    for (j = 0; j < N; j++) {
        if (percolate(matrix, 0, j) == 1) {
            count++;
        }
    }

    // printing result
    if (count > 0) {
        printf("The matrix percolates!\n");
    } else {
        printf("The matrix does not percolate :(\n");
    }

    return 0;
}