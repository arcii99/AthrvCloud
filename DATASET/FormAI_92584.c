//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: lively
#include <stdio.h>
#include <pthread.h>

// This is a simple example of implementing a threading library in C

// Function for the thread execution
void* thread_function(void* arg)
{
    int i;
    for(i = 1; i <= 10; i++)
    {
        printf("%d\n", i);
    }
    return NULL;
}

int main()
{
    // Creating the thread
    pthread_t thread;

    // Creating the attribute
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    // Setting the attribute to joinable
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    // Creating the thread with the attribute
    pthread_create(&thread, &attr, thread_function, NULL);

    // Destroying the attribute
    pthread_attr_destroy(&attr);

    // Waiting for the thread to finish
    pthread_join(thread, NULL);

    // Exiting the main thread
    pthread_exit(NULL);

    // End of program
    return 0;
}