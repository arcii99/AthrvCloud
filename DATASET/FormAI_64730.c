//FormAI DATASET v1.0 Category: System boot optimizer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * bootOptimization(void *);

int main()
{
    pthread_t thread1, thread2;
    char * message1 = "Thread 1: Running boot optimization process...";
    char * message2 = "Thread 2: Running cleanup process...";

    int ret1 = pthread_create(&thread1, NULL, bootOptimization, (void*) message1);

    if(ret1)
    {
        printf("Error: unable to create thread %d\n", ret1);
        exit(-1);
    }

    int ret2 = pthread_create(&thread2, NULL, bootOptimization, (void*) message2);

    if(ret2)
    {
        printf("Error: unable to create thread %d\n", ret2);
        exit(-1);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("\nBoot optimization and cleanup processes have completed successfully.\n");

    exit(0);
}

void * bootOptimization(void * arg)
{
    char * message = (char *) arg;

    printf("%s\n", message);

    for(int i = 1; i <= 10; i++)
    {
        printf("Processing task %d of 10...\n", i);
        sleep(1);
    }

    printf("Boot optimization process has completed successfully.\n");

    pthread_exit(NULL);
}