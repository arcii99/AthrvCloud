//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: rigorous
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *print_hello(void *thread_id) {
    long id = (long)thread_id;
    printf("Hello from thread %ld!\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ret, i;

    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread %d\n", i);
        ret = pthread_create(&threads[i], NULL, print_hello, (void *)i);
        if (ret) {
            printf("Error creating thread %d, return code: %d\n", i, ret);
            exit(-1);
        }
    }

    printf("Main thread is waiting for all threads to complete..\n");
    for (i = 0; i < NUM_THREADS; i++) {
        ret = pthread_join(threads[i], NULL);
        if (ret) {
            printf("Error joining thread %d, return code: %d\n", i, ret);
            exit(-1);
        }
        printf("Thread %d completed\n", i);
    }

    printf("All threads completed, exiting..\n");

    pthread_exit(NULL);
    return 0;
}