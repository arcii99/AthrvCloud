//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

void *thread_func(void *arg);

int main()
{
    pthread_t tid[MAX_THREADS];
    int i, thread_num[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        thread_num[i] = i;
        if (pthread_create(&tid[i], NULL, thread_func, &thread_num[i]) != 0) {
            printf("Failed to create thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        if (pthread_join(tid[i], NULL) != 0) {
            printf("Failed to join thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads terminated successfully.\n");

    return EXIT_SUCCESS;
}

void *thread_func(void *arg)
{
    int i, thread_num = *(int *) arg;

    for (i = 0; i < 10; i++) {
        printf("Thread %d: iteration %d\n", thread_num, i);
    }

    pthread_exit(NULL);
}