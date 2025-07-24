//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

void* print_hello(void* thread_id) {
    int tid = (int) thread_id;
    printf("Hello from thread %d!\n", tid);
    pthread_exit(NULL);
}

void create_threads(int num_threads) {
    pthread_t threads[num_threads];
    int rc, t;

    for (t = 0; t < num_threads; t++) {
        printf("Creating thread %d...\n", t);
        rc = pthread_create(&threads[t], NULL, print_hello, (void*) t);
        if (rc) {
            printf("Error creating thread: %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
}

int main() {
    int num_threads;

    printf("Welcome to the Threading Library Implementation Example Program! \n");
    printf("How many threads would you like to create (up to %d)? ", MAX_THREADS);
    scanf("%d", &num_threads);

    if (num_threads > MAX_THREADS) {
        printf("Sorry, the number of threads exceeded the maximum limit of %d.\n", MAX_THREADS);
        printf("Please re-run the program and try again.\n");
        exit(-1);
    }

    create_threads(num_threads);

    return 0;
}