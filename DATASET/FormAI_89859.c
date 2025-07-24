//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: romantic
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[2]; // Thread ID's
int counter;
pthread_mutex_t lock; // Mutex

void* doSomeThing(void *arg)
{
    pthread_mutex_lock(&lock); // Mutex Lock

    unsigned long i = 0;
    counter += 1;

    printf("\n Job %d started\n", counter);

    for(i=0; i<(0xFFFFFFFF);i++);

    printf("\n Job %d finished\n", counter);

    pthread_mutex_unlock(&lock); // Mutex Unlock

    return NULL;
}

int main(void)
{
    int i = 0;

    if (pthread_mutex_init(&lock, NULL) != 0) // Mutex Initialization
    {
        printf("\n Mutex Init Failed\n");
        return 1;
    }

    while(i < 2) // Creating two threads
    {
        if(pthread_create(&tid[i], NULL, &doSomeThing, NULL) != 0)
        {
            printf("\n Error creating thread\n");
            return 1;
        }
        i++;
    }

    pthread_join(tid[0], NULL); // Joining threads
    pthread_join(tid[1], NULL);

    pthread_mutex_destroy(&lock); // Mutex Destroy

    return 0;
}