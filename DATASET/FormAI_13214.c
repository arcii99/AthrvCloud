//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// define constants
#define NUM_THREADS 4
#define MAX_ITERATIONS 1000000

// function declarations
void *print_hello(void *num);
void *print_world(void *num);

int main(int argc, char *argv[]) {
    // declare variables
    pthread_t threads[NUM_THREADS];
    int rc, t;

    // create threads
    for (t = 0; t < NUM_THREADS; t++) {
        if (t % 2 == 0) {
            rc = pthread_create(&threads[t], NULL, print_hello, (void *)&t);
        } else {
            rc = pthread_create(&threads[t], NULL, print_world, (void *)&t);
        }

        if (rc) {
            fprintf(stderr, "Error: unable to create thread, rc=%d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    // wait for threads to complete
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("Finished executing threads!\n");
    return 0;
}

void *print_hello(void *num) {
    int i;
    int *thread_num = (int *)num;

    for (i = 0; i < MAX_ITERATIONS; i++) {
        printf("Hello from thread %d\n", *thread_num);
    }

    pthread_exit(NULL);
}

void *print_world(void *num) {
    int i;
    int *thread_num = (int *)num;

    for (i = 0; i < MAX_ITERATIONS; i++) {
        printf("World from thread %d\n", *thread_num);
    }

    pthread_exit(NULL);
}