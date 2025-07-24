//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define THREAD_COUNT 5

void *print_thread_id(void *thread_id);
void *print_thread_message(void *message);

int main()
{
    int i;
    pthread_t threads[THREAD_COUNT];
    
    printf("Starting program...\n");
    
    // Create threads that print their thread ID
    for (i = 0; i < THREAD_COUNT; i++)
    {
        printf("Creating thread %d...\n", i);
        if (pthread_create(&threads[i], NULL, print_thread_id, (void *)i) != 0)
        {
            printf("Error creating thread %d.\n", i);
            exit(1);
        }
    }
    
    // Wait for all threads to finish executing
    for (i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
        printf("Thread %d has finished executing.\n", i);
    }
    
    // Create thread that prints a message
    char *message = "This is a message from a thread!";
    pthread_t message_thread;
    if (pthread_create(&message_thread, NULL, print_thread_message, (void *)message) != 0)
    {
        printf("Error creating message thread.\n");
        exit(1);
    }
    pthread_join(message_thread, NULL);
    
    printf("Program has finished executing.\n");
    
    return 0;
}

void *print_thread_id(void *thread_id)
{
    printf("Thread %d is executing.\n", (int)thread_id);
    pthread_exit(NULL);
}

void *print_thread_message(void *message)
{
    printf("%s\n", (char *)message);
    pthread_exit(NULL);
}