//FormAI DATASET v1.0 Category: File Synchronizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 4
#define MAX_FILES 10

pthread_mutex_t sync_lock;
char available_files[MAX_FILES][50] = {"file1.txt", "file2.txt", "file3.txt", "file4.txt", "file5.txt", "file6.txt", "file7.txt", "file8.txt", "file9.txt", "file10.txt"};

void *SyncFiles(void *threadid) {
    long tid;
    tid = (long) threadid;
    
    // Lock the mutex while accessing the shared resources
    pthread_mutex_lock(&sync_lock);

    // Randomly select two files to sync from the available_files array
    int file1 = rand() % MAX_FILES;
    int file2 = rand() % MAX_FILES;
    while (file2 == file1) {
        file2 = rand() % MAX_FILES;
    }

    printf("Thread %ld is synchronizing %s with %s\n", tid, available_files[file1], available_files[file2]);
    // Simulate synchronization process
    sleep(1);

    // Unlock the mutex after accessing
    pthread_mutex_unlock(&sync_lock);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    // Initialize the mutex
    pthread_mutex_init(&sync_lock, NULL);

    // Seed the random number generator
    srand(time(NULL));

    // Create threads
    for (t = 0; t < NUM_THREADS; t++) {
        rc = pthread_create(&threads[t], NULL, SyncFiles, (void *) t);
        if (rc) {
            printf("ERROR: Return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&sync_lock);

    pthread_exit(NULL);
}