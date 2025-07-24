//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: thoughtful
/* 

    This is a simple C Threading Library Implementation
    inspired by the PThread Library. The library is used 
    to create multiple threads of execution within a single process. 
    
    In this example program, we will create 3 threads and use 
    them to perform some simple tasks.
    
    Author: John Doe (johndoe@example.com)
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads we want to create
// and the number of tasks each thread should perform
#define NUM_THREADS 3
#define TASKS_PER_THREAD 5

// Thread function that performs some simple tasks
void *task(void *id)
{
    int tid = *((int *)id);
    printf("Thread %d performing %d tasks...\n", tid, TASKS_PER_THREAD);
    
    // Perform some simple tasks
    int i;
    for (i = 1; i <= TASKS_PER_THREAD; i++) {
        printf("Thread %d: Task %d\n", tid, i);
    }
    
    printf("Thread %d finished all tasks.\n", tid);
    pthread_exit(NULL);
}

int main()
{
    // Initialize variables
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i;
    
    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i+1;
        if (pthread_create(&threads[i], NULL, task, (void *)&thread_ids[i])) {
            fprintf(stderr, "Error creating thread %d.\n", i+1);
            exit(EXIT_FAILURE);
        }
    }
    
    // Wait for threads to finish their tasks
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread %d.\n", i+1);
            exit(EXIT_FAILURE);
        }
    }
    
    // Exit program
    printf("All threads finished their tasks successfully.\n");
    pthread_exit(NULL);
}