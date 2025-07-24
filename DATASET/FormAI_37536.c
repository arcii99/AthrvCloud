//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to simulate the remote control vehicle
void rcVehicleSimulation(int x, int y, char dir[], int speed) {
    printf("Starting the RC vehicle simulation...\n");
    printf("Initial position: x = %d, y = %d, direction = %s, speed = %d\n", x, y, dir, speed);
    int distance = speed * 10; // Distance travelled in 1 second at this speed
    printf("Vehicle will travel %d units per second\n", distance);
    int remainingDistance = distance;
    while (remainingDistance > 0) {
        printf("Current position: x = %d, y = %d, direction = %s\n", x, y, dir);
        if (strcmp(dir, "North") == 0) {
            y = y + remainingDistance;
        } else if (strcmp(dir, "East") == 0) {
            x = x + remainingDistance;
        } else if (strcmp(dir, "South") == 0) {
            y = y - remainingDistance;
        } else if (strcmp(dir, "West") == 0) {
            x = x - remainingDistance;
        } else {
            printf("Invalid direction: %s\n", dir);
            exit(1);
        }
        remainingDistance = 0;
    }
    printf("Final position: x = %d, y = %d, direction = %s\n", x, y, dir);
    printf("RC vehicle simulation completed successfully!\n");
}

int main() {
    int x = 0; // Starting X coordinate
    int y = 0; // Starting Y coordinate
    char dir[10] = "North"; // Starting direction
    int speed = 5; // Starting speed
    rcVehicleSimulation(x, y, dir, speed);
    return 0;
}