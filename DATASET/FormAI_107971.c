//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_COUNT 100

int count = 0;
pthread_mutex_t mutex_count;

void *increment_count(void *thread_id) {
    long tid;
    tid = (long) thread_id;
    printf("Thread %ld starting...\n", tid);
    
    while (1) {
        pthread_mutex_lock(&mutex_count);
        if (count == MAX_COUNT) {
            pthread_mutex_unlock(&mutex_count);
            break;
        }
        count++;
        printf("Thread %ld incremented count to %d\n", tid, count);
        pthread_mutex_unlock(&mutex_count);
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    pthread_mutex_init(&mutex_count, NULL);
    
    for (t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, increment_count, (void *)t);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    
    pthread_mutex_destroy(&mutex_count);
    
    printf("Final count is: %d\n", count);
    
    pthread_exit(NULL);
}