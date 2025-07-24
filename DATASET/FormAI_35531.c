//FormAI DATASET v1.0 Category: Memory management ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2
#define MAX_ALLOC 1000000

void *thread_func(void *arg)
{
    int *arr = NULL;
    int size = *(int*)arg;
    arr = (int*)malloc(size * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        pthread_exit(NULL);
    }
    else
    {
        printf("Allocated %d bytes successfully!\n", size * sizeof(int));
        int i;
        for (i = 0; i < size; i++)
        {
            arr[i] = i;
        }
    }

    pthread_exit((void*)arr);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int sizes[NUM_THREADS] = { MAX_ALLOC / 2, MAX_ALLOC / 2 };
    void *status[NUM_THREADS];

    int i;
    for (i = 0; i < NUM_THREADS; i++)
    {
        int rc = pthread_create(&threads[i], NULL, thread_func, (void*)&sizes[i]);

        if (rc)
        {
            printf("Error creating thread: %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++)
    {
        int rc = pthread_join(threads[i], &status[i]);
        if (rc)
        {
            printf("Error joining thread: %d\n", rc);
            exit(-1);
        }
        else
        {
            int *arr = status[i];
            printf("Thread %d allocated memory successfully!\n", i);
            if (arr != NULL)
            {
                printf("Sample data from array:");
                int j;
                for (j = 0; j < sizes[i]; j++)
                {
                    printf("%d ", arr[j]);
                }
                printf("\n");
                free(arr);
            }
        }
    }

    pthread_exit(NULL);
}