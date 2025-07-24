//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    int *index = (int *)arg; // Get the index of the thread
    printf("This is thread number %d\n", *index);
    return NULL;
}

int main()
{
    pthread_t threads[5]; // Create 5 threads
    int i;

    for (i = 0; i < 5; i++)
    {
        if (pthread_create(&threads[i], NULL, thread_function, (void *)&i))
        {
            printf("Error creating thread %d\n", i);
        }
    }

    for (i = 0; i < 5; i++)
    {
        if (pthread_join(threads[i], NULL))
        {
            printf("Error joining thread %d\n", i);
        }
    }

    printf("All threads have finished\n");

    return 0;
}