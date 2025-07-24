//FormAI DATASET v1.0 Category: Game ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 100000

int arr[ARRAY_SIZE];

void *sum(void *thread_id) {
    int i;
    long tid;
    long sum = 0;

    tid = (long) thread_id;

    for (i = tid * (ARRAY_SIZE / NUM_THREADS); i < (tid + 1) * (ARRAY_SIZE / NUM_THREADS); i++) {
        sum += arr[i];
    }

    pthread_exit((void *) sum);
}

void generate_array() {
    int i;

    for (i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = i;
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, rc;
    long t;
    void *status;
    long total_sum = 0;

    generate_array();

    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, sum, (void *) t);
        
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], &status);
        
        if (rc) {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        
        total_sum += (long) status;
    }

    printf("The sum of the array is %ld\n", total_sum);

    pthread_exit(NULL);
}