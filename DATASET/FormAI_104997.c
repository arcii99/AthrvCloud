//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex; // declare a mutex

int shared_var = 0; // declare a shared variable

void *increment(void *args) {
    pthread_mutex_lock(&mutex); // lock the mutex
    shared_var++; // increment the shared variable
    printf("Thread %d incremented the shared variable to %d\n", (int)pthread_self(), shared_var);
    pthread_mutex_unlock(&mutex); // unlock the mutex
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    pthread_mutex_init(&mutex, NULL); // initialize the mutex

    pthread_create(&thread1, NULL, increment, NULL); // create first thread
    pthread_create(&thread2, NULL, increment, NULL); // create second thread

    pthread_join(thread1, NULL); // wait for first thread to finish
    pthread_join(thread2, NULL); // wait for second thread to finish

    pthread_mutex_destroy(&mutex); // destroy the mutex

    printf("The final value of the shared variable is %d\n", shared_var);

    return 0;
}