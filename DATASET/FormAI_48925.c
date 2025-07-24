//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 5

void *print_hello(void *thread_id)
{
    long tid;
    tid = (long) thread_id;
    printf("Thread %ld: Hello, World!\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for(t=0; t<NUM_THREADS; t++)
    {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, print_hello, (void*)t);

        if(rc)
        {
            printf("Error: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to complete execution
    for(t=0; t<NUM_THREADS; t++)
    {
        pthread_join(threads[t], NULL);
    }

    printf("All threads have completed execution.\n");
    pthread_exit(NULL);
}