//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

/* the thread function */
void *run(void *tid) {
    int thread_id = *((int*) tid);
    printf("Thread %d: Starting...\n", thread_id);
    printf("Thread %d: Working...\n", thread_id);
    printf("Thread %d: Finishing...\n", thread_id);
    pthread_exit(NULL);
}

int main (int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int rc;
    int t;

    for(t=0;t<NUM_THREADS;t++) {
        thread_ids[t] = t;
        printf("Main: Creating thread %d\n", t);
        rc = pthread_create(&threads[t], NULL, run, (void*) &thread_ids[t]);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    /* Wait for all threads to complete */
    for(t=0;t<NUM_THREADS;t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        printf("Main: Thread %d has completed\n", t);
    }

    printf("Main: Program exiting.\n");
    pthread_exit(NULL);
}