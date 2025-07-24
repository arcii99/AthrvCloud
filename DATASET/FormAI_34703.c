//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: protected
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Mutex declaration
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *print_message(void *ptr)
{
    char *message;
    message = (char *) ptr;

    // Using mutex to protect the shared resource
    pthread_mutex_lock(&lock);
    printf("%s\n", message);
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int thread_result;

    // Creating thread 1
    thread_result = pthread_create(&thread1, NULL, print_message, (void*) message1);
    if (thread_result)
    {
        printf("Error: Return code from pthread_create() is %d\n", thread_result);
        exit(-1);
    }

    // Creating thread 2
    thread_result = pthread_create(&thread2, NULL, print_message, (void*) message2);
    if (thread_result)
    {
        printf("Error: Return code from pthread_create() is %d\n", thread_result);
        exit(-1);
    }

    // Waiting for threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroying mutex
    pthread_mutex_destroy(&lock);

    // Exiting the program
    pthread_exit(NULL);

    return 0;
}