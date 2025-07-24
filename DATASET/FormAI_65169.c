//FormAI DATASET v1.0 Category: Searching algorithm ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 10000
#define NUM_THREADS 4

int array[ARRAY_SIZE];
int search_val = 500;

int found_flag[NUM_THREADS] = {0};
pthread_mutex_t lock;

void *linear_search(void *arg) {
    int thread_no = *(int*)arg;
    int start = thread_no * (ARRAY_SIZE / NUM_THREADS);
    int end = start + (ARRAY_SIZE / NUM_THREADS);

    for(int i=start; i<end; i++) {
        if(array[i] == search_val) {
            pthread_mutex_lock(&lock);
            found_flag[thread_no] = 1;
            pthread_mutex_unlock(&lock);
            pthread_exit(NULL);
        }
    }
    pthread_exit(NULL);
}

int main() {
    int i, rc;
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    // Initialize array
    for(i=0; i<ARRAY_SIZE; i++) {
        array[i] = i;
    }

    // Initialize mutex
    pthread_mutex_init(&lock, NULL);

    // Create threads
    for(i=0; i<NUM_THREADS; i++) {
        thread_args[i] = i;
        rc = pthread_create(&threads[i], NULL, linear_search, (void*)&thread_args[i]);
        if(rc != 0) {
            fprintf(stderr, "Error: pthread_create failed with status %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to finish
    for(i=0; i<NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Check if value was found 
    for(i=0; i<NUM_THREADS; i++) {
        if(found_flag[i]) {
            printf("Value found by thread %d\n", i);
            break;
        }
    }

    // Cleanup mutex
    pthread_mutex_destroy(&lock);

    return 0;
}