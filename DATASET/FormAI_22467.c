//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: interoperable
#include <stdio.h>
#include <stdbool.h>

// Remote Control Vehicle simulation function
void operate_RC_vehicle(bool forward, bool backward, bool left, bool right)
{
    printf("Operating the RC vehicle...\n");

    if (forward)
    {
        printf("Moving forward.\n");
    }
    else if (backward)
    {
        printf("Moving backward.\n");
    }

    if (left)
    {
        printf("Turning left.\n");
    }
    else if (right)
    {
        printf("Turning right.\n");
    }

    printf("RC vehicle simulation completed!\n");
}

// Main function to test the RC vehicle operation
int main()
{
    bool forward = false, backward = false, left = false, right = false;
    char input;

    printf("Welcome to Remote Control Vehicle simulation program!\n");

    printf("Please enter the controls to operate the vehicle (F-forward, B-backward, L-left, R-right): ");

    // Read the user input
    while ((input = getchar()) != '\n')
    {
        if (input == 'F' || input == 'f')
        {
            forward = true;
        }
        else if (input == 'B' || input == 'b')
        {
            backward = true;
        }
        else if (input == 'L' || input == 'l')
        {
            left = true;
        }
        else if (input == 'R' || input == 'r')
        {
            right = true;
        }
    }

    // Operate the RC vehicle based on user input
    operate_RC_vehicle(forward, backward, left, right);

    return 0;
}