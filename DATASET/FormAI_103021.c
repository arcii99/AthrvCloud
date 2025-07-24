//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_mutex_t mutex;
int count = 0;

void *thread_function(void *arg) {
    int i;
    pthread_mutex_lock(&mutex);
    printf("Thread %d starting\n", *(int *)arg);
    for (i = 0; i < 5; i++) {
        printf("Thread %d count %d\n", *(int *)arg, count++);
        sleep(1);
    }
    printf("Thread %d ending\n", *(int *)arg);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    int i;
    pthread_t tids[NUM_THREADS];
    int thread_args[NUM_THREADS];

    if (pthread_mutex_init(&mutex, NULL) != 0) {
        printf("Mutex initialization failed.\n");
        return 1;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        if (pthread_create(&tids[i], NULL, thread_function, &thread_args[i]) != 0) {
            printf("Thread creation failed.\n");
            return 1;
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(tids[i], NULL) != 0) {
            printf("Thread join failed.\n");
            return 1;
        }
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}