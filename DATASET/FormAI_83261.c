//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sum = 0;
pthread_mutex_t mutex;

void *runner(void *num) {
    pthread_mutex_lock(&mutex); // acquire lock on shared resource
    int n = *((int *) num);
    sum += n; // update shared resource
    pthread_mutex_unlock(&mutex); // release lock on shared resource
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <n1> <n2> ... <nk>\n", argv[0]);
        exit(1);
    }

    int n = argc - 1; // number of elements to sum
    int arr[n]; // array of numbers to sum

    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i+1]); // convert command line argument to integer
    }

    pthread_t tids[n]; // array of thread identifiers

    pthread_mutex_init(&mutex, NULL); // initialize mutex

    for (int i = 0; i < n; i++) {
        pthread_create(&tids[i], NULL, runner, (void *) &arr[i]); // create thread for each element in arr
    }

    for (int i = 0; i < n; i++) {
        pthread_join(tids[i], NULL); // wait for each thread to finish
    }

    pthread_mutex_destroy(&mutex); // destroy mutex

    printf("Sum = %d\n", sum); // print final sum

    return 0;
}