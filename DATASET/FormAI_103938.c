//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *thread_id);

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, i;
    
    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating Thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, thread_func, (void *)i);
        
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    printf("All threads created successfully!\n");
    
    pthread_exit(NULL);
}

void *thread_func(void *thread_id) {
    int tid;
    tid = (int)thread_id;
    printf("Thread %d is starting\n", tid);
    pthread_exit(NULL);
}