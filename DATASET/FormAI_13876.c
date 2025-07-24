//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define MAX_THREADS 10

void *thread_function(void *args) {
    int thread_id = *(int *)args;
    printf("Thread %d: Hello World!\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    printf("We're about to start an insane thread party!\n");
    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i;
        int result = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
        if (result != 0) {
            printf("Error: Failed to create thread number %d! The entire party is ruined!\n", i);
            exit(-1);
        }
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        int result = pthread_join(threads[i], NULL);
        if (result != 0) {
            printf("Error: Failed to join thread number %d! The entire party is ruined!\n", i);
            exit(-1);
        }
    }

    printf("Thanks for partying with us! See you next thread time!\n");
    pthread_exit(NULL);
}