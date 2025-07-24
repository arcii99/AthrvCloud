//FormAI DATASET v1.0 Category: Benchmarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 1000 // Size of matrices
#define THREADS 10 // Number of threads to be created

int matA[SIZE][SIZE]; // Global variables for matrices and sum matrix
int matB[SIZE][SIZE];
int sum[SIZE][SIZE];

void *add(void* arg) { // Function to add parts of matrices
    int start = *(int*)arg, end = start + SIZE/THREADS;
    for(int i=start; i<end; i++) {
        for(int j=0; j<SIZE; j++) {
            sum[i][j] = matA[i][j] + matB[i][j];
        }
    }
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL)); // Initialize random number generator

    // Initialize matrices with random numbers
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            matA[i][j] = rand() % 100;
            matB[i][j] = rand() % 100;
        }
    }

    pthread_t threads[THREADS]; // Array to hold thread IDs
    int threadArgs[THREADS]; // Array to hold thread arguments

    // Create threads and assign tasks
    for(int i=0; i<THREADS; i++) {
        threadArgs[i] = i * SIZE/THREADS;
        pthread_create(&threads[i], NULL, add, &threadArgs[i]);
    }

    // Wait for all threads to finish
    for(int i=0; i<THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print sum matrix
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}