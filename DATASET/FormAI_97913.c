//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Sherlock Holmes
//The following code snippet is a sample implementation of a threading library developed by Sherlock Holmes to solve cases faster.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4

pthread_mutex_t mutex;
int counter = 0;

void *thread_function(void *arg) {
    pthread_mutex_lock(&mutex);
    counter++;
    printf("Thread %d started. Current count is %d.\n", (int)arg, counter);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t thread[MAX_THREADS];
    int i;

    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    for (i = 0; i < MAX_THREADS; i++) {
        if (pthread_create(&thread[i], NULL, thread_function, (void *)i) != 0) {
            printf("Thread creation failed.\n");
            return 1;
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(thread[i], NULL) != 0) {
            printf("Thread join failed.\n");
            return 1;
        }
    }

    printf("All threads have terminated and the final count is %d.\n", counter);

    if (pthread_mutex_destroy(&mutex) != 0) {
        printf("Mutex destruction failed.\n");
        return 1;
    }

    return 0;
}