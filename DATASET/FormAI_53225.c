//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining Struct for Vehicle State
typedef struct VehicleState {
    int xPos;
    int yPos;
    char direction[10];
} VehicleState;

// Enum to represent directions
enum Direction {
    North = 0,
    East,
    South,
    West
};

// Function to update the direction of the vehicle
int updateDirection(VehicleState *vehicle, int direction) {
    switch(direction) {
        case North:
            strncpy(vehicle->direction, "North", sizeof(vehicle->direction));
            break;
        case East:
            strncpy(vehicle->direction, "East", sizeof(vehicle->direction));
            break;
        case South:
            strncpy(vehicle->direction, "South", sizeof(vehicle->direction));
            break;
        case West:
            strncpy(vehicle->direction, "West", sizeof(vehicle->direction));
            break;
        default:
            return -1; // Invalid direction
    }
    return 0; // Success
}

// Function to print the current state of the vehicle
void printState(VehicleState *vehicle) {
    printf("Current State:\n");
    printf("Position: (%d, %d)\n", vehicle->xPos, vehicle->yPos);
    printf("Direction: %s\n", vehicle->direction);
    printf("------------------------------------------\n");
}

int main() {
    // Initial Vehicle Configuration
    VehicleState vehicle;
    vehicle.xPos = 0;
    vehicle.yPos = 0;
    strncpy(vehicle.direction, "North", sizeof(vehicle.direction));

    // Getting User Input for Vehicle Movement
    char input[100];
    printf("Welcome to Remote Control Vehicle Simulation!\n");
    printf("Type 'quit' to exit.\n");
    while(1) {
        printf("Enter commands ('f' for forward, 'b' for backward, 'l' for left, 'r' for right): ");
        fgets(input, 100, stdin);

        // Remove trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Check if user wants to quit
        if(strcmp(input, "quit") == 0) {
            printf("Exiting...\n");
            break;
        }

        // Parsing User Input for Movement Instructions
        for(int i = 0; i < strlen(input); i++) {
            switch(input[i]) {
                case 'f':
                    if(strcmp(vehicle.direction, "North") == 0) {
                        vehicle.yPos++;
                    } else if(strcmp(vehicle.direction, "East") == 0) {
                        vehicle.xPos++;
                    } else if(strcmp(vehicle.direction, "South") == 0) {
                        vehicle.yPos--;
                    } else if(strcmp(vehicle.direction, "West") == 0) {
                        vehicle.xPos--;
                    }
                    break;
                case 'b':
                    if(strcmp(vehicle.direction, "North") == 0) {
                        vehicle.yPos--;
                    } else if(strcmp(vehicle.direction, "East") == 0) {
                        vehicle.xPos--;
                    } else if(strcmp(vehicle.direction, "South") == 0) {
                        vehicle.yPos++;
                    } else if(strcmp(vehicle.direction, "West") == 0) {
                        vehicle.xPos++;
                    }
                    break;
                case 'l':
                    if(strcmp(vehicle.direction, "North") == 0) {
                        if(updateDirection(&vehicle, West) == 0) {
                            continue;
                        }
                    } else if(strcmp(vehicle.direction, "East") == 0) {
                        if(updateDirection(&vehicle, North) == 0) {
                            continue;
                        }
                    } else if(strcmp(vehicle.direction, "South") == 0) {
                        if(updateDirection(&vehicle, East) == 0) {
                            continue;
                        }
                    } else if(strcmp(vehicle.direction, "West") == 0) {
                        if(updateDirection(&vehicle, South) == 0) {
                            continue;
                        }
                    }
                    printf("Invalid Direction!\n");
                    break;
                case 'r':
                    if(strcmp(vehicle.direction, "North") == 0) {
                        if(updateDirection(&vehicle, East) == 0) {
                            continue;
                        }
                    } else if(strcmp(vehicle.direction, "East") == 0) {
                        if(updateDirection(&vehicle, South) == 0) {
                            continue;
                        }
                    } else if(strcmp(vehicle.direction, "South") == 0) {
                        if(updateDirection(&vehicle, West) == 0) {
                            continue;
                        }
                    } else if(strcmp(vehicle.direction, "West") == 0) {
                        if(updateDirection(&vehicle, North) == 0) {
                            continue;
                        }
                    }
                    printf("Invalid Direction!\n");
                    break;
                default:
                    printf("Invalid Command!\n");
                    break;
            }
        }
        printState(&vehicle);
    }

    return 0;
}