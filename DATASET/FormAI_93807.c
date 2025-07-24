//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: genious
/*
 * This program is a performance-critical component of a complex system.
 * It updates a numerical matrix in a way that involves significant computation.
 * To achieve maximum performance, it leverages multithreading and SIMD instructions.
 * 
 * Developed by [YOUR NAME]
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <emmintrin.h>
#include <pthread.h>

#define MATRIX_SIZE 1000
#define THREAD_COUNT 4

typedef struct {
    int start;
    int end;
} MatrixBlock;

typedef struct {
    float matrix[MATRIX_SIZE][MATRIX_SIZE];
    MatrixBlock block;
} ThreadData;

void* updateMatrix(void* arg);

int main() {
    ThreadData data[THREAD_COUNT];
    pthread_t threads[THREAD_COUNT];
    int i;
    
    // Initialize matrix
    for (i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++) {
        data[0].matrix[i / MATRIX_SIZE][i % MATRIX_SIZE] = ((float) rand()) / RAND_MAX;
    }

    // Divide matrix into equal blocks
    int blockSize = MATRIX_SIZE / THREAD_COUNT;
    for (i = 0; i < THREAD_COUNT; i++) {
        data[i].block.start = i * blockSize;
        data[i].block.end = (i + 1) * blockSize;
    }
    data[THREAD_COUNT - 1].block.end = MATRIX_SIZE;

    // Start threads to update matrix
    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_create(&threads[i], NULL, updateMatrix, &data[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < THREAD_COUNT; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void* updateMatrix(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    MatrixBlock block = data->block;

    int i, j;
    __m128 row1, row2, row3, row4, row5;
    __m128 mult1, mult2, mult3, mult4, mult5, result1, result2, result3, result4, result5;

    for (i = block.start; i < block.end; i += 5) {
        for (j = 0; j < MATRIX_SIZE; j += 4) {
            // Load rows into vectors
            row1 = _mm_loadu_ps(&data->matrix[i][j]);
            row2 = _mm_loadu_ps(&data->matrix[i + 1][j]);
            row3 = _mm_loadu_ps(&data->matrix[i + 2][j]);
            row4 = _mm_loadu_ps(&data->matrix[i + 3][j]);
            row5 = _mm_loadu_ps(&data->matrix[i + 4][j]);

            // Multiply rows by constants
            mult1 = _mm_mul_ps(row1, _mm_set1_ps(0.5));
            mult2 = _mm_mul_ps(row2, _mm_set1_ps(0.5));
            mult3 = _mm_mul_ps(row3, _mm_set1_ps(0.5));
            mult4 = _mm_mul_ps(row4, _mm_set1_ps(0.5));
            mult5 = _mm_mul_ps(row5, _mm_set1_ps(0.5));

            // Combine results and store in destination rows
            result1 = _mm_add_ps(mult1, mult2);
            _mm_storeu_ps(&data->matrix[i][j], result1);

            result2 = _mm_add_ps(mult3, mult4);
            _mm_storeu_ps(&data->matrix[i + 2][j], result2);

            result3 = _mm_add_ps(result1, result2);
            result3 = _mm_add_ps(result3, mult5);
            _mm_storeu_ps(&data->matrix[i + 4][j], result3);
        }
    }

    pthread_exit(NULL);
}