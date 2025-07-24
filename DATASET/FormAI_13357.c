//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void *factorial(void *arg) {
    int *n = (int *) arg;
    int result = 1;
    
    for (int i = 1; i <= *n; i++) {
        result *= i;
    }
    
    pthread_exit((void *) result);
}

int main() {
    int numbers[NUM_THREADS] = {3, 5, 2, 6, 8, 1, 9, 4, 7, 10};
    int factorial_results[NUM_THREADS];
    pthread_t threads[NUM_THREADS];
    
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, factorial, (void *) &numbers[i])) {
            fprintf(stderr, "Error creating thread\n");
            exit(-1);
        }
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], (void **) &factorial_results[i])) {
            fprintf(stderr, "Error joining thread\n");
            exit(-1);
        }
    }
    
    printf("Factorial results:\n");
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("%d! = %d\n", numbers[i], factorial_results[i]);
    }
    
    pthread_exit(NULL);
}