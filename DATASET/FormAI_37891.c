//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREAD_COUNT 5

void *thread_func(void *arg)
{
    long thread_id = *(long *)arg;
    printf("Thread %ld is busy working...\n", thread_id);
    sleep(2);
    printf("Thread %ld is done working.\n", thread_id);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[THREAD_COUNT];
    long ids[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++) {
        ids[i] = i;
        if (pthread_create(&threads[i], NULL, thread_func, &ids[i])) {
            perror("pthread_create failed!");
            exit(EXIT_FAILURE);
        }
        printf("Thread %ld created.\n", ids[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++) {
        if (pthread_join(threads[i], NULL)) {
            perror("pthread_join failed!");
            exit(EXIT_FAILURE);
        }
        printf("Thread %ld joined.\n", ids[i]);
    }

    printf("All threads completed.\n");

    pthread_exit(NULL);
}