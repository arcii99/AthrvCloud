//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void *thread_func(void *thread_id) {
    int tid = *(int *)thread_id;
    printf("Thread %d is starting...\n", tid);
    printf("Thread %d is working...\n", tid);
    printf("Thread %d is ending...\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int tids[NUM_THREADS];
    int i;
    
    for (i = 0; i < NUM_THREADS; i++) {
        tids[i] = i;
        printf("Creating thread %d...\n", i);
        int ret = pthread_create(&threads[i], NULL, &thread_func, (void *)&tids[i]);
        if (ret) {
            printf("ERROR: return code from pthread_create() is %d\n", ret);
            exit(-1);
        }
    }
    
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        printf("Thread %d has joined.\n", i);
    }
    
    return 0;
}