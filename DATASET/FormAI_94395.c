//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MEMSIZE 1024
#define NUM_THREADS 4

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int memory[MEMSIZE];
int total_usage = 0;

void *monitor_func(void *threadid)
{
    long tid;
    tid = (long)threadid;

    int start = tid * (MEMSIZE/NUM_THREADS);
    int end = start + (MEMSIZE/NUM_THREADS);

    while (1)
    {
        int usage = 0;
        for (int i=start; i<end; i++)
        {
            if(memory[i] != 0)
            {
                usage++;
            }
        }
        pthread_mutex_lock(&mutex1);
        total_usage += usage;
        pthread_mutex_unlock(&mutex1);
        printf("Thread %ld - RAM Usage: %d\n", tid, usage);
        sleep(5); // Check every 5 seconds
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for (int i=0; i<MEMSIZE; i++)
    {
        memory[i] = 0; // Initialize memory to 0
    }

    for (t=0; t<NUM_THREADS; t++)
    {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, monitor_func, (void *)t);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    while (1)
    {
        printf("Total RAM Usage: %d\n", total_usage);
        sleep(5); // Display every 5 seconds
    }

    pthread_exit(NULL);
}