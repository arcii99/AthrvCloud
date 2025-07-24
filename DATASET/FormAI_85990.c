//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//function to be executed by each thread
void* print_thread(void *thread_id){
    long tid = (long)thread_id;
    printf("I am thread %ld\n", tid);
    pthread_exit(NULL);
}

//main function
int main(){
    printf("Welcome to my Threading Library Implementation program, my dear Watson.\n");

    //initialize the threads
    pthread_t threads[5];
    int rc;
    long t;

    //loop to create and execute threads
    for(t=0; t<5; t++){
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, print_thread, (void *)t);
        if(rc){
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    //wait for all threads to complete execution
    for(t=0; t<5; t++){
        pthread_join(threads[t], NULL);
    }

    printf("All threads have completed execution. My work here is done.\n");

    return 0;
}