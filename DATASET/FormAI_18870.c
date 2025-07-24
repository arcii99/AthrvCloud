//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 4

// thread function
void *threadFunction(void *arg) {
    // retrieve thread id
    int tid = *(int*)arg;
    // print thread id
    printf("Thread %d is running\n", tid);
    // exit thread
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    // initialize thread attributes
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    // initialize thread id array
    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS];

    // create threads
    for(int i=0; i<MAX_THREADS; i++) {
        ids[i] = i+1;
        if(pthread_create(&threads[i], &attr, threadFunction, (void*)&ids[i]) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // clean up attribute object
    pthread_attr_destroy(&attr);

    // wait for all threads to complete
    for(int i=0; i<MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // exit program
    return 0;
}