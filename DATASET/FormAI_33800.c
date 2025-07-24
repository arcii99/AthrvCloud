//FormAI DATASET v1.0 Category: Random ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define THREADS 5       // Number of threads
#define MAX_RAND 100    // Maximum random number to generate

// Global variable to track if a random number has been found
bool isFound = false;

// Function to generate random numbers
int generateRand() {
    return rand() % MAX_RAND + 1;
}

// Function to be executed by threads
void *searchRand(void *arg) {
    pthread_t selfThread = pthread_self();
    int threadNum = *(int*)arg;

    while (!isFound) {
        int num = generateRand();
        printf("Thread %d generated random number: %d\n", threadNum, num);

        // Check if the generated number is a multiple of 7
        if (num % 7 == 0) {
            printf("Thread %d found a multiple of 7: %d\n", threadNum, num);
            isFound = true;
        } else {
            printf("Thread %d didn't find a multiple of 7.\n", threadNum);
        }
    }

    printf("Thread %d is exiting.\n", threadNum);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS];
    int threadArgs[THREADS];

    // Initialize thread arguments with their corresponding numbers
    for (int i = 0; i < THREADS; i++) {
        threadArgs[i] = i + 1;
    }

    // Create threads
    for (int i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, searchRand, (void*)&threadArgs[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished.\n");

    return 0;
}