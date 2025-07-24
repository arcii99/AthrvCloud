//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// function run by threads
void* thread_func(void *arg)
{
    int tid = *(int*)arg;

    // cyberpunk style message
    printf("Hacker %d running...\n", tid);
    sleep(2);

    // cyberpunk style message
    printf("Hacker %d infiltrating system...\n", tid);
    sleep(3);

    // cyberpunk style message
    printf("Hacker %d planting code...\n", tid);
    sleep(4);

    // cyberpunk style message
    printf("Hacker %d exiting system...\n", tid);

    // end thread
    pthread_exit(NULL);
}

int main()
{
    // array of thread IDs
    pthread_t threads[5];

    // array of thread arguments
    int args[5];

    // create threads
    for(int i=0; i<5; i++)
    {
        args[i] = i+1;
        int rc = pthread_create(&threads[i], NULL, thread_func, &args[i]);
        if (rc)
        {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    // join threads
    for(int i=0; i<5; i++)
    {
        int rc = pthread_join(threads[i], NULL);
        if (rc)
        {
            printf("Error: return code from pthread_join() is %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}