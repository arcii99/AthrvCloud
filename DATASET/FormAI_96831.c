//FormAI DATASET v1.0 Category: System boot optimizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

void *optimizeBoot(void *threadID) {
    int id = *((int*) threadID);
    printf("Thread %d - optimizing boot...\n", id);
    sleep(2); // Simulates boot optimization
    printf("Thread %d - boot optimization completed!\n", id);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];
    int rc, t;

    printf("Welcome to the C System Boot Optimizer!\n");
    printf("Optimizing boot will now begin...\n");

    for (t = 0; t < NUM_THREADS; t++) {
        threadIDs[t] = t;
        rc = pthread_create(&threads[t], NULL, optimizeBoot, (void*) &threadIDs[t]);
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }

    // Wait for all threads to finish
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    printf("All threads have completed boot optimization.\n");
    printf("Optimizing boot process complete. Your system is now ready!\n");

    pthread_exit(NULL);
}