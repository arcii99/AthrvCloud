//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_print(void *thread_id) {
    long id = (long) thread_id;
    printf("Hello from thread #%ld\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // create threads
    for(t=0; t<NUM_THREADS; t++){
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, thread_print, (void *)t);
        if (rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // wait for threads to finish
    for(t=0; t<NUM_THREADS; t++){
        pthread_join(threads[t], NULL);
    }

    printf("All threads completed. Exiting program.\n");

    pthread_exit(NULL);
}