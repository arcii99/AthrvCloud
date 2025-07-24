//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main() {
    int speed, direction; // variables to store speed and direction of the remote control vehicle
    printf("Welcome to the Remote Control Vehicle Simulator!\n");
    printf("Please enter the speed of the vehicle (0-10): ");
    scanf("%d", &speed);
    printf("Please enter the direction of the vehicle (0-359): ");
    scanf("%d", &direction);

    // checking if the input is valid
    if (speed < 0 || speed > 10 || direction < 0 || direction > 359) {
        printf("Invalid input. Speed should be between 0 and 10, and direction should be between 0 and 359.\n");
        exit(0);
    }

    // display the status of the vehicle
    printf("Vehicle status:\nSpeed: %d\nDirection: %d\n", speed, direction);

    // simulate the movement of the vehicle
    for (int i = 0; i < 10; i++) {
        // randomly change the speed and direction of the vehicle
        int new_speed = rand() % 11;
        int new_direction = rand() % 360;

        // display the updated status of the vehicle
        printf("\nVehicle status after %d seconds:\nNew speed: %d\nNew direction: %d\n", i+1, new_speed, new_direction);

        // check if the vehicle has crashed
        if (new_speed == 0 && direction != new_direction) {
            printf("!!!CRASH!!!\n");
            break;
        }

        // update the speed and direction of the vehicle
        speed = new_speed;
        direction = new_direction;
    }

    // display the final status of the vehicle
    printf("\nFinal vehicle status:\nSpeed: %d\nDirection: %d\n", speed, direction);

    return 0;
}