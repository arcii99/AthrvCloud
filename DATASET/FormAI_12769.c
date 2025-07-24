//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define THREADS_NUM 4 // Define the number of threads to use
#define LOOP_TIMES 5 // Define the number of times each thread will loop

// Define a function to be executed by each thread
void *thread_function(void *thread_arg)
{
    int thread_id = *((int*) thread_arg); // Cast thread_arg to integer
    printf("Thread %d starting...\n", thread_id);
    int i;
    for (i = 0; i < LOOP_TIMES; i++)
    {
        printf("Thread %d is looping %d out of %d times\n", thread_id, i+1, LOOP_TIMES);
        sleep(1); // Pause for 1 second to simulate work
    }
    printf("Thread %d exiting...\n", thread_id);
    pthread_exit(NULL);
}

int main()
{
    printf("Multi-threading example program starting...\n");

    pthread_t threads[THREADS_NUM]; // Array to hold thread IDs
    int thread_ids[THREADS_NUM]; // Array to hold integer thread IDs

    int i;
    for (i = 0; i < THREADS_NUM; i++)
    {
        thread_ids[i] = i + 1; // Assign integer ID to each thread
        int status = pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]); // Start the thread
        if (status != 0)
        {
            printf("Error creating thread %d. Exiting...\n", i+1);
            exit(1);
        }
    }

    for (i = 0; i < THREADS_NUM; i++)
    {
        int status = pthread_join(threads[i], NULL); // Wait for the thread to finish
        if (status != 0)
        {
            printf("Error joining thread %d. Exiting...\n", i+1);
            exit(1);
        }
    }

    printf("Multi-threading example program finished.\n");
    return 0;
}