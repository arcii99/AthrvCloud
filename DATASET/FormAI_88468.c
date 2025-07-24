//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

typedef struct {
    double latitude;
    double longitude;
} Location;

Location current_location = {51.5074, 0.1278};

void *navigation_thread(void *thread_id) {
    int tid = *(int*)thread_id;
    printf("Navigation Thread #%d starting...\n", tid);

    while(1) {
        Location destination = {rand()%90, rand()%180};
        printf("Thread #%d: Navigating from (%.4f, %.4f) to (%.4f, %.4f)\n", 
            tid, current_location.latitude, current_location.longitude,
            destination.latitude, destination.longitude);
        
        // Simulating navigation by sleeping for a random time
        sleep(rand()%5 + 1);
        
        // Updating current location
        current_location = destination;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];
    int i;

    printf("Starting GPS navigation simulation...\n");

    for(i=0; i<NUM_THREADS; i++) {
        thread_ids[i] = i;
        int rc = pthread_create(&threads[i], NULL, navigation_thread, (void*)&thread_ids[i]);
        if (rc) {
            printf("ERROR: Unable to create thread #%d\n", i);
            exit(-1);
        }
    }

    pthread_exit(NULL);
    return 0;
}