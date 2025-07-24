//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 10
#define MIN_SPEED 0
#define MAX_ANGLE 360
#define MIN_ANGLE 0

int main()
{
    int speed = 0;
    int angle = 0;
    bool isOn = false;

    printf("Welcome to Remote Control Vehicle Simulation\n");

    while (true)
    {
        // Print current state of the vehicle
        printf("Speed: %d\nAngle: %d\n", speed, angle);
        printf("Power: %s\n", isOn ? "On" : "Off");

        // Get user input
        char input[50];
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);

        // Process user input
        char command = input[0];
        switch (command)
        {
            case 's':
                // Set speed
                speed = atoi(&input[1]);
                if (speed > MAX_SPEED)
                {
                    speed = MAX_SPEED;
                }
                else if (speed < MIN_SPEED)
                {
                    speed = MIN_SPEED;
                }
                break;

            case 'a':
                // Set angle
                angle = atoi(&input[1]);
                if (angle > MAX_ANGLE)
                {
                    angle = MAX_ANGLE;
                }
                else if (angle < MIN_ANGLE)
                {
                    angle = MIN_ANGLE;
                }
                break;

            case 'p':
                // Toggle power
                isOn = !isOn;
                break;

            case 'h':
                // Print help message
                printf("s <speed> - set speed\n");
                printf("a <angle> - set angle\n");
                printf("p - toggle power\n");
                printf("h - print help message\n");
                printf("q - quit\n");
                break;

            case 'q':
                // Quit program
                return 0;

            default:
                // Invalid command
                printf("Invalid command. Type 'h' for help.\n");
                break;
        }
    }

    return 0;
}