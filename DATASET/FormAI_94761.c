//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

/* Remote Control Vehicle Simulation */

int main()
{
    // SETUP
    int battery_level = 100;
    int distance_traveled = 0;
    int direction_facing = 0; // Represents a compass direction in degrees (0-359)
    printf("Welcome to Remote Control Vehicle Simulation Program! \n\n");

    // MAIN LOOP
    while (battery_level > 0) // Battery must have at least 1% charge to operate
    {
        // Prompt user for input
        printf("Enter a command: ");
        char command = getchar();
        getchar(); // Ignore the newline character

        // PROCESS INPUT
        switch (command)
        {
            case 'F':
            case 'f':
                // Move forward
                printf("Vehicle is moving forward... \n");
                distance_traveled++;
                break;
            case 'B':
            case 'b':
                // Move backward
                printf("Vehicle is moving backward... \n");
                distance_traveled--;
                break;
            case 'L':
            case 'l':
                // Turn left
                printf("Vehicle is turning left... \n");
                direction_facing -= 45; // Turn 45 degrees to the left
                if (direction_facing < 0) {
                    direction_facing += 360; // Wrap around to 359 degrees
                }
                break;
            case 'R':
            case 'r':
                // Turn right
                printf("Vehicle is turning right... \n");
                direction_facing += 45; // Turn 45 degrees to the right
                if (direction_facing >= 360) {
                    direction_facing -= 360; // Wrap around to 0 degrees
                }
                break;
            case 'C':
            case 'c':
                // Check battery level
                printf("Battery level is %d%% \n", battery_level);
                break;
            default:
                // Invalid command
                printf("Error: Invalid command entered. \n");
                break;
        }

        // CONSUME BATTERY
        battery_level--;

        // CHECK STATUS
        if (battery_level <= 0) {
            printf("Battery has run out! Vehicle has stopped. \n");
            break;
        }

        // PRINT STATE
        printf("Vehicle has traveled %d units of distance and is facing %d degrees from North. \n", distance_traveled, direction_facing);
        printf("------------------\n");
    }

    // CLEANUP
    printf("Simulation has ended. Thank you for using the Remote Control Vehicle Simulation Program! \n");
    return 0;
}