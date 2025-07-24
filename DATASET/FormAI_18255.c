//FormAI DATASET v1.0 Category: Game of Life ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define M 60

void printMatrix(char matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

void initializeMatrix(char matrix[N][M]) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (rand() % 2 == 0) {
                matrix[i][j] = '.';
            } else {
                matrix[i][j] = '*';
            }
        }
    }
}

int countNeighbors(char matrix[N][M], int row, int col) {
    int count = 0;
    if (row > 0) {
        if (matrix[row - 1][col] == '*') count++;
        if (col > 0 && matrix[row - 1][col - 1] == '*') count++;
        if (col < M - 1 && matrix[row - 1][col + 1] == '*') count++;
    }
    if (row < N - 1) {
        if (matrix[row + 1][col] == '*') count++;
        if (col > 0 && matrix[row + 1][col - 1] == '*') count++;
        if (col < M - 1 && matrix[row + 1][col + 1] == '*') count++;
    }
    if (col > 0 && matrix[row][col - 1] == '*') count++;
    if (col < M - 1 && matrix[row][col + 1] == '*') count++;
    return count;
}

void updateMatrix(char matrix[N][M]) {
    char newMatrix[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int count = countNeighbors(matrix, i, j);
            if (matrix[i][j] == '*') {
                if (count == 2 || count == 3) newMatrix[i][j] = '*';
                else newMatrix[i][j] = '.';
            } else {
                if (count == 3) newMatrix[i][j] = '*';
                else newMatrix[i][j] = '.';
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = newMatrix[i][j];
        }
    }
}

int main() {
    char matrix[N][M];
    initializeMatrix(matrix);
    printf("Initial Matrix:\n");
    printMatrix(matrix);
    while (1) {
        updateMatrix(matrix);
        printf("\n\n");
        printMatrix(matrix);
        printf("Press Enter to Continue or Ctrl+C to Stop");
        getchar();
    }
    return 0;
}