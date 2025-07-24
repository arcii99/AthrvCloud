//FormAI DATASET v1.0 Category: Matrix operations ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define ROWS 5
#define COLS 5
#define THREADS_COUNT 3

int matrix_a[ROWS][COLS], matrix_b[ROWS][COLS], matrix_c[ROWS][COLS];

void *multiply(void *slice);

int main()
{
    srand(time(NULL));
    
    pthread_t threads[THREADS_COUNT];
    int thread_args[THREADS_COUNT];
    int i, j, k, slice, remainder;
    
    // Initialize matrices A and B with random values
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            matrix_a[i][j] = rand() % 10;
            matrix_b[i][j] = rand() % 10;
        }
    }
    
    // Calculate how many slices will be processed by each thread
    slice = ROWS / THREADS_COUNT;
    remainder = ROWS % THREADS_COUNT;
    
    // Create the threads and start them
    for(i=0; i<THREADS_COUNT; i++)
    {
        thread_args[i] = i * slice;
        if(i == THREADS_COUNT - 1)
            slice += remainder;
        pthread_create(&threads[i], NULL, multiply, (void*) &thread_args[i]);
    }
    
    // Wait for the threads to finish and join them
    for(i=0; i<THREADS_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    // Print matrix A
    printf("Matrix A:\n");
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            printf("%d ", matrix_a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Print matrix B
    printf("Matrix B:\n");
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            printf("%d ", matrix_b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Print matrix C (result)
    printf("Matrix C:\n");
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            printf("%d ", matrix_c[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}

void *multiply(void *slice)
{
    int s = *(int*) slice;
    int i, j, k;
    
    // Perform matrix multiplication for the sliced portion of matrices A and B
    for(i=s; i<s+ROWS/THREADS_COUNT; i++)
    {
        for(j=0; j<COLS; j++)
        {
            for(k=0; k<ROWS; k++)
            {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    
    // Finish the thread
    pthread_exit(0);
}