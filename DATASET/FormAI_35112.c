//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 5

// Function to simulate receiving signal strength from a Wi-Fi network
int getSignalStrength() {
    return rand() % 101; // Returns a random signal strength between 0 and 100
}

// Thread function to continuously monitor and print the signal strength
void *monitorSignalStrength(void *threadID) {
    int threadId = (int)threadID;
    printf("Thread%d: Monitoring signal strength...\n", threadId);
    while(1) {
        int signalStrength = getSignalStrength();
        printf("Thread%d: Signal Strength: %d%%\n", threadId, signalStrength);
        usleep(2000000); // Wait for 2 seconds before checking signal strength again
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;

    // Create threads to monitor signal strength
    for(int i = 0; i < NUM_THREADS; i++) {
        printf("Main: Creating thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, monitorSignalStrength, (void *)i);
        if(rc) {
            printf("Error: Unable to create thread %d\n", i);
            exit(-1);
        }
    }
    pthread_exit(NULL);
    return 0;
}