//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: interoperable
#include <stdio.h>

// Define some common constants
#define TURN_LEFT 1
#define TURN_RIGHT 2
#define FORWARD 3
#define BACKWARD 4
#define STOP 5

// Define the RemoteControlVehicle struct
typedef struct RemoteControlVehicle {
    int speed;
    int direction;
} RCVehicle;

// Function to control the RC vehicle
void controlVehicle(RCVehicle* vehicle, int action) {
    switch (action) {
        case TURN_LEFT:
            vehicle->direction -= 45;
            break;
        case TURN_RIGHT:
            vehicle->direction += 45;
            break;
        case FORWARD:
            vehicle->speed = 10;
            break;
        case BACKWARD:
            vehicle->speed = -10;
            break;
        case STOP:
            vehicle->speed = 0;
            break;
        default:
            printf("Invalid action!\n");
    }
}

// Function to simulate the movement of the RC vehicle
void simulateMovement(RCVehicle* vehicle) {
    if (vehicle->speed == 0) {
        printf("The RC vehicle is stopped.\n");
    } else {
        printf("The RC vehicle is moving %d units in direction %d.\n", vehicle->speed, vehicle->direction);
    }
}

int main() {
    // Initialize the RC vehicle
    RCVehicle myVehicle = {
        .speed = 0,
        .direction = 0
    };

    // Control the RC vehicle
    controlVehicle(&myVehicle, FORWARD);
    controlVehicle(&myVehicle, TURN_LEFT);
    controlVehicle(&myVehicle, BACKWARD);
    controlVehicle(&myVehicle, TURN_RIGHT);
    controlVehicle(&myVehicle, STOP);

    // Simulate the movement of the RC vehicle
    simulateMovement(&myVehicle);

    return 0;
}