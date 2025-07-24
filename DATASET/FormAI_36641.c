//FormAI DATASET v1.0 Category: Error handling ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *threadFunction1(void *arg);
void *threadFunction2(void *arg);

int main() {
    pthread_t thread1, thread2;
    int thread1Result, thread2Result;

    thread1Result = pthread_create(&thread1, NULL, threadFunction1, NULL);
    if (thread1Result) {
        printf("Error - pthread_create() for thread 1 returned error code: %d\n", thread1Result);
        exit(EXIT_FAILURE);
    }

    thread2Result = pthread_create(&thread2, NULL, threadFunction2, NULL);
    if (thread2Result) {
        printf("Error - pthread_create() for thread 2 returned error code: %d\n", thread2Result);
        exit(EXIT_FAILURE);
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Both threads completed successfully.\n");

    return 0;
}

void *threadFunction1(void *arg) {
    printf("Thread 1 executing.\n");
    return NULL;
}

void *threadFunction2(void *arg) {
    printf("Thread 2 executing.\n");

    int randomNum = rand() % 10;
    if (randomNum == 0) {
        printf("Error - random number generator returned 0.\n");
        pthread_exit(NULL);
        // Exit the thread early, without calling pthread_join() below.
    }

    return NULL;
}