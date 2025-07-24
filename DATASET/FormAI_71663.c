//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_work(void *thread_id) {
    long tid = (long) thread_id;
    int sum = 0;
    
    for(int i=0; i<tid+1; i++) {
        sum += i;
    }
    
    printf("Thread %ld: Sum of numbers 1 to %ld is %d\n", tid, tid+1, sum);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    for(t=0; t<NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, thread_work, (void *) t);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    pthread_exit(NULL);
}