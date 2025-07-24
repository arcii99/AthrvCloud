//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

//Function executed by threads
void *threadFunction(void *arg)
{
    int *id = (int *)arg;
    printf("Hello from thread %d\n", *id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread[NUM_THREADS]; //Array of NUM_THREADS threads
    int threadID[NUM_THREADS]; //Array of NUM_THREADS unique thread IDs
    int i;

    //Create threads
    for(i=0; i<NUM_THREADS; i++)
    {
        threadID[i] = i; //Assign unique thread ID
        printf("Creating thread %d\n", i);
        int status = pthread_create(&thread[i], NULL, threadFunction, &threadID[i]);
        if(status != 0) //Check if thread creation failed
        {
            printf("Error creating thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    //Join threads
    for(i=0; i<NUM_THREADS; i++)
    {
        printf("Joining thread %d\n", i);
        int status = pthread_join(thread[i], NULL);
        if(status != 0) //Check if thread joining failed
        {
            printf("Error joining thread %d\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("All threads have terminated\n");

    pthread_exit(NULL);
}