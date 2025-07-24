//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: ephemeral
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lock2 = PTHREAD_MUTEX_INITIALIZER;

void *thread1(void *arg) {
    printf("Thread 1 started\n");
    pthread_mutex_lock(&lock1);
    printf("Thread 1 acquired lock 1\n");
    sleep(1);
    pthread_mutex_lock(&lock2);
    printf("Thread 1 acquired lock 2\n");
    pthread_mutex_unlock(&lock2);
    printf("Thread 1 released lock 2\n");
    pthread_mutex_unlock(&lock1);
    printf("Thread 1 released lock 1\n");
    return NULL;
}

void *thread2(void *arg) {
    printf("Thread 2 started\n");
    pthread_mutex_lock(&lock2);
    printf("Thread 2 acquired lock 2\n");
    sleep(1);
    pthread_mutex_lock(&lock1);
    printf("Thread 2 acquired lock 1\n");
    pthread_mutex_unlock(&lock1);
    printf("Thread 2 released lock 1\n");
    pthread_mutex_unlock(&lock2);
    printf("Thread 2 released lock 2\n");
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t thread[2];

    int rc = pthread_create(&thread[0], NULL, thread1, NULL);
    if (rc) {
        fprintf(stderr, "Error creating thread 1: %d\n", rc);
        return EXIT_FAILURE;
    }
    printf("Thread 1 created\n");
    
    rc = pthread_create(&thread[1], NULL, thread2, NULL);
    if (rc) {
        fprintf(stderr, "Error creating thread 2: %d\n", rc);
        return EXIT_FAILURE;
    }
    printf("Thread 2 created\n");

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    return EXIT_SUCCESS;
}