//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables for drone movements
    int forward = 0;
    int backward = 0;
    int left = 0;
    int right = 0;
    int Up = 0;
    int Down = 0;

    printf("Welcome to the C Drone Remote Control Program!\n\n");

    // Loop to receive user commands
    while (1)
    {
        // Print current drone movements status
        printf("Current Drone Movements: Forward - %d | Backward - %d | Left - %d | Right - %d | Up - %d | Down - %d\n\n", forward, backward, left, right, Up, Down);

        // Receive user command
        printf("Please enter a command (F = Forward, B = Backward, L = Left, R = Right, U = Up, D = Down, Q = Quit):\n");
        char command = getchar();

        // Handle user command
        switch (command)
        {
            case 'F':
            case 'f':
                printf("Moving Forward...\n");
                forward++;
                break;

            case 'B':
            case 'b':
                printf("Moving Backward...\n");
                backward++;
                break;

            case 'L':
            case 'l':
                printf("Moving Left...\n");
                left++;
                break;

            case 'R':
            case 'r':
                printf("Moving Right...\n");
                right++;
                break;

            case 'U':
            case 'u':
                printf("Moving Up...\n");
                Up++;
                break;

            case 'D':
            case 'd':
                printf("Moving Down...\n");
                Down++;
                break;

            case 'Q':
            case 'q':
                printf("Exiting Drone Remote Control Program...\n");
                return 0;

            default:
                printf("Invalid command. Please try again.\n");
                break;
        }

        // Clear input buffer
        while (getchar() != '\n');
    }

    return 0;
}