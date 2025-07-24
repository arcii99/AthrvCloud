//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: active
#include <stdio.h>
#include <pthread.h>

#define MAX_THREADS 5

void *threadFunction(void *arg)
{
    int threadNum = *(int *)arg;
    printf("Hello from thread %d\n", threadNum);
    return NULL;
}

int main()
{
    pthread_t threads[MAX_THREADS];
    int i, args[MAX_THREADS];

    for (i = 0; i < MAX_THREADS; i++) {
        args[i] = i;
        pthread_create(&threads[i], NULL, threadFunction, &args[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed\n");

    return 0;
}