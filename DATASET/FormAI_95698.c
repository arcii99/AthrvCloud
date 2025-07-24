//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

int count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *argument)
{
    int i;
    pthread_mutex_lock(&mutex);
    printf("Thread %ld started.\n", (long)argument);
    for (i = 0; i < 10; i++) {
        count++;
        printf("Thread %ld: Count is %d\n", (long)argument, count);
    }
    printf("Thread %ld finished.\n", (long)argument);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int error_code, i;

    printf("Creating threads...\n");
    for (i = 0; i < NUM_THREADS; i++) {
        error_code = pthread_create(&threads[i], NULL, thread_function, (void *)i);
        if (error_code) {
            printf("Thread creation failed: %d\n", error_code);
            exit(EXIT_FAILURE);
        }
    }

    printf("Waiting for threads to finish...\n");
    for (i = 0; i < NUM_THREADS; i++) {
        error_code = pthread_join(threads[i], NULL);
        if (error_code) {
            printf("Thread join failed: %d\n", error_code);
            exit(EXIT_FAILURE);
        }
    }

    printf("Result: Count is %d\n", count);

    pthread_exit(NULL);
}