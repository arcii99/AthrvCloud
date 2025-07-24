//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *arg) {
    int threadID = *(int*)arg;
    printf("Thread %d started...\n", threadID);
    for(int i=0; i<5; i++) {
        printf("Thread %d running %d\n", threadID, i+1);
        sleep(1);
    }
    printf("Thread %d finished.\n", threadID);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];
    
    for(int i=0; i<NUM_THREADS; i++) {
        threadIDs[i] = i+1;
        printf("Creating thread %d...\n", i+1);
        int ret = pthread_create(&threads[i], NULL, thread_func, (void*)&threadIDs[i]);
        if (ret) {
            printf("ERROR: pthread_create() returned %d\n", ret);
            exit(-1);
        }
    }

    for(int i=0; i<NUM_THREADS; i++) {
        int ret = pthread_join(threads[i], NULL);
        if (ret) {
            printf("ERROR: pthread_join() returned %d\n", ret);
            exit(-1);
        }
    }
    printf("All threads finished.\n");

    return 0;
}