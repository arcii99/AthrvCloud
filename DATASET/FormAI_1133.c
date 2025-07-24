//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include <stdio.h>

// Define the command codes for the drone remote control
#define TAKE_OFF 1
#define LAND 2
#define HOVER 3
#define FORWARD 4
#define BACKWARD 5
#define LEFT 6
#define RIGHT 7
#define UP 8
#define DOWN 9

// Define a struct to hold the drone's current state
typedef struct {
    int x; // horizontal position in meters
    int y; // vertical position in meters
    int z; // depth position in meters
    int speed; // speed in kph
} DroneState;

// Define a struct to hold a command for the drone
typedef struct {
    int code; // command code
    int parameter; // command parameter (distance, speed, etc.)
} DroneCommand;

// Define a struct to hold the response from the drone
typedef struct {
    int status; // status code (success or failure)
    int message; // error message or confirmation message
} DroneResponse;

// Define the function to send a command to the drone
DroneResponse sendCommand(DroneCommand command, DroneState* state) {

    // Initialize the response object
    DroneResponse response;
    response.status = 0;
    response.message = 0;

    // Handle each command code
    switch (command.code) {
        case TAKE_OFF:
            response.status = 1;
            response.message = "Drone took off.";
            break;
            
        case LAND:
            response.status = 1;
            response.message = "Drone landed.";
            break;
            
        case HOVER:
            response.status = 1;
            response.message = "Drone is hovering.";
            break;
            
        case FORWARD:
            state->x += command.parameter;
            response.status = 1;
            response.message = "Drone moved forward.";
            break;
            
        case BACKWARD:
            state->x -= command.parameter;
            response.status = 1;
            response.message = "Drone moved backward.";
            break;
            
        case LEFT:
            state->y -= command.parameter;
            response.status = 1;
            response.message = "Drone moved left.";
            break;
            
        case RIGHT:
            state->y += command.parameter;
            response.status = 1;
            response.message = "Drone moved right.";
            break;
            
        case UP:
            state->z += command.parameter;
            response.status = 1;
            response.message = "Drone moved up.";
            break;
            
        case DOWN:
            state->z -= command.parameter;
            response.status = 1;
            response.message = "Drone moved down.";
            break;
            
        default:
            response.status = 0;
            response.message = "Invalid command.";
            break;
    }

    // Return the response object
    return response;
}

int main() {
    DroneState state;
    state.x = 0;
    state.y = 0;
    state.z = 0;
    state.speed = 0;

    DroneCommand command;
    
    command.code = TAKE_OFF;
    command.parameter = 0;
    DroneResponse response = sendCommand(command, &state);
    printf("%s\n", response.message);
    
    command.code = FORWARD;
    command.parameter = 50;
    response = sendCommand(command, &state);
    printf("%s\n", response.message);
    
    command.code = RIGHT;
    command.parameter = 20;
    response = sendCommand(command, &state);
    printf("%s\n", response.message);
    
    command.code = HOVER;
    command.parameter = 0;
    response = sendCommand(command, &state);
    printf("%s\n", response.message);
    
    command.code = LAND;
    command.parameter = 0;
    response = sendCommand(command, &state);
    printf("%s\n", response.message);

    return 0;
}