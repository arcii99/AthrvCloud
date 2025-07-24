//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: secure
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lock to protect shared resource
pthread_mutex_t lock;

// Shared resource
int count = 0;

// Thread function to increment the count
void *increment_count(void *arg) {
    int i;
    for (i = 0; i < 1000000; i++) {
        // Acquire lock to access shared resource
        pthread_mutex_lock(&lock);
        count++;
        // Release lock
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

    // Initialize lock for shared resource
    if (pthread_mutex_init(&lock, NULL) != 0) {
        fprintf(stderr, "Error initializing lock\n");
        exit(EXIT_FAILURE);
    }

    // Create threads
    pthread_t thread1, thread2;
    if (pthread_create(&thread1, NULL, increment_count, NULL) != 0) {
        fprintf(stderr, "Error creating thread1\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&thread2, NULL, increment_count, NULL) != 0) {
        fprintf(stderr, "Error creating thread2\n");
        exit(EXIT_FAILURE);
    }

    // Wait for threads to complete
    if (pthread_join(thread1, NULL) != 0) {
        fprintf(stderr, "Error joining thread1\n");
        exit(EXIT_FAILURE);
    }
    if (pthread_join(thread2, NULL) != 0) {
        fprintf(stderr, "Error joining thread2\n");
        exit(EXIT_FAILURE);
    }

    // Destroy lock
    if (pthread_mutex_destroy(&lock) != 0) {
        fprintf(stderr, "Error destroying lock\n");
        exit(EXIT_FAILURE);
    }

    // Print final count
    printf("Final count: %d\n", count);

    return 0;
}