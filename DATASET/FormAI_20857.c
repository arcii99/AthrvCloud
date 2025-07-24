//FormAI DATASET v1.0 Category: Data validation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function to check if a number is prime
int isPrime(int num) {
    int i;
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to be called by the threads
void *validateData(void *arg) {
    int *arr = (int *)arg;
    int num = arr[0];
    int max = arr[1];
    int count = 0;

    // Check if all numbers in the range are prime
    for (int i = num; i < max; i++) {
        if (isPrime(i)) {
            count++;
        }
    }

    // Check if at least half of the numbers are prime
    if (count >= (max - num) / 2) {
        printf("%d to %d: Valid\n", num, max);
    } else {
        printf("%d to %d: Invalid\n", num, max);
    }

    pthread_exit(NULL);
}

int main() {
    int numRanges = 3;
    int ranges[][2] = {{1, 10}, {100, 110}, {1000, 1010}};

    pthread_t threads[numRanges];

    // Start threads for data validation
    for (int i = 0; i < numRanges; i++) {
        if (pthread_create(&threads[i], NULL, validateData, (void *)ranges[i]) != 0) {
            printf("Error creating Thread %d!\n", i+1);
            exit(1);
        }
    }

    // Wait for each thread to finish
    for (int i = 0; i < numRanges; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}