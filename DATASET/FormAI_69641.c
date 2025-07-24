//FormAI DATASET v1.0 Category: Matrix operations ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MATRIX_SIZE 100

int matrix[MATRIX_SIZE][MATRIX_SIZE];
int result[MATRIX_SIZE][MATRIX_SIZE];

void *multiply_row(void *arg) {
    int row = *(int*)arg;
    for (int i=0; i<MATRIX_SIZE; i++) {
        int sum = 0;
        for (int j=0; j<MATRIX_SIZE; j++) {
            sum += matrix[row][j] * matrix[j][i];
        }
        result[row][i] = sum;
    }
    return NULL;
}

int main() {
    // fill the matrix with random values
    for (int i=0; i<MATRIX_SIZE; i++) {
        for (int j=0; j<MATRIX_SIZE; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    // create threads for each row
    pthread_t threads[MATRIX_SIZE];
    for (int i=0; i<MATRIX_SIZE; i++) {
        pthread_create(&threads[i], NULL, &multiply_row, &i);
    }

    // wait for all threads to finish
    for (int i=0; i<MATRIX_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    // print the result
    for (int i=0; i<MATRIX_SIZE; i++) {
        for (int j=0; j<MATRIX_SIZE; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}