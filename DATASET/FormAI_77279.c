//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void *myThreadFun(void *vargp)
{
    int *myid = (int *)vargp;
    printf("Thread ID %d\n", *myid);
    return NULL;
}

int main()
{
    int i;
    pthread_t tid[NUM_THREADS];

    for (i = 0; i < NUM_THREADS; i++)
    {
        int *arg = malloc(sizeof(*arg));
        *arg = i;
        pthread_create(&tid[i], NULL, myThreadFun, arg);
    }

    for (i = 0; i < NUM_THREADS; i++)
        pthread_join(tid[i], NULL);

    return 0;
}