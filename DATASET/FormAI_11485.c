//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NTHREADS 5

int sum = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_function(void *arg)
{
    int *thread_arg = (int *) arg;
    int i;
    for(i = 0; i < *thread_arg; i++) {
        pthread_mutex_lock(&mutex);
        sum += 1;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NTHREADS];
    int thread_args[NTHREADS];
    int i;
    for(i = 0; i < NTHREADS; i++) {
        thread_args[i] = i + 1;
        if(pthread_create(&threads[i], NULL, thread_function, &thread_args[i]) != 0) {
            printf("Error creating thread %d\n", i);
            exit(1);
        }
    }
    for(i = 0; i < NTHREADS; i++) {
        if(pthread_join(threads[i], NULL) != 0) {
            printf("Error joining thread %d\n", i);
            exit(1);
        }
    }
    printf("The sum of the first %d natural numbers is %d.\n", NTHREADS, sum);
    return 0;
}