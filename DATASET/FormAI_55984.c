//FormAI DATASET v1.0 Category: Scientific ; Style: multi-threaded
/* A multi-threaded C program that calculates the factorial of a number using multiple threads */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_FACT 10

typedef struct {
    int num;
    int result;
} FactArgs;

// Factorial function
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

// Thread function to calculate factorial
void* calculateFactorial(void* args) {
    FactArgs* factArgs = (FactArgs*) args;
    factArgs->result = factorial(factArgs->num);
    pthread_exit(NULL);
}

int main() {
    // Create array of threads
    pthread_t threads[MAX_FACT];
    FactArgs factArgs[MAX_FACT];

    // Create threads to calculate factorial
    for (int i = 0; i < MAX_FACT; i++) {
        factArgs[i].num = i + 1;
        pthread_create(&threads[i], NULL, calculateFactorial, &factArgs[i]);
    }

    // Wait for threads to finish and print results
    for (int i = 0; i < MAX_FACT; i++) {
        pthread_join(threads[i], NULL);
        printf("%d! = %d\n", factArgs[i].num, factArgs[i].result);
    }

    return 0;
}