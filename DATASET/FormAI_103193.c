//FormAI DATASET v1.0 Category: Date and time ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 2

void *print_current_time(void *thread_id) {
    long tid = (long)thread_id;
    time_t raw_time;
    struct tm * time_info;
    char buffer[80];

    // Get current time
    time(&raw_time);
    time_info = localtime(&raw_time);
    strftime(buffer, 80, "Thread %ld: The current time is %I:%M:%S %p.", time_info);

    // Print current time
    printf("%s\n", buffer);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Create threads
    for(t = 0; t < NUM_THREADS; t++) {
        printf("Creating thread %ld...\n", t);
        rc = pthread_create(&threads[t], NULL, print_current_time, (void *)t);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for threads to finish
    for(t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    pthread_exit(NULL);
}