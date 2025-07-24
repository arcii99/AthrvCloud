//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4
#define SIZE 1000

// Cyberpunk-style color codes
#define CYAN "\033[0;36m"
#define MAGENTA "\033[0;35m"
#define RED "\033[0;31m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

int matrixA[SIZE][SIZE], matrixB[SIZE][SIZE], resultMatrix[SIZE][SIZE];

// Function declarations
void *matrixMultiplication(void *arg);

int main()
{
    srand(time(NULL));

    // Initialize matrices with random values
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            matrixA[i][j] = rand() % 10;
            matrixB[i][j] = rand() % 10;
        }
    }

    printf(CYAN "\nWelcome to the Cyber Matrix Multiplication!\n\n" RESET);

    // Display matrix A
    printf(YELLOW "Matrix A:\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", matrixA[i][j]);
        }
        printf("\n");
    }

    // Display matrix B
    printf("\n" MAGENTA "Matrix B:\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", matrixB[i][j]);
        }
        printf("\n");
    }

    // Create threads
    pthread_t threads[NUM_THREADS];

    int threadArgs[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++) {
        threadArgs[i] = i;
        pthread_create(&threads[i], NULL, matrixMultiplication, &threadArgs[i]);
    }

    // Wait for threads to finish
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display result matrix
    printf("\n" RED "Result Matrix:\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    printf(RESET "\nThank you for using Cyber Matrix Multiplication!\n");

    return 0;
}

void *matrixMultiplication(void *arg) {
    int threadId = *(int*) arg;

    // Determine the start and end indices for this thread
    int startRow = (SIZE / NUM_THREADS) * threadId;
    int endRow = (SIZE / NUM_THREADS) * (threadId + 1);

    // Multiply matrix A and matrix B for the assigned rows
    for(int i = startRow; i < endRow; i++) {
        for(int j = 0; j < SIZE; j++) {
            int sum = 0;

            for(int k = 0; k < SIZE; k++) {
                sum += matrixA[i][k] * matrixB[k][j];
            }

            resultMatrix[i][j] = sum;
        }
    }

    pthread_exit(NULL);
}