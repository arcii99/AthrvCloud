//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: genious
#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

// Function to print thread ID and message
void *print_message(void *thread_id) {
    long tid = (long)thread_id;
    printf("Thread ID %ld: Hello World!\n", tid);
    pthread_exit(NULL);
}

// Main function
int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Creating threads
    for(t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, print_message, (void *)t);
        if (rc) {
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            return -1;
        }
    }

    // Joining threads
    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
        printf("Thread %ld has joined\n", t);
    }

    pthread_exit(NULL);
    return 0;
}