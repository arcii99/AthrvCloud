//FormAI DATASET v1.0 Category: Arithmetic ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 4       // Number of threads to be created
#define BUFFER_SIZE 10      // Size of buffer

int buffer[BUFFER_SIZE];    // Shared buffer
int buffer_pos = 0;         // Position of buffer
pthread_mutex_t lock;       // Mutex lock for critical sections

// Function to produce an item into buffer
void *produce_item(void *args) {
    int item;
    while(1) {
        item = rand() % 100;    // Generate a random item to be produced
        pthread_mutex_lock(&lock);
        if(buffer_pos < BUFFER_SIZE) {
            buffer[buffer_pos++] = item;
            printf("Produced Item = %d\n", item);
        }
        pthread_mutex_unlock(&lock);
        if(buffer_pos == BUFFER_SIZE) {
            printf("Buffer is full!\n");
        }
        // Sleep for a random time
        sleep(rand() % 3);
    }
    pthread_exit(NULL);
}

// Function to consume an item from buffer
void *consume_item(void *args) {
    int item;
    while(1) {
        pthread_mutex_lock(&lock);
        if(buffer_pos > 0) {
            item = buffer[--buffer_pos];
            printf("Consumed Item = %d\n", item);
        }
        pthread_mutex_unlock(&lock);
        if(buffer_pos == 0) {
            printf("Buffer is empty!\n");
        }
        // Sleep for a random time
        sleep(rand() % 3);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];    // Array of threads
    int rc;
    long t;

    // Create producer threads
    for(t = 0; t < NUM_THREADS/2; t++) {
        rc = pthread_create(&threads[t], NULL, produce_item, (void *)t);
        if(rc) {
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Create consumer threads
    for(t = NUM_THREADS/2; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, consume_item, (void *)t);
        if(rc) {
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish
    for(t = 0; t < NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if(rc) {
            printf("ERROR: Return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
    }

    pthread_mutex_destroy(&lock);   // Destroy mutex lock
    pthread_exit(NULL);
}