//FormAI DATASET v1.0 Category: Random ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

void *randomNum(void *arg);

int main()
{
    srand(time(NULL));
    pthread_t thread;

    if (pthread_create(&thread, NULL, randomNum, NULL) != 0)
    {
        perror("pthread_create");
        exit(-1);
    }

    printf("Waiting for the random numbers...\n");
    pthread_join(thread, NULL);
    printf("\nRandom number generation complete!\n");

    return 0;
}

void *randomNum(void *arg)
{
    int count = 0, number;
    while (count < 10)
    {
        number = rand() % 100;
        printf("%d ", number);
        fflush(stdout);
        sleep(1);
        count++;
    }
    return NULL;
}