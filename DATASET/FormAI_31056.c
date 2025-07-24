//FormAI DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 5
#define COLS 5

// Matrix A
int matrixA[ROWS][COLS] = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};

// Matrix B
int matrixB[ROWS][COLS] = {
    {1, 6, 11, 16, 21},
    {2, 7, 12, 17, 22},
    {3, 8, 13, 18, 23},
    {4, 9, 14, 19, 24},
    {5, 10, 15, 20, 25}
};

// Matrix C
int matrixC[ROWS][COLS];

// Struct to hold information for each thread
typedef struct {
    int row_start;
    int row_end;
} ThreadInfo;

// Function that each thread will execute
void* matrixMultiplication(void* arg) {
    ThreadInfo* info = (ThreadInfo*) arg;
    int row_start = info->row_start;
    int row_end = info->row_end;

    for (int i = row_start; i < row_end; i++) {
        for (int j = 0; j < COLS; j++) {
            int sum = 0;
            for (int k = 0; k < ROWS; k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            matrixC[i][j] = sum;
        }
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[ROWS];
    ThreadInfo info[ROWS];

    // Divide the work among the threads
    for (int i = 0; i < ROWS; i++) {
        info[i].row_start = i;
        info[i].row_end = i + 1;
        pthread_create(&threads[i], NULL, matrixMultiplication, &info[i]);
    }

    // Join the threads
    for (int i = 0; i < ROWS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the result
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

    printf("\nMatrix C:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrixC[i][j]);
        }
        printf("\n");
    }

    return 0;
}