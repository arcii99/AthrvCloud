//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: authentic
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *print_thread_id(void *thread_id);

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, t;
    
    for(t=0; t<NUM_THREADS; t++) {
        printf("Creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, print_thread_id, (void *)t);
        
        if(rc) {
            printf("Error creating thread %d\n", rc);
            exit(-1);
        }
    }
    
    pthread_exit(NULL);
    return 0;
}

void *print_thread_id(void *thread_id) {
    int tid = (int)thread_id;
    printf("Thread ID: %d\n", tid);
    
    pthread_exit(NULL);
}