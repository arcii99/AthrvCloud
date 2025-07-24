//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// thread function
void *print_hello(void *threadid)
{
    // print thread ID and hello message
    long tid;
    tid = (long)threadid;
    printf("Hello from thread %ld\n", tid);
    
    // exit the thread
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // create threads
    for(t=0; t<NUM_THREADS; t++){
        printf("Creating thread %ld\n", t);
        // pass thread ID and create thread
        rc = pthread_create(&threads[t], NULL, print_hello, (void *)t);

        if (rc){
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // wait for threads to finish before exit
    for(t=0; t<NUM_THREADS; t++){
        pthread_join(threads[t], NULL);
    }
    
    // exit the program
    pthread_exit(NULL);
}