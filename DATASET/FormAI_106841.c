//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Sherlock Holmes
/*The Adventure of the Threading Library Implementation*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

void *thread_function(void *arg);

//Struct to hold arguments for thread function
typedef struct{
    int thread_no;
    int sleep_time;
} thread_args;

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc, i;
    printf("Welcome to the Threading Library Implementation Adventure!\n\n");
    
   //Array to keep track of thread arguments
    thread_args thread_data[NUM_THREADS];
    thread_data[0].thread_no = 1;
    thread_data[0].sleep_time = 2;
    thread_data[1].thread_no = 2;
    thread_data[1].sleep_time = 3;
    thread_data[2].thread_no = 3;
    thread_data[2].sleep_time = 4;

    //Create threads
    for(i = 0; i < NUM_THREADS; i++){
        rc = pthread_create(&threads[i], NULL, thread_function, (void *)&thread_data[i]);
        
        if(rc){
            printf("ERROR: Unable to create thread %d. Return code: %d\n", i+1, rc);
            exit(-1);
        }
    }
    
    //Join threads
    for(i = 0; i < NUM_THREADS; i++){
        rc = pthread_join(threads[i], NULL);
        
        if(rc){
            printf("ERROR: Unable to join thread %d. Return code: %d\n", i+1, rc);
            exit(-1);
        }
    }
    
    printf("\nThe End! Thank you for participating.\n");

    return 0;
}

void *thread_function(void *arg)
{
    thread_args *my_args = (thread_args *) arg;
    int thread_no = my_args -> thread_no;
    int sleep_time = my_args -> sleep_time;
    printf("Thread %d created. Sleeping for %d seconds...\n", thread_no, sleep_time);
    sleep(sleep_time);
    printf("Thread %d waking up!\n", thread_no);
    pthread_exit(NULL);
}