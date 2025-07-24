//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: expert-level
// Simple Threading Library Implementation in C
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread1(void *arg);
void *thread2(void *arg);

int main()
{
    pthread_t tid1, tid2; // thread identifiers
    pthread_attr_t attr; // set of thread attributes

    // get the default attributes
    pthread_attr_init(&attr);

    // create the threads
    pthread_create(&tid1, &attr, thread1, NULL);
    pthread_create(&tid2, &attr, thread2, NULL);

    // wait for the threads to finish
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    printf("Thread execution complete.\n");
}

// Thread 1 Function
void *thread1(void *arg)
{
    printf("Thread 1 executing...\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Thread 1 printing %d.\n", i);
    }
    printf("Thread 1 exiting...\n");
    pthread_exit(0);
}

// Thread 2 Function
void *thread2(void *arg)
{
    printf("Thread 2 executing...\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Thread 2 printing %d.\n", i);
    }
    printf("Thread 2 exiting...\n");
    pthread_exit(0);
}