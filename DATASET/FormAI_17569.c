//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

pthread_t threads[NUM_THREADS];
int thread_ids[NUM_THREADS];
int sum = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *calculate_sum(void *arg) {
    int tid = *((int*)arg);
    int start = (tid * 100) + 1;
    int end = start + 99;
    int local_sum = 0;

    for(int i=start; i<=end; i++) {
        local_sum += i;
    }

    pthread_mutex_lock(&lock);
    sum += local_sum;
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main() {
    int rc, i;
    for(i=0; i<NUM_THREADS; i++) {
        thread_ids[i] = i;
        rc = pthread_create(&threads[i], NULL, calculate_sum, &thread_ids[i]);
        if (rc) {
            fprintf(stderr, "Error creating thread %d\n", rc);
            exit(-1);
        }
    }

    for(i=0; i<NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if(rc) {
            fprintf(stderr, "Error joining thread %d\n", rc);
            exit(-1);
        }
    }

    printf("Total sum = %d\n", sum);
    pthread_mutex_destroy(&lock);

    return 0;
}