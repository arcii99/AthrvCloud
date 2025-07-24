//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: satisfied
#include <stdio.h>
#include <pthread.h>

#define THREAD_COUNT 5

void *threadFunction(void *threadID) {
    long tid = (long) threadID;
    printf("Thread %ld is running\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[THREAD_COUNT];
    int result;
    long i;

    for (i = 0; i < THREAD_COUNT; i++) {
        printf("Creating thread %ld\n", i);
        result = pthread_create(&threads[i], NULL, threadFunction, (void *)i);
        if (result != 0) {
            printf("Thread creation failed\n");
            return 1;
        }
    }

    for (i = 0; i < THREAD_COUNT; i++) {
        printf("Joining thread %ld\n", i);
        result = pthread_join(threads[i], NULL);
        if (result != 0) {
            printf("Thread join failed\n");
            return 1;
        } else {
            printf("Thread %ld has joined\n", i);
        }
    }

    return 0;
}