//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *);

#define NUM_THREADS 5

int main()
{
    int res, i;
    pthread_t a_thread[NUM_THREADS];
    void *thread_result;

    for (i = 0; i < NUM_THREADS; i++)
    {
        res = pthread_create(&(a_thread[i]), NULL, thread_function, (void *)i);
        if (res != 0)
        {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    printf("Waiting for threads to finish...\n");

    for (i = 0; i < NUM_THREADS; i++)
    {
        res = pthread_join(a_thread[i], &thread_result);
        if (res != 0)
        {
            perror("Thread join failed");
            exit(EXIT_FAILURE);
        }
        printf("Thread %d joined\n", i);
    }

    printf("All threads have finished\n");
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
    int my_number = (int)arg;
    int rand_num;

    printf("Thread %d starting...\n", my_number);
    rand_num = 1 + (int)(9.0 * rand() / (RAND_MAX + 1.0));
    sleep(rand_num);
    printf("Thread %d finished after sleeping %d seconds\n", my_number, rand_num);

    pthread_exit(NULL);
}