//FormAI DATASET v1.0 Category: Funny ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void *thread_function(void *arg);

int main()
{
    pthread_t threads[3];
    int thread_args[3] = {0, 1, 2};
    int i;

    for (i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *)&thread_args[i]);
        sleep(1);
    }

    for (i = 0; i < 3; i++)
        pthread_join(threads[i], NULL);

    printf("All threads completed successfully\n");
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
    int thread_num = *(int *)arg;
    int i;

    for (i = 0; i < 5; i++) {
        printf("Thread %d: Counting %d\n", thread_num, i);
        usleep(1000000);
    }

    printf("Thread %d: Done counting.\n", thread_num);
    pthread_exit(NULL);
}