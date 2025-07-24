//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>

// Function to simulate the remote control vehicle
void simulateRemoteControlVehicle(int remoteControl) {
    int speed = 0;
    int direction = 0;

    switch (remoteControl) {
        case 0:
            printf("Vehicle stopped.\n");
            speed = 0;
            direction = 0;
            break;

        case 1:
            printf("Vehicle moving forward.\n");
            speed = 50;
            direction = 0;
            break;

        case 2:
            printf("Vehicle moving backward.\n");
            speed = 50;
            direction = 180;
            break;

        case 3:
            printf("Vehicle turning left.\n");
            speed = 50;
            direction = -90;
            break;

        case 4:
            printf("Vehicle turning right.\n");
            speed = 50;
            direction = 90;
            break;

        default:
            printf("Invalid remote control command.\n");
    }

    printf("Current speed: %d\n", speed);
    printf("Current direction: %d degrees\n", direction);
}

int main() {
    printf("Remote control vehicle simulation program.\n\n");

    // Simulating the vehicle movement
    int remoteControl = 1;
    simulateRemoteControlVehicle(remoteControl);

    remoteControl = 4;
    simulateRemoteControlVehicle(remoteControl);

    remoteControl = 2;
    simulateRemoteControlVehicle(remoteControl);

    remoteControl = 5;
    simulateRemoteControlVehicle(remoteControl);

    return 0;
}