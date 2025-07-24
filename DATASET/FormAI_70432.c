//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdbool.h>

// Function to get user input
void getCommand(char *input, int size) {
    printf("Enter your command: ");
    fgets(input, size, stdin);
}

int main() {
    printf("Welcome to C Drone Remote Control!\n");

    bool powerOn = false;
    bool isFlying = false;
    float altitude = 0.0;
    float pitch = 0.0;
    float roll = 0.0;
    float yaw = 0.0;
    char command[50];

    while (true) {
        printf("\nCurrent status:\n");
        printf("Power: %s\n", powerOn ? "on" : "off");
        printf("Flight Status: %s\n", isFlying ? "in air" : "on ground");
        printf("Altitude: %.2f meters\n", altitude);
        printf("Pitch: %.2f degrees\n", pitch);
        printf("Roll: %.2f degrees\n", roll);
        printf("Yaw: %.2f degrees\n", yaw);

        getCommand(command, 50);
        
        // Handling different commands
        if (strcmp(command, "power on\n") == 0) {
            printf("Powering on...\n");
            powerOn = true;
        } 
        else if (strcmp(command, "power off\n") == 0) {
            printf("Powering off...\n");
            powerOn = false;
            isFlying = false;
            altitude = 0;
            pitch = 0;
            roll = 0;
            yaw = 0;
        }
        else if (strcmp(command, "takeoff\n") == 0) {
            if (!powerOn) {
                printf("Cannot take off, power is off.\n");
            } else if (isFlying) {
                printf("Drone is already in air.\n");
            } else {
                printf("Taking off...\n");
                isFlying = true;
                altitude = 0.5;
            }
        }
        else if (strcmp(command, "land\n") == 0) {
            if (!isFlying) {
                printf("Drone is already on ground.\n");
            } else {
                printf("Landing...\n");
                isFlying = false;
                altitude = 0;
                pitch = 0;
                roll = 0;
                yaw = 0;
            }
        }
        else if (strcmp(command, "up\n") == 0) {
            if (!isFlying) {
                printf("Drone is not in air.\n");
            } else {
                printf("Moving up...\n");
                altitude += 0.5;
            }
        }
        else if (strcmp(command, "down\n") == 0) {
            if (!isFlying) {
                printf("Drone is not in air.\n");
            } else {
                printf("Moving down...\n");
                altitude -= 0.5;
            }
        }
        else if (strcmp(command, "forward\n") == 0) {
            if (!isFlying) {
                printf("Drone is not in air.\n");
            } else {
                printf("Moving forward...\n");
                pitch += 10;
            }
        }
        else if (strcmp(command, "backward\n") == 0) {
            if (!isFlying) {
                printf("Drone is not in air.\n");
            } else {
                printf("Moving backward...\n");
                pitch -= 10;
            }
        }
        else if (strcmp(command, "right\n") == 0) {
            if (!isFlying) {
                printf("Drone is not in air.\n");
            } else {
                printf("Moving right...\n");
                roll += 10;
            }
        }
        else if (strcmp(command, "left\n") == 0) {
            if (!isFlying) {
                printf("Drone is not in air.\n");
            } else {
                printf("Moving left...\n");
                roll -= 10;
            }
        }
        else if (strcmp(command, "rotate right\n") == 0) {
            if (!isFlying) {
                printf("Drone is not in air.\n");
            } else {
                printf("Rotating right...\n");
                yaw += 10;
            }
        }
        else if (strcmp(command, "rotate left\n") == 0) {
            if (!isFlying) {
                printf("Drone is not in air.\n");
            } else {
                printf("Rotating left...\n");
                yaw -= 10;
            }
        }
        else if (strcmp(command, "quit\n") == 0) {
            printf("Goodbye!\n");
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}