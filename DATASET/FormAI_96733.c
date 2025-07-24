//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREADS 5

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    printf("Hello, I'm thread %d\n", thread_id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[N_THREADS];
    int thread_ids[N_THREADS];
    int i;

    for (i = 0; i < N_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_func, &thread_ids[i])) {
            fprintf(stderr, "Error creating thread\n");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < N_THREADS; i++) {
        if (pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread\n");
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads finished successfully!\n");

    return 0;
}