//FormAI DATASET v1.0 Category: Physics simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_t thread1, thread2;
double position = 0.0;
double velocity = 0.0;
double acceleration = 1.0;
int time_elapsed = 0;

void *simulate_position(void *arg) {
    while (1) {
        position = 0.5 * acceleration * time_elapsed * time_elapsed;
        time_elapsed++; // update the time elapsed
        usleep(10000); // wait for 10ms
    }
}

void *simulate_velocity(void *arg) {
    while (1) {
        velocity = acceleration * time_elapsed;
        usleep(10000); // wait for 10ms
    }
}

int main() {
    pthread_create(&thread1, NULL, simulate_position, NULL);
    pthread_create(&thread2, NULL, simulate_velocity, NULL);
    
    while (time_elapsed < 100) {
        printf("Time elapsed: %d, Position: %f, Velocity: %f\n", time_elapsed, position, velocity);
        usleep(50000); // wait for 50ms
    }
    
    pthread_cancel(thread1);
    pthread_cancel(thread2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}