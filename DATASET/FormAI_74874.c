//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg);

int main()
{
    pthread_t thread1, thread2;
    int value1 = 5, value2 = 10;

    pthread_create(&thread1, NULL, thread_function, (void *)&value1);
    pthread_create(&thread2, NULL, thread_function, (void *)&value2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads have completed execution.\n");
    return 0;
}

void *thread_function(void *arg)
{
    int value = *(int *)arg;

    printf("Thread started with value %d.\n", value);

    for (int i = 1; i <= value; i++)
    {
        printf("%d ", i);
    }

    printf("\nThread finished with value %d.\n", value);

    pthread_exit(NULL);
}