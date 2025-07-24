//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREADS 5

void *print_message(void *message)
{
    printf("%s\n", (char*) message);
    pthread_exit(NULL);
}

int main()
{
    int i;
    char *messages[THREADS] = {"Hello World!", "This is a multithreaded program.", "Concurrency is awesome!", "Threads are faster than processes.", "C threading library is easy."};
    pthread_t threads[THREADS];

    for (i = 0; i < THREADS; i++)
    {
        printf("Creating thread %d\n", i);
        pthread_create(&threads[i], NULL, print_message, (void*) messages[i]);
    }

    for (i = 0; i < THREADS; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Thread %d has completed.\n", i);
    }

    pthread_exit(NULL);
}