//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define constants for maximum speed and steering angle
#define MAX_SPEED 100.0
#define MAX_ANGLE 45.0

int main()
{
    // Declare variables for speed, angle, and distance
    double speed = 0.0;
    double angle = 0.0;
    double distance = 0.0;

    // Welcome message and instructions
    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Use the arrow keys to control the vehicle.\n");
    printf("Press 'q' to quit.\n\n");

    // Loop until user quits
    while (1)
    {
        // Get user input
        printf("Speed: %0.2f Angle: %0.2f Distance: %0.2f\n", speed, angle, distance);
        printf(">");
        char input = getchar();

        // Process user input
        switch (input)
        {
            case 'w':
                if (speed < MAX_SPEED) { speed += 10.0; }
                break;
            case 's':
                if (speed > -MAX_SPEED) { speed -= 10.0; }
                break;
            case 'a':
                if (angle < MAX_ANGLE) { angle += 5.0; }
                break;
            case 'd':
                if (angle > -MAX_ANGLE) { angle -= 5.0; }
                break;
            case 'q':
                printf("Thanks for playing!\n");
                exit(0);
            default:
                printf("Invalid input.\n");
                break;
        }

        // Update distance based on speed and angle
        distance += (speed / 10.0) * cos(angle * 3.14159 / 180.0);

        // Check if vehicle has crashed (i.e. distance is negative)
        if (distance < 0.0)
        {
            printf("CRASH! You traveled %0.2f meters.\n", -distance);
            exit(0);
        }
    }

    return 0;
}