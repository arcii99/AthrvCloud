//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5 // number of threads to be created
#define COUNT_MAX 10 // maximum count value
#define COUNT_MAX_BEFORE_YIELD 7 // value at which threads should yield

pthread_mutex_t lock; // mutex for shared count access
int count = 0; // shared count variable

void *thread_func(void *thread_id) {
    int id = *(int *)thread_id;
    int local_count = 0;
    
    while (local_count < COUNT_MAX) {
        // acquire mutex lock
        pthread_mutex_lock(&lock);
        
        // increment shared count variable
        count++;
        local_count++;
        
        // print thread and current count information
        printf("Thread %d: count is now %d\n", id, count);
        
        // check if threads should yield to allow other threads to run
        if (count % COUNT_MAX_BEFORE_YIELD == 0) {
            printf("Thread %d: yielding after %d iterations\n", id, local_count);
            sched_yield();
        }
        
        // release mutex lock
        pthread_mutex_unlock(&lock);
    }
    
    printf("Thread %d finished with count value of %d\n", id, count);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i, rc;
    
    // initialize mutex
    pthread_mutex_init(&lock, NULL);
    
    // create threads
    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        rc = pthread_create(&threads[i], NULL, thread_func, (void *)&thread_ids[i]);
        
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    
    // join threads
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        
        if (rc) {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }
    
    // destroy mutex
    pthread_mutex_destroy(&lock);
    
    printf("Final count value is %d\n", count);
    
    pthread_exit(NULL);
}