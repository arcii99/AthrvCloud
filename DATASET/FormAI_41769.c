//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_t tid[2];

void* func1(void* arg)
{
    int i;
    printf("\n Thread 1 is running\n");
    for (i = 0; i < 5; i++) 
    {
        printf("\n Thread 1 is still running\n");
        sleep(1);
    }
    printf("\n Thread 1 is done running\n");
    return NULL;
}

void* func2(void* arg) 
{
    int i;
    printf("\n Thread 2 is running\n");
    for (i = 0; i < 5; i++) 
    {
        printf("\n Thread 2 is still running\n");
        sleep(1);
    }
    printf("\n Thread 2 is done running\n");
    return NULL;
}

int main() 
{
    int i;
    if (pthread_create(&tid[0], NULL, &func1, NULL) != 0)
        printf("\n Thread 1 creation failed\n");
    else
        printf("\n Thread 1 created successfully\n");
    if (pthread_create(&tid[1], NULL, &func2, NULL) != 0)
        printf("\n Thread 2 creation failed\n");
    else
        printf("\n Thread 2 created successfully\n");

    if (pthread_join(tid[0], NULL) != 0)
        printf("\n Thread 1 join failed\n");
    else
        printf("\n Thread 1 join successfull\n");
    if (pthread_join(tid[1], NULL) != 0)
        printf("\n Thread 2 join failed\n");
    else
        printf("\n Thread 2 join successfull\n");

    return 0;
}