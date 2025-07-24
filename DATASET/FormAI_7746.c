//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *funny_thread(void *arg)
{
    int count = 0;
    while(count < 5)
    {
        printf("This thread is hilarious! %d\n", count);
        count++;
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread;
    int rc;
    printf("Starting the program...\n");

    rc = pthread_create(&thread, NULL, funny_thread, NULL);
    if(rc)
    {
        printf("Error: Unable to create thread, code %d\n", rc);
        exit(-1);
    }

    printf("I'm the main thread and I'm waiting for my funny friend...\n");

    pthread_join(thread, NULL);

    printf("The funny thread is done!\n");

    return 0;
}