//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5

pthread_t threads[MAX_THREADS];
int thread_nums[MAX_THREADS];

void *thread_func(void *arg)
{
    int thread_num = *(int *)arg;
    printf("Thread %d executing\n", thread_num);
    pthread_exit(NULL);
}

int main()
{
    int i, ret;

    /* Create threads */
    for (i = 0; i < MAX_THREADS; i++) {
        thread_nums[i] = i;
        ret = pthread_create(&threads[i], NULL, thread_func, &thread_nums[i]);
        if (ret) {
            printf("Error: pthread_create returned %d\n", ret);
            exit(EXIT_FAILURE);
        }
        printf("Thread %d created\n", i);
    }

    /* Wait for threads to complete */
    for (i = 0; i < MAX_THREADS; i++) {
        ret = pthread_join(threads[i], NULL);
        if (ret) {
            printf("Error: pthread_join returned %d\n", ret);
            exit(EXIT_FAILURE);
        }
        printf("Thread %d completed\n", i);
    }

    printf("All threads completed\n");
    return 0;
}