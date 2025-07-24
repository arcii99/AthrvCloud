//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

// Define the thread struct here
typedef struct thread_data {
    int thread_id;
    int sum;
    int num_iterations;
} thread_data_t;

// Define the thread function here
void *find_sum(void *threadarg) {
    thread_data_t *thread_data = (thread_data_t *) threadarg;
    int start = thread_data->thread_id * thread_data->num_iterations + 1;
    int end = start + thread_data->num_iterations - 1;
    int i;

    for (i = start; i <= end; i++) {
        thread_data->sum += i;
    }

    pthread_exit(NULL);
}

// Main function
int main(int argc, char *argv[]) {
    pthread_t threads[NUM_THREADS];
    thread_data_t thread_data[NUM_THREADS];

    int i, rc;
    int num_iterations = 100000;
    int total_sum = 0;

    // Create threads and initialize thread data
    for (i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].sum = 0;
        thread_data[i].num_iterations = num_iterations;

        rc = pthread_create(&threads[i], NULL, find_sum, (void *) &thread_data[i]);
        if (rc) {
            printf("Error creating thread %d\n", i);
            exit(-1);
        }
    }

    // Wait for threads to finish and get their partial sums
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error joining thread %d\n", i);
            exit(-1);
        }

        total_sum += thread_data[i].sum;
    }

    printf("The sum from 1 to %d is %d\n", NUM_THREADS * num_iterations, total_sum);

    pthread_exit(NULL);
}