//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define ARRAY_SIZE 10

int a[ARRAY_SIZE] = {9, 7, 5, 3, 1, 8, 6, 4, 2, 0}; // input array
int sum = 0; // sum of all thread results

// thread function for calculating the sum of a portion of the array
void *calc_sum(void *thread_idx) {
    int idx = (int) thread_idx;
    int start = idx * (ARRAY_SIZE / NUM_THREADS);
    int end = (idx + 1) * (ARRAY_SIZE / NUM_THREADS);
    int max = a[start]; // for greedy selection
    int result = max;
    
    for (int i = start + 1; i < end; i++) {
        if (a[i] > max) {
            max = a[i];
            result += max;
        }
    }
    
    printf("Thread %d calculates result %d from index %d to %d\n", idx, result, start, end - 1);
    sum += result; // add thread result to sum
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // create threads
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, calc_sum, (void*)t);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(1);
        }
    }

    // join threads
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR: return code from pthread_join() is %d\n", rc);
            exit(1);
        }
    }
    
    printf("The maximum sum of consecutive numbers is %d\n", sum);

    pthread_exit(NULL);
}