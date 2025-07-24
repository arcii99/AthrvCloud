//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count = 0; // global variable to be manipulated by threads
pthread_mutex_t lock; // mutex lock to prevent race conditions

/* thread function that increments count */
void *thread_func(void *arg)
{
    int i;
    for (i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock); // acquire lock before manipulating shared variable
        count++;
        pthread_mutex_unlock(&lock); // release lock after manipulation
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[4]; // array of thread IDs
    int i;

    if (pthread_mutex_init(&lock, NULL) != 0) { // initialize mutex lock
        printf("Mutex init failed\n");
        return 1;
    }

    // create four threads
    for (i = 0; i < 4; i++) {
        if (pthread_create(&threads[i], NULL, thread_func, NULL) != 0) {
            printf("Thread creation failed\n");
            return 1;
        }
    }

    // join threads
    for (i = 0; i < 4; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("Thread join failed\n");
            return 1;
        }
    }

    printf("Count value is %d\n", count);

    pthread_mutex_destroy(&lock); // destroy mutex lock

    return 0;
}