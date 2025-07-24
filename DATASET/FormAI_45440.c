//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: thoughtful
// Unique C Drone Remote Control Program

#include <stdio.h>

#define MAX_INPUT 25

// Function prototype declaration
void droneControl(char input[MAX_INPUT]);

int main() {
    char input[MAX_INPUT];

    printf("*** Welcome to Drone Remote Control! ***\n");
    printf("Please enter your commands:\n\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_INPUT, stdin);

        if (input[0] == '\n') {
            printf("Invalid input, please enter a valid command\n");
            continue;
        }

        droneControl(input);
    }

    return 0;
}

void droneControl(char input[MAX_INPUT]) {
    // Define limits of the drone's flying capabilities
    int minX = -100;
    int maxX = 100;
    int minY = -100;
    int maxY = 100;
    int minZ = 0;
    int maxZ = 100;

    // Initialize the drone's position
    int x = 0;
    int y = 0;
    int z = 0;

    // Parse the command and extract the direction and distance values
    char direction = input[0];
    int distance = (int) strtol(input+1, NULL, 10);

    // Move the drone based on the command
    switch (direction) {
        case 'U':
            z += distance;
            break;
        case 'D':
            z -= distance;
            break;
        case 'L':
            x -= distance;
            break;
        case 'R':
            x += distance;
            break;
        case 'F':
            y += distance;
            break;
        case 'B':
            y -= distance;
            break;
        default:
            printf("Invalid command, please try again\n");
            return;
    }

    // Check if the drone is still within the flying limits
    if (x < minX || x > maxX || y < minY || y > maxY || z < minZ || z > maxZ) {
        printf("Drone has hit the limit, please try another command\n");
    } else {
        printf("Drone has moved to position: (%d, %d, %d)\n", x, y, z);
    }
}