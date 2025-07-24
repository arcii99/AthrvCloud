//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: introspective
#include <stdio.h>

// Initialize drone controller struct
typedef struct {
    int batteryLevel;
    int height;
    int forwardSpeed;
    int sideSpeed;
    int rotationSpeed;
} DroneController;

// Function to print current drone controller state
void printDroneControllerState(DroneController droneController) {
    printf("Battery Level: %d %%\n", droneController.batteryLevel);
    printf("Height: %d meters\n", droneController.height);
    printf("Forward Speed: %d m/s\n", droneController.forwardSpeed);
    printf("Side Speed: %d m/s\n", droneController.sideSpeed);
    printf("Rotation Speed: %d deg/s\n", droneController.rotationSpeed);
}

int main() {
    // Create and initialize drone controller
    DroneController droneController = {100, 0, 0, 0, 0}; // 100% battery, 0m height, 0m/s speed, 0deg/s rotation

    // Print initial state
    printf("Initial State:\n");
    printDroneControllerState(droneController);

    // User input loop
    char input;
    do {
        printf("\nEnter command ('w'=forward, 'a'=left, 's'=backward, 'd'=right, 'e'=rotate, 'q'=land): ");
        input = getchar();

        // Process command
        switch (input) {
            case 'w':
                droneController.forwardSpeed += 2;
                printf("Moving Forward\n");
                break;

            case 'a':
                droneController.sideSpeed -= 2;
                printf("Moving Left\n");
                break;

            case 's':
                droneController.forwardSpeed -= 2;
                printf("Moving Backward\n");
                break;

            case 'd':
                droneController.sideSpeed += 2;
                printf("Moving Right\n");
                break;

            case 'e':
                droneController.rotationSpeed += 5;
                printf("Rotating Right\n");
                break;

            case 'q':
                droneController.height = 0;
                printf("Landing...\n");
                break;

            default:
                printf("Invalid command.\n");
                break;
        }

        // Update drone controller state
        droneController.batteryLevel -= 1; // Battery decreases with each command
        droneController.height += (droneController.forwardSpeed / 2); // Height increases with forward speed
        droneController.sideSpeed *= 0.7; // Side speed decreases over time
        droneController.rotationSpeed *= 0.9; // Rotation speed decreases over time
        
        // Print updated state
        printf("Updated State:\n");
        printDroneControllerState(droneController);
    } while (input != 'q');
    
    return 0;
}