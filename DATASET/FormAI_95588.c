//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

/* Define a structure to hold thread data */
typedef struct
{
    int thread_id;
    char *message;
} thread_data_t;

/* Thread function that prints thread ID and message */
void *print_message_thread(void *threadarg)
{
    thread_data_t *thread_data = (thread_data_t *) threadarg;
    int thread_id = thread_data->thread_id;
    char *message = thread_data->message;
    printf("Thread %d: %s\n", thread_id, message);
    pthread_exit(NULL);
}

/* Main function to create threads */
int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];
    int rc, t;

    /* Initialize thread data */
    for (t = 0; t < NUM_THREADS; t++)
    {
        thread_data[t].thread_id = t;
        thread_data[t].message = "Hello, world!";
    }

    /* Create threads */
    for (t = 0; t < NUM_THREADS; t++)
    {
        rc = pthread_create(&threads[t], NULL, print_message_thread, (void *)&thread_data[t]);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    /* Wait for all threads to finish */
    for (t = 0; t < NUM_THREADS; t++)
    {
        pthread_join(threads[t], NULL);
    }

    /* Exit main thread */
    pthread_exit(NULL);
}