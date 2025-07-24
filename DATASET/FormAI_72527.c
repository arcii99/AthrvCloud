//FormAI DATASET v1.0 Category: Task Scheduler ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* task_a(void* arg);
void* task_b(void* arg);

int main()
{
    pthread_t thread1;
    pthread_t thread2;

    int t1_arg = 1;
    int t2_arg = 2;

    if (pthread_create(&thread1, NULL, task_a, &t1_arg) != 0)
    {
        printf("Error creating thread 1\n");
        return 1;
    }

    if (pthread_create(&thread2, NULL, task_b, &t2_arg) != 0)
    {
        printf("Error creating thread 2\n");
        return 1;
    }

    if (pthread_join(thread1, NULL) != 0)
    {
        printf("Error joining thread 1\n");
        return 1;
    }

    if (pthread_join(thread2, NULL) != 0)
    {
        printf("Error joining thread 2\n");
        return 1;
    }

    return 0;
}

void* task_a(void* arg)
{
    int i;

    for (i = 0; i < 10; ++i)
    {
        printf("Task A, iteration %d\n", i);
        sleep(1);
    }

    pthread_exit(NULL);
}

void* task_b(void* arg)
{
    int i;

    for (i = 0; i < 10; ++i)
    {
        printf("Task B, iteration %d\n", i);
        sleep(1);
    }

    pthread_exit(NULL);
}