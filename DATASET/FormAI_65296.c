//FormAI DATASET v1.0 Category: Matrix operations ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 5
#define COLS 5

int matrix1[ROWS][COLS];
int matrix2[ROWS][COLS];
int result[ROWS][COLS];

struct args {
    int row;
    int col;
};

void *matrix_multiply(void *arg) {
    struct args *index = (struct args *) arg;
    int row = index->row;
    int col = index->col;

    int i;
    for (i = 0; i < COLS; i++) {
        result[row][col] += matrix1[row][i] * matrix2[i][col];
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[ROWS][COLS];
    struct args arguments[ROWS][COLS];
    int i, j;

    // Generate random matrices
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }
    }

    // Create threads for each element multiplication
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            arguments[i][j].row = i;
            arguments[i][j].col = j;
            pthread_create(&threads[i][j], NULL, matrix_multiply, &arguments[i][j]);
        }
    }

    // Wait for all threads to finish
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            pthread_join(threads[i][j], NULL);
        }
    }

    // Print the resulting matrix
    printf("Matrix 1:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    printf("\nResult:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}