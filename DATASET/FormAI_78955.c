//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

// Struct used to pass data to our threads
typedef struct {
    int id;
    char message[100];
} thread_data;

// Function that our threads will execute
void *thread_function(void *arg) {
    thread_data *data = (thread_data *)arg;
    printf("Thread %d: %s\n", data->id, data->message);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_data thread_data_array[NUM_THREADS];
    int rc;

    // Create threads
    for (int i=0; i<NUM_THREADS; i++) {
        thread_data data = { i, "Hello, from thread!" };
        thread_data_array[i] = data;
        rc = pthread_create(&threads[i], NULL, thread_function, (void *)&thread_data_array[i]);
        if (rc) {
            fprintf(stderr, "Error creating thread [%d]\n", rc);
            exit(1);
        }
    }

    // Wait for threads to finish and join them
    for (int i=0; i<NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            fprintf(stderr, "Error joining thread [%d]\n", rc);
            exit(1);
        }
    }

    printf("All threads finished.\n");

    return 0;
}