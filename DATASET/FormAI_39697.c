//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *args){
    int thread_num = *((int *) args);
    printf("Thread number %d is running!\n", thread_num);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int i, rc;

    for(i=0; i<NUM_THREADS; i++){
        printf("Creating thread number %d...\n", i);

        thread_args[i] = i;
        rc = pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);

        if(rc){
            printf("ERROR: Return code from pthread_create is %d.\n", rc);
            exit(-1);
        }
    }

    printf("All %d threads are created successfully!\n", NUM_THREADS);

    pthread_exit(NULL);
}