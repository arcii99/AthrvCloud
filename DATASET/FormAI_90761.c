//FormAI DATASET v1.0 Category: Data validation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100 //Maximum number of elements in our array

int arr[MAX]; //Global integer array to store the elements

pthread_mutex_t lock; //Global lock

void* validationThread(void* arg) {
    int* data = (int*) arg;

    int isValid = 1;

    for (int i = 0; i < MAX; i++) {
        if (data[i] < 0 || data[i] > 100) isValid = 0;
    }

    pthread_mutex_lock(&lock);
    if (isValid) {
        printf("Data is valid.\n");
    }
    else {
        printf("Data is invalid.\n");
    }
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

void* fillingThread(void* arg) {
    int* data = (int*) arg;

    for (int i = 0; i < MAX; i++) {
        data[i] = rand() % 101 - 50;
    }

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL)); //Seed the random number generator

    pthread_t thread1, thread2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread1, NULL, fillingThread, (void*) arr);

    pthread_join(thread1, NULL);

    pthread_create(&thread2, NULL, validationThread, (void*) arr);

    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}