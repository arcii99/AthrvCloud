//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: complete
#include <stdio.h>
#include <pthread.h>

// Function to print the thread ID
void *thread_func(void *arg)
{
    printf("Thread ID: %ld\n", pthread_self());
    pthread_exit(NULL);
}

int main()
{
    // Declare two threads
    pthread_t thread1, thread2;

    // Create thread 1 and check for errors
    if (pthread_create(&thread1, NULL, thread_func, NULL) != 0)
    {
        printf("Error creating thread 1.\n");
        return 1;
    }

    // Create thread 2 and check for errors
    if (pthread_create(&thread2, NULL, thread_func, NULL) != 0)
    {
        printf("Error creating thread 2.\n");
        return 1;
    }


    // Wait for both threads to finish
    if (pthread_join(thread1, NULL) != 0)
    {
        printf("Error joining thread 1.\n");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0)
    {
        printf("Error joining thread 2.\n");
        return 1;
    }

    printf("Both threads have completed.\n");

    return 0;
}