//FormAI DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MATRIX_SIZE 5

int matrix_a[MATRIX_SIZE][MATRIX_SIZE];
int matrix_b[MATRIX_SIZE][MATRIX_SIZE];
int result_matrix[MATRIX_SIZE][MATRIX_SIZE];

// Function to fill the matrices with random values
void fillMatrices() {
    srand(time(NULL));
    for(int i=0; i<MATRIX_SIZE; i++) {
        for(int j=0; j<MATRIX_SIZE; j++) {
            matrix_a[i][j] = rand()%10;
            matrix_b[i][j] = rand()%10;
        }
    }
}

// Function to multiply the matrices using asynchronous programming
void* multiplyMatrices(void* arg) {
    int row = *(int*)arg;
    for(int i=0; i<MATRIX_SIZE; i++) {
        int sum = 0;
        for(int j=0; j<MATRIX_SIZE; j++) {
            sum += matrix_a[row][j] * matrix_b[j][i];
        }
        result_matrix[row][i] = sum;
    }
    pthread_exit(0);
}

int main() {
    fillMatrices();
    printf("Matrix A:\n");
    for(int i=0; i<MATRIX_SIZE; i++) {
        for(int j=0; j<MATRIX_SIZE; j++) {
            printf("%d ", matrix_a[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix B:\n");
    for(int i=0; i<MATRIX_SIZE; i++) {
        for(int j=0; j<MATRIX_SIZE; j++) {
            printf("%d ", matrix_b[i][j]);
        }
        printf("\n");
    }
    printf("\nCalculating matrix multiplication asynchronously...\n");

    // Creating threads for asynchronous programming
    pthread_t tid[MATRIX_SIZE];
    int row_numbers[MATRIX_SIZE];
    for(int i=0; i<MATRIX_SIZE; i++) {
        row_numbers[i] = i;
        pthread_create(&tid[i], NULL, multiplyMatrices, &row_numbers[i]);
    }

    // Joining threads to wait for the matrix multiplication to complete
    for(int i=0; i<MATRIX_SIZE; i++) {
        pthread_join(tid[i], NULL);
    }

    printf("\nResultant Matrix:\n");
    for(int i=0; i<MATRIX_SIZE; i++) {
        for(int j=0; j<MATRIX_SIZE; j++) {
            printf("%d ", result_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}