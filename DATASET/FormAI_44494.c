//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Sherlock Holmes
// The Adventure of the Threading Library Implementation
// by Sherlock Holmes

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_hello(void* thread_id) {
    long id = (long) thread_id;
    printf("Hello from thread %ld\n", id);
    pthread_exit(NULL);
}

int main() {
    int num_threads = 5;
    pthread_t threads[num_threads];
    int rc;
    long t;

    printf("Starting threads...\n");

    for (t = 0; t < num_threads; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, print_hello, (void*)t);
        if (rc) {
            printf("Error creating thread %d\n", rc);
            exit(-1);
        }
    }

    printf("All threads started.\n");

    pthread_exit(NULL);
}