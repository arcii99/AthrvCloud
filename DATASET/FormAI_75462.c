//FormAI DATASET v1.0 Category: Smart home light control ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 3

int light_state = 0; // 0 for off, 1 for on
pthread_mutex_t mutex;

void *change_light_state(void *thread_id) {
    int tid = *((int*) thread_id);
    while (1) {
        pthread_mutex_lock(&mutex); // lock mutex to modify shared variable
        if (tid == 0) { // Thread 0 handles turning on/off the light
            if (light_state == 0) {
                printf("Turn on the light\n");
                light_state = 1;
            } else {
                printf("Turn off the light\n");
                light_state = 0;
            }
        } else if (tid == 1) { // Thread 1 handles increasing brightness
            if (light_state == 1) {
                printf("Increase brightness\n");
                // code to increase brightness goes here
            }
        } else if (tid == 2) { // Thread 2 handles decreasing brightness
            if (light_state == 1) {
                printf("Decrease brightness\n");
                // code to decrease brightness goes here
            }
        }
        pthread_mutex_unlock(&mutex); // unlock mutex
        sleep(2); // delay for 2 seconds before next modification
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, id[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL); // initialize the mutex

    for (i = 0; i < NUM_THREADS; i++) {
        id[i] = i;
        pthread_create(&threads[i], NULL, change_light_state, (void *) &id[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex); // destroy the mutex
    pthread_exit(NULL);
}