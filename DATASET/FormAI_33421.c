//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

int counter = 0;
pthread_mutex_t lock;

void *thread_function(void *arg)
{
    int i;
    pthread_mutex_lock(&lock);
    counter++;
    printf("Thread %ld starting, counter = %d\n", (long)arg, counter);
    sleep(1);
    printf("Thread %ld finishing, counter = %d\n", (long)arg, counter);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    pthread_mutex_init(&lock, NULL);
    
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, thread_function, (void *)t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    
    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);
}