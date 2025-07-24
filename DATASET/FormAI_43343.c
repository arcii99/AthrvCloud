//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for maximum speed and steering angle
#define MAX_SPEED 100
#define MAX_STEER_ANGLE 30

// define struct for the vehicle state
typedef struct {
    int speed;
    int steer_angle;
} VehicleState;

// function to simulate the remote control vehicle
void simulate_vehicle(VehicleState* state) {
    int command;
    do {
        printf("\nSpeed: %d\nSteering Angle: %d\n\n", state->speed, state->steer_angle);
        printf("Enter command (0 to quit):\n");
        printf("1. Increase speed\n");
        printf("2. Decrease speed\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        scanf("%d", &command);
        switch (command) {
            case 1:
                state->speed = state->speed < MAX_SPEED ? state->speed + 10 : MAX_SPEED;
                break;
            case 2:
                state->speed = state->speed > 0 ? state->speed - 10 : 0;
                break;
            case 3:
                state->steer_angle = state->steer_angle > -MAX_STEER_ANGLE ? state->steer_angle - 5 : -MAX_STEER_ANGLE;
                break;
            case 4:
                state->steer_angle = state->steer_angle < MAX_STEER_ANGLE ? state->steer_angle + 5 : MAX_STEER_ANGLE;
                break;
        }
    } while (command != 0);
}

int main() {
    srand(time(NULL));
    VehicleState state = {0, 0};
    simulate_vehicle(&state);
    return 0;
}