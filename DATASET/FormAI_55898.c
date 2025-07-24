//FormAI DATASET v1.0 Category: Game of Life ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

//initialize matrix
void initMatrix(int matrix[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 2;
        }
    }
}

//print matrix
void printMatrix(int matrix[SIZE][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

//count live neighbors
int countNeighbors(int matrix[SIZE][SIZE], int i, int j) {
    int count = 0;
    int row, col;
    for (row = i-1; row <= i+1; row++) {
        for (col = j-1; col <= j+1; col++) {
            if (row == i && col == j) {
                continue;
            }
            if (row < 0 || col < 0 || row >= SIZE || col >= SIZE) {
                continue;
            }
            if (matrix[row][col] == 1) {
                count++;
            }
        }
    }
    return count;
}

//generate the next generation
void generateNextGen(int matrix[SIZE][SIZE], int newMatrix[SIZE][SIZE]) {
    int i, j, neighbors;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            neighbors = countNeighbors(matrix, i, j);
            if (matrix[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    newMatrix[i][j] = 0;
                }
                else {
                    newMatrix[i][j] = 1;
                }
            }
            else {
                if (neighbors == 3) {
                    newMatrix[i][j] = 1;
                }
                else {
                    newMatrix[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    int matrix[SIZE][SIZE];
    int newMatrix[SIZE][SIZE];
    srand(time(NULL));

    //initialize
    initMatrix(matrix);
    printMatrix(matrix);
    printf("\n");

    //generate first 10 generations
    int i;
    for (i = 0; i < 10; i++) {
        generateNextGen(matrix, newMatrix);
        memcpy(matrix, newMatrix, sizeof(matrix));
        printMatrix(matrix);
        printf("\n");
    }
    return 0;
}