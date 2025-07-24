//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads
#define THREADS 10

// Define a struct to hold the variables
typedef struct {
    int a;
    int b;
    int c;
} Variables;

// Define the thread function
void *thread_func(void *args) {
    Variables *var = (Variables *) args;

    printf("Thread %ld started...\n", pthread_self());
    printf("Variables: a=%d, b=%d, c=%d\n", var->a, var->b, var->c);

    // Do some computation
    int result = var->a * var->b + var->c;

    printf("Result: %d\n", result);
    printf("Thread %ld finished.\n", pthread_self());
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS];

    // Declare an array of variables
    Variables vars[THREADS];

    // Initialize the variables and create the threads
    for (int i = 0; i < THREADS; i++) {
        vars[i].a = i + 1;
        vars[i].b = i + 2;
        vars[i].c = i + 3;

        if (pthread_create(&threads[i], NULL, thread_func, &vars[i])) {
            fprintf(stderr, "Error creating thread %d.\n", i);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}