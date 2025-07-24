//FormAI DATASET v1.0 Category: Date and time ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 2

void *printDate(void *arg)
{
    time_t now;
    struct tm *localTime;
    char buffer[80];

    now = time(NULL);
    localTime = localtime(&now);

    strftime(buffer, sizeof(buffer), "Today is %A, %B %d, %Y.\n", localTime);
    printf("%s", buffer);

    pthread_exit(NULL);
}

void *printTime(void *arg)
{
    time_t now;
    struct tm *localTime;
    char buffer[80];

    now = time(NULL);
    localTime = localtime(&now);

    strftime(buffer, sizeof(buffer), "Current time is %I:%M:%S %p.\n", localTime);
    printf("%s", buffer);

    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc1, rc2;

    rc1 = pthread_create(&threads[0], NULL, printDate, NULL);
    rc2 = pthread_create(&threads[1], NULL, printTime, NULL);

    if(rc1 || rc2){
        printf("Error: return code from pthread_create() is %d\n", rc1);
        exit(-1);
    }

    printf("Waiting for threads to finish...\n");

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    exit(0);
}