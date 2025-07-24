//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: future-proof
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

// Function that each thread will execute
void* threadFunc(void* threadId){
    long id = (long) threadId;
    printf("Thread #%ld started.\n", id);
    for(int i=0; i<5; i++){
        printf("Thread #%ld counting: %d\n", id, i);
        sleep(1);
    }
    printf("Thread #%ld finished counting.\n", id);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Creating threads
    for(t=0; t<NUM_THREADS; t++){
        printf("Creating thread #%ld\n", t);
        rc = pthread_create(&threads[t], NULL, threadFunc, (void*) t);
        if(rc){
            printf("Error creating thread. Return code: %d\n", rc);
            return 1;
        }
    }

    // Waiting for threads to finish
    for(t=0; t<NUM_THREADS; t++){
        pthread_join(threads[t], NULL);
    }

    printf("All threads have finished counting. Exiting program.\n");

    pthread_exit(NULL);
    return 0;
}