//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/* Function to check if a number is prime */
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

/* Function to generate a random number between min and max */
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Main function */
int main() {
    int num, count = 0;
    clock_t t;
    double time_taken;
    
    // Start timer
    t = clock();

    // Generate 100 random numbers between 1000 and 10000
    for (int i = 0; i < 100; i++) {
        num = getRandomNumber(1000, 10000);
        if (isPrime(num)) {
            count++;
        }
    }

    // Stop timer and calculate time taken
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;

    printf("Out of 100 random numbers, %d are prime.\n", count);
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}