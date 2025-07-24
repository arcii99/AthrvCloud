//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scalable
#include <stdio.h>

// Define the possible commands for the remote control vehicle
typedef enum {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP,
} Command;

// Define the current state of the vehicle
typedef struct {
    int x; // x-coordinate of the vehicle's position
    int y; // y-coordinate of the vehicle's position
    int heading; // direction in which the vehicle is facing (in degrees)
} State;

// Helper function to move the vehicle based on a given command
void moveVehicle(State* state, Command command) {
    switch (command) {
        case FORWARD:
            state->x += 1;
            break;
        case BACKWARD:
            state->x -= 1;
            break;
        case LEFT:
            state->heading = (state->heading - 90) % 360;
            break;
        case RIGHT:
            state->heading = (state->heading + 90) % 360;
            break;
        case STOP:
            break;
        default:
            printf("Invalid command\n");
            break;
    }
}

int main() {
    State state = {0, 0, 0}; // initialize the vehicle state at (0, 0) facing north (0 degrees)

    // display the initial state
    printf("Vehicle position: (%d, %d)\n", state.x, state.y);
    printf("Vehicle heading: %d degrees\n", state.heading);

    // simulate some commands
    Command commands[] = {FORWARD, FORWARD, LEFT, FORWARD, RIGHT};
    int numCommands = sizeof(commands) / sizeof(Command);

    for (int i = 0; i < numCommands; i++) {
        moveVehicle(&state, commands[i]);
        printf("Executed command %d\n", i+1);
        printf("Vehicle position: (%d, %d)\n", state.x, state.y);
        printf("Vehicle heading: %d degrees\n", state.heading);
    }

    return 0;
}