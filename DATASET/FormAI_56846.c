//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_function(void *arg);

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

int main()
{
    pthread_t threads[NUM_THREADS];
    int i;

    for(i=0; i<NUM_THREADS; i++){
        pthread_create(&threads[i], NULL, thread_function, NULL);
    }

    for(i=0; i<NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
    }

    printf("Final counter: %d\n", counter);

    return 0;
}

void *thread_function(void *arg)
{
    pthread_mutex_lock(&mutex1);
    printf("Thread number %ld\n", pthread_self());
    counter++;
    pthread_mutex_unlock(&mutex1);
    return NULL;
}