//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 4

int main() {
    pthread_t threads[NUM_THREADS];

    // thread function to drive the vehicle forward
    void *drive_forward(void *arg) {
        int distance = *(int *)arg;
        printf("Driving forward for %d meters\n", distance);
        sleep(distance); // simulate driving
        printf("Vehicle has reached destination!\n");
        pthread_exit(NULL);
    }

    // thread function to reverse the vehicle
    void *reverse(void *arg) {
        int distance = *(int *)arg;
        printf("Reversing for %d meters\n", distance);
        sleep(distance); // simulate reversing
        printf("Vehicle has reached destination!\n");
        pthread_exit(NULL);
    }

    // thread function to turn left
    void *turn_left(void *arg) {
        int degrees = *(int *)arg;
        printf("Turning left by %d degrees\n", degrees);
        sleep(1); // simulate turning
        printf("Vehicle has turned left!\n");
        pthread_exit(NULL);
    }

    // thread function to turn right
    void *turn_right(void *arg) {
        int degrees = *(int *)arg;
        printf("Turning right by %d degrees\n", degrees);
        sleep(1); // simulate turning
        printf("Vehicle has turned right!\n");
        pthread_exit(NULL);
    }

    int distance, degrees;

    // create threads for each movement command
    pthread_create(&threads[0], NULL, drive_forward, (void *)&distance);
    pthread_create(&threads[1], NULL, turn_left, (void *)&degrees);
    pthread_create(&threads[2], NULL, reverse, (void *)&distance);
    pthread_create(&threads[3], NULL, turn_right, (void *)&degrees);

    // join threads to wait for them to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}