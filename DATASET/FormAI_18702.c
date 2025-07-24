//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

int x = 0, y = 0;

void *droneController(void *threadid) {
    long tid;
    tid = (long)threadid;
    
    if (tid == 1) {
        /* Roll Control */
        while (1) {
            printf("Current roll: %d\n", x);
        }
    } else if (tid == 2) {
        /* Pitch Control */
        while (1) {
            printf("Current pitch: %d\n", y);
        }
    } else if (tid == 3) {
        /* Yaw Control */
        while (1) {
            /* Read input from remote */
        }
    } else if (tid == 4) {
        /* Throttle Control */
        while (1) {
            /* Read input from remote */
        }
    }
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    
    rc = pthread_create(&threads[0], NULL, droneController, (void*)1);
    rc = pthread_create(&threads[1], NULL, droneController, (void*)2);
    rc = pthread_create(&threads[2], NULL, droneController, (void*)3);
    rc = pthread_create(&threads[3], NULL, droneController, (void*)4);
    
    pthread_exit(NULL);
}