//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 3

// thread function
void *thread_function(void *arg) {
    int id = *(int*)arg;
    printf("Thread %d started...\n", id);
    for (int i = 0; i < 5; ++i) {
        printf("Thread %d is working...\n", id);
        sleep(1);
    }
    printf("Thread %d finished!\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREADS];
    int ids[THREADS];

    printf("Creating %d threads...\n\n", THREADS);

    // create threads
    for (int i = 0; i < THREADS; ++i) {
        ids[i] = i + 1;
        if (pthread_create(&threads[i], NULL, thread_function, &ids[i])) {
            printf("Error creating thread %d!\n", i+1);
            exit(EXIT_FAILURE);
        }
    }

    printf("\nAll threads created successfully!\n\n");

    // wait for threads to finish
    for (int i = 0; i < THREADS; ++i) {
        if (pthread_join(threads[i], NULL)) {
            printf("Error joining thread %d!\n", i+1);
            exit(EXIT_FAILURE);
        }
    }

    printf("\nAll threads finished successfully!\n");

    return 0;
}