//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SPEED 10 // Maximum speed of the vehicle
#define MAX_ANGLE 180 // Maximum angle of the vehicle's steering

// Function to simulate the movement of the vehicle
void moveVehicle(int speed, int angle, bool isMovingForward) {
    printf("Vehicle is moving at speed %d with steering angle %d ", speed, angle);
    if (isMovingForward) {
        printf("forward.\n");
    } else {
        printf("backward.\n");
    }
}

int main() {
    srand(time(0));
    int speed = 0;
    int angle = 0;
    bool isMovingForward = true;
    bool isButtonPressed = false;
    
    printf("Remote Control Vehicle Simulation Program\n");

    while (true) {
        // Check if button is pressed
        if (isButtonPressed) {
            printf("Button is pressed, stopping the vehicle.\n");
            speed = 0;
            angle = 0;
            isMovingForward = true;
            isButtonPressed = false;
        }

        // Generate random speed and angle
        speed = rand() % (MAX_SPEED + 1);
        angle = rand() % (MAX_ANGLE + 1);

        // Generate random forward/backward movement
        isMovingForward = (rand() % 2) == 0 ? true : false;

        // Move the vehicle
        moveVehicle(speed, angle, isMovingForward);

        // Delay for 1 second to simulate real-time movement
        printf("---------------\n");
        sleep(1); 
    }

    return 0;
}