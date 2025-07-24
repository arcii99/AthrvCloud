//FormAI DATASET v1.0 Category: System administration ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count = 0;

void* thread_function(void* arg)
{
    int i;
    printf("Thread %d: starting\n", *((int*) arg));
    for (i = 0; i < 5; i++) {
        count++;
        printf("Thread %d: count = %d\n", *((int*) arg), count);
    }
    printf("Thread %d: ending\n", *((int*) arg));
    free(arg);
    pthread_exit(NULL);
}

int main()
{
    int i, error;
    pthread_t thread_id[3];

    for (i = 0; i < 3; i++) {
        int* thread_number = malloc(sizeof(int));
        *thread_number = i;
        error = pthread_create(&(thread_id[i]), NULL, &thread_function, thread_number);
        if (error != 0) {
            printf("Thread %d: Error in creating thread\n", i);
        }
    }

    for (i = 0; i < 3; i++) {
        error = pthread_join(thread_id[i], NULL);
        if (error != 0) {
            printf("Thread %d: Error in joining thread\n", i);
        }
    }

    printf("Main thread: count = %d\n", count);

    pthread_exit(NULL);
}