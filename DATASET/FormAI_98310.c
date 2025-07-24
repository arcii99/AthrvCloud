//FormAI DATASET v1.0 Category: Benchmarking ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>

#define THREADS 4
#define MAX 100000000

int counter = 0;

void *increment_counter(void *arg) {
    int i;
    for(i = 0; i < MAX / THREADS; i++) {
        counter++;
    }
    return NULL;
}

int main() {

    struct timeval start, end;
    gettimeofday(&start, NULL);

    pthread_t threads[THREADS];

    int i;
    for(i = 0; i < THREADS; i++) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    for(i = 0; i < THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    gettimeofday(&end, NULL);
    double time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Counter value: %d\n", counter);
    printf("Time taken with %d threads: %f seconds\n", THREADS, time);

    return 0;
}