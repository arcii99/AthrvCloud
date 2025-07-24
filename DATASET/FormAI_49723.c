//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 10

void *thread_function(void *arg);

int main(int argc, char ** argv) {
    int i, rc;
    pthread_t threads[NUM_THREADS];
    
    for (i = 0; i < NUM_THREADS; i++) {
        printf("Creating thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, thread_function, (void *) &i);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }
    
    printf("All threads have been completed successfully\n");
    
    return 0;
}

void *thread_function(void *arg) {
    int thread_num = *(int*) arg;
    printf("Thread %d is running\n", thread_num);
    sleep(1);
    printf("Thread %d has finished\n", thread_num);
    pthread_exit(NULL);
}