//FormAI DATASET v1.0 Category: Benchmarking ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

#define BILLION 1000000000L

int num_threads = 4;
int num_iterations = 1000000;
int value = 0;
pthread_mutex_t lock;
struct timespec start, end;

void *thread_function(void *arg) {
    int i, j;
    for (i = 0; i < num_iterations; i++) {
        pthread_mutex_lock(&lock);
        for (j = 0; j < 1000; ++j) {
            value++;
        }
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL); 
}

int main() {
    long long total_time;
    int i, rc;

    pthread_t threads[num_threads];
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    pthread_mutex_init(&lock, NULL);

    clock_gettime(CLOCK_MONOTONIC, &start);

    for (i = 0; i < num_threads; i++) {
        rc = pthread_create(&threads[i], &attr, thread_function, (void *)i);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_attr_destroy(&attr);

    for (i = 0; i < num_threads; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    total_time = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
    printf("Time taken = %lld nanoseconds\n", total_time);

    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);
}