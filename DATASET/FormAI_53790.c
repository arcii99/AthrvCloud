//FormAI DATASET v1.0 Category: Recursive ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

// Recursive function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

// Thread function to calculate the factorial of a number
void* thread_factorial(void* arg) {
    int n = *((int*) arg);
    int fact = factorial(n);
    printf("Factorial of %d = %d\n", n, fact);
    pthread_exit(NULL);
}

int main() {
    int numbers[] = {5, 7, 3, 9, 2};
    pthread_t threads[5];

    // Create and run threads to calculate factorial of each number
    for (int i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, thread_factorial, (void*) &numbers[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}