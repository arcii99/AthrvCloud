//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: Linus Torvalds
/* This program demonstrates an example of a performance-critical component that performs matrix multiplication using multi-threading */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N 1000
#define THREAD_COUNT 10

int matrix_a[N][N];
int matrix_b[N][N];
int matrix_c[N][N];

pthread_t threads[THREAD_COUNT];

void* multiplication(void* arg);

int main() 
{
    // Fill the matrices with random values
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            matrix_a[i][j] = rand() % 10;
            matrix_b[i][j] = rand() % 10;
        }
    }

    // Create the threads
    int thread_args[THREAD_COUNT][2];
    for(int i=0; i<THREAD_COUNT; i++){
        thread_args[i][0] = i*(N/THREAD_COUNT);
        thread_args[i][1] = (i+1)*(N/THREAD_COUNT);
        pthread_create(&threads[i], NULL, multiplication, &thread_args[i]);
    }

    // Wait for all the threads to complete
    for(int i=0; i<THREAD_COUNT; i++){
        pthread_join(threads[i], NULL);
    }

    // Print the result
    printf("Matrix C:\n");
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf("%d ", matrix_c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void* multiplication(void* arg)
{
    int thread_id = (int)pthread_self() % THREAD_COUNT;
    int start = ((int*)arg)[0];
    int end = ((int*)arg)[1];

    // Multiply the matrices using the given range
    for(int i=start; i<end; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    printf("Thread %d completed\n", thread_id);
}