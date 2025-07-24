//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

/* function executed by each thread */
void *threadFunction(void *arg) {
    int id = *((int*)arg);
    printf("Thread %d started\n", id);
    
    /* do some work */
    for (int i = 0; i < 10000000; i++) {}
    
    printf("Thread %d finished\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int *ids[NUM_THREADS];
    int rc;
    int i;
    
    /* create threads */
    for (i = 0; i < NUM_THREADS; i++) {
        ids[i] = (int*)malloc(sizeof(int));
        *ids[i] = i;
        rc = pthread_create(&threads[i], NULL, threadFunction, (void*)ids[i]);
        if (rc) {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    
    /* wait for threads to finish */
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        free(ids[i]);
    }
    
    printf("All threads finished\n");
    pthread_exit(NULL);
}