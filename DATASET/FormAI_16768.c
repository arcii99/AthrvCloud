//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

void *thread_message(void *p_id)
{
    int id = *((int *)p_id);
    printf("Thread %d says: Hello, world!\n", id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS];

    printf("Welcome to the Thread Puzzler!\n");

    for(int i = 0; i < MAX_THREADS; i++)
    {
        ids[i] = i;
        pthread_create(&threads[i], NULL, thread_message, (void *)&ids[i]);
        printf("Thread %d created!\n", i);
    }

    for(int i = 0; i < MAX_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Thread %d joined!\n", i);
    }

    printf("All threads have completed. Thanks for playing the Thread Puzzler!\n");

    return 0;
}