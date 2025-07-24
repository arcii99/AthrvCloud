//FormAI DATASET v1.0 Category: Math exercise ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 5

typedef struct {
    int a;
    int b;
    int result;
} math_problem;

void *calculate(void *arg) {
    math_problem *problem = (math_problem *) arg;

    // Multiply a and b to get result
    problem->result = problem->a * problem->b;

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    // Initialize array of problems
    math_problem problems[MAX_THREADS];

    // Create array of threads
    pthread_t threads[MAX_THREADS];

    // Create and execute async tasks
    for (int i = 0; i < MAX_THREADS; i++) {
        // Generate random numbers for the problem
        int a = rand() % 10 + 1;
        int b = rand() % 10 + 1;

        // Assign the problem to the array
        problems[i].a = a;
        problems[i].b = b;

        // Create the async task
        int error = pthread_create(&threads[i], NULL, calculate, &problems[i]);

        if (error != 0) {
            printf("Error creating thread: %d\n", error);
            return 1;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display the results
    for (int i = 0; i < MAX_THREADS; i++) {
        printf("Problem %d: %d x %d = %d\n", i+1, problems[i].a, problems[i].b, problems[i].result);
    }

    return 0;
}