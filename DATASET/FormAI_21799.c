//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXIMUM_SPEED 100
#define TURN_SPEED 50
#define ACCELERATION 10
#define DECELERATION 20
#define STEERING_ANGLE 30

void simulateEngine(int speed, int distance) {
    printf("Simulation - Engine\n");
    printf("Accelerating...\n");
    for (int i = speed; i <= MAXIMUM_SPEED; i += ACCELERATION) {
        usleep(50000);
        printf("Speed: %dkm/h\n", i);
        if (i % TURN_SPEED == 0) {
            printf("Turning right...\n");
            usleep(1000000);
        }
    }
    printf("Maximum speed reached.\n");
    usleep(1000000);
    printf("Decelerating...\n");
    for (int i = MAXIMUM_SPEED; i > 0; i -= DECELERATION) {
        usleep(50000);
        printf("Speed: %dkm/h\n", i);
        if (i % TURN_SPEED == 0) {
            printf("Turning left...\n");
            usleep(1000000);
        }
    }
    printf("Vehicle stopped.\n");
    printf("Distance traveled: %dkm.\n", distance);
}

void simulateSteering(int angle) {
    printf("Simulation - Steering\n");
    if (angle > STEERING_ANGLE) {
        printf("Turning right...\n");
        for (int i = 0; i <= angle; i += STEERING_ANGLE) {
            usleep(1000000);
            printf("Steering angle: %d degrees\n", i);
        }
    } else if (angle < -STEERING_ANGLE) {
        printf("Turning left...\n");
        for (int i = 0; i >= angle; i -= STEERING_ANGLE) {
            usleep(1000000);
            printf("Steering angle: %d degrees\n", i);
        }
    } else {
        printf("Vehicle is driving straight ahead.\n");
    }
}

int main() {
    printf("Welcome to Vehicle Simulation Program\n");
    printf("Setting Vehicle parameters...\n");
    int speed = 40, distance = 50, angle = -45;
    printf("Speed: %dkm/h\n", speed);
    printf("Distance: %dkm\n", distance);
    printf("Steering angle: %d degrees\n", angle);
    printf("Starting simulation...\n");
    simulateEngine(speed, distance);
    simulateSteering(angle);
    return 0;
}