//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define NUM_THREADS 5
#define MAX_VALUE 10

int arr[MAX_VALUE];

// Function to print a thread's assigned values
void *printThreadValues(void *threadId) {
    int id = (int) threadId;
    printf("Thread %d has values: ", id);
    for (int i = id; i < MAX_VALUE; i += NUM_THREADS) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Assign values to array
    for (int i = 0; i < MAX_VALUE; i++) {
        arr[i] = i;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        int rc = pthread_create(&threads[i], NULL, printThreadValues, (void *) i);
        if (rc) {
            printf("Error creating thread: %d\n", rc);
            exit(-1);
        }
    }

    // Wait for threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads completed.\n");

    return 0;
}