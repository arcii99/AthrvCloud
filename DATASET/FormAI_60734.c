//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define STEERING_ANGLE 30
#define MAX_DISTANCE 100

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize vehicle status
    int speed = 0;
    int steering = 0;
    int distance = 0;

    // Simulator loop
    while (distance < MAX_DISTANCE) {
        // Generate random inputs
        int speed_input = rand() % (2*MAX_SPEED+1) - MAX_SPEED;
        int steering_input = rand() % (2*STEERING_ANGLE+1) - STEERING_ANGLE;

        // Update vehicle status
        speed += speed_input;
        steering += steering_input;
        if (speed < 0) {
            speed = 0;
        } else if (speed > MAX_SPEED) {
            speed = MAX_SPEED;
        }
        if (steering < -STEERING_ANGLE) {
            steering = -STEERING_ANGLE;
        } else if (steering > STEERING_ANGLE) {
            steering = STEERING_ANGLE;
        }
        distance += speed;

        // Print current status
        printf("Vehicle status: Speed=%d, Steering=%d, Distance=%d\n", speed, steering, distance);
    }

    printf("Vehicle simulation complete!\n");

    return 0;
}