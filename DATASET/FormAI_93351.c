//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 10

void *thread_func(void *arg){
    printf("Thread %d started.\n", *(int *)arg);
    // Do some processing
    printf("Thread %d finished.\n", *(int *)arg);
    return NULL;
}

int main(){
    pthread_t threads[THREAD_COUNT];
    int thread_args[THREAD_COUNT];
    int i, rc;

    // Create threads
    for (i = 0; i < THREAD_COUNT; i++){
        thread_args[i] = i;
        rc = pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);
        if(rc){
            printf("Error creating thread %d.\n", i);
            exit(1);
        }
    }

    // Wait for all threads to complete
    for (i = 0; i < THREAD_COUNT; i++){
        rc = pthread_join(threads[i], NULL);
        if(rc){
            printf("Error joining thread %d.\n", i);
            exit(1);
        }
    }

    printf("All threads completed successfully.\n");

    return 0;
}