//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 5

void *test_speed(void *id);

int main() {
    pthread_t threads[NUM_THREADS];
    int i, status;

    srand(time(NULL)); // seed random number generator

    for (i = 0; i < NUM_THREADS; i++) {
        status = pthread_create(&threads[i], NULL, test_speed, (void *)i);
        if (status) {
            printf("Error: pthread_create returned status code %d", status);
            exit(-1);
        }
    }

    printf("All tests started successfully.\n");

    // wait for all threads to finish before exiting
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All tests completed.\n");

    return 0;
}

void *test_speed(void *id) {
    int thread_id = (int) id;
    int speed = 0;

    printf("Thread %d started.\n", thread_id);
    // simulate a speed test by generating a random number between 1 and 1000
    speed = (rand() % 1000) + 1;
    printf("Thread %d finished with speed %d Mbps.\n", thread_id, speed);

    pthread_exit(NULL);
}