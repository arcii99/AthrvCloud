//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *param)
{
    // Print a message
    printf("Thread Started.\n");

    // Sleep for 2 seconds to simulate some work
    sleep(2);

    // Print another message
    printf("Thread Completed.\n");

    // Exit the thread
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    // Create the thread
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &thread_function, NULL);

    // Wait for the thread to complete
    pthread_join(thread_id, NULL);

    // Print a final message
    printf("Main Function Completed.\n");

    // Exit the program
    exit(EXIT_SUCCESS);
}