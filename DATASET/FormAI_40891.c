//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: distributed
/**
 * A distributed style program to perform matrix multiplication
 * with multiple threads for improved performance.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MATRIX_SIZE 1000

int matrix1[MATRIX_SIZE][MATRIX_SIZE];
int matrix2[MATRIX_SIZE][MATRIX_SIZE];
int result[MATRIX_SIZE][MATRIX_SIZE];

// Thread data structure
typedef struct {
    int start_row;
    int end_row;
} thread_data;

// Thread function to perform matrix multiplication
void *matrix_mult(void *arg) {
    thread_data *td = (thread_data*) arg;
    
    // Perform matrix multiplication in the given rows
    for(int i = td->start_row; i < td->end_row; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            result[i][j] = 0;
            for(int k = 0; k < MATRIX_SIZE; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    
    pthread_exit(NULL);
}

int main() {
    // Initialize matrices with random values
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            matrix1[i][j] = rand() % 10;
            matrix2[i][j] = rand() % 10;
        }
    }
    
    // Create threads
    int num_threads = 8;
    pthread_t threads[num_threads];
    thread_data td[num_threads];
    
    int rows_per_thread = MATRIX_SIZE / num_threads;
    for(int i = 0; i < num_threads; i++) {
        td[i].start_row = i * rows_per_thread;
        td[i].end_row = (i+1) * rows_per_thread;
        if(i == (num_threads - 1)) {
            td[i].end_row = MATRIX_SIZE; // Last thread processes remaining rows
        }
        pthread_create(&threads[i], NULL, matrix_mult, &td[i]);
    }
    
    // Wait for threads to finish
    for(int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print results
    for(int i = 0; i < MATRIX_SIZE; i++) {
        for(int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}