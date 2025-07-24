//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_message(void *threadID)
{
    int id = *(int*)threadID;
    printf("Thread ID: %d\n", id);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int threadID[NUM_THREADS];
    int i;

    for(i = 0; i < NUM_THREADS; i++)
    {
        threadID[i] = i+1;
        int rc = pthread_create(&threads[i], NULL, print_message, (void*)&threadID[i]);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_exit(NULL);
    return 0;
}