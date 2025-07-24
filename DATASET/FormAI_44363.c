//FormAI DATASET v1.0 Category: Scientific ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

/* Thread functions */
void *thread1_func(void *arg);
void *thread2_func(void *arg);
void *thread3_func(void *arg);

int main()
{
    int i;
    pthread_t threads[NUM_THREADS];

    /* Create threads */
    pthread_create(&threads[0], NULL, thread1_func, NULL);
    pthread_create(&threads[1], NULL, thread2_func, NULL);
    pthread_create(&threads[2], NULL, thread3_func, NULL);

    /* Wait for threads to finish */
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished\n");

    return 0;
}

/* Thread 1 Function */
void *thread1_func(void *arg)
{
    printf("Thread 1 Started\n");

    /* Some Logic Here */

    printf("Thread 1 Finished\n");

    return NULL;
}

/* Thread 2 Function */
void *thread2_func(void *arg)
{
    printf("Thread 2 Started\n");

    /* Some Logic Here */

    printf("Thread 2 Finished\n");

    return NULL;
}

/* Thread 3 Function */
void *thread3_func(void *arg)
{
    printf("Thread 3 Started\n");

    /* Some Logic Here */

    printf("Thread 3 Finished\n");

    return NULL;
}