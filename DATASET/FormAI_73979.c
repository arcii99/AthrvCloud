//FormAI DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define ROWS 3
#define COLS 3

int matrixA[ROWS][COLS];
int matrixB[ROWS][COLS];
int matrixC[ROWS][COLS];

void *multiplyMatrix(void *arg) {
    int row = *((int *) arg);
    for (int i = 0; i < COLS; i++) {
        matrixC[row][i] = 0;
        for (int j = 0; j < ROWS; j++) {
            matrixC[row][i] += matrixA[row][j] * matrixB[j][i];
        }
    }
    printf("Finished multiplication of row %d\n", row + 1);
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));
    pthread_t tid[ROWS];
    int rowIndices[ROWS];

    // Initialize matrices
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrixA[i][j] = rand() % 10;
            matrixB[i][j] = rand() % 10;
            matrixC[i][j] = -1;
        }
    }

    // Display matrices
    printf("Matrix A:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix B:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    // Multiply matrices concurrently using threads
    for (int i = 0; i < ROWS; i++) {
        rowIndices[i] = i;
        pthread_create(&tid[i], NULL, multiplyMatrix, &rowIndices[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < ROWS; i++) {
        pthread_join(tid[i], NULL);
    }

    // Display result matrix
    printf("\nMatrix C:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }
    return 0;
}