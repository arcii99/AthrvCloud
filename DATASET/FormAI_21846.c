//FormAI DATASET v1.0 Category: Robot movement control ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Declare global variables
int x = 0; // X position of the robot
int y = 0; // Y position of the robot
int dir = 0; // Direction the robot is facing (0: north, 1: east, 2: south, 3: west)
int power = 100; // The robot's power level

// Declare function prototypes
void move_forward();
void turn_left();
void turn_right();
void display_position();

int main()
{
    // Print welcome message
    printf("Welcome to Robot Control Program!\n");

    // Main loop of the program
    int ch;
    do
    {
        // Display robot's current position and power level
        display_position();

        // Prompt user for input
        printf("Enter command (f - forward, l - turn left, r - turn right, q - quit): ");
        ch = getchar();
        getchar(); // Remove the newline character from the input buffer

        // Execute the command based on user input
        switch (ch)
        {
            case 'f':
                move_forward();
                break;
            case 'l':
                turn_left();
                break;
            case 'r':
                turn_right();
                break;
            case 'q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid command!\n");
                break;
        }

        // Check if the robot has any power left
        if (power <= 0)
        {
            printf("The robot is out of power!\n");
            break;
        }
    } while (ch != 'q');

    // End of program
    return 0;
}

void move_forward()
{
    // Calculate the new position based on the robot's direction
    switch (dir)
    {
        case 0: // north
            y++;
            break;
        case 1: // east
            x++;
            break;
        case 2: // south
            y--;
            break;
        case 3: // west
            x--;
            break;
    }

    // Decrease the power level by 1
    power--;

    // Display a message to the user
    printf("Robot moves forward one space.\n");
}

void turn_left()
{
    // Update the robot's direction
    dir = (dir + 3) % 4;

    // Decrease the power level by 1
    power--;

    // Display a message to the user
    printf("Robot turns left.\n");
}

void turn_right()
{
    // Update the robot's direction
    dir = (dir + 1) % 4;

    // Decrease the power level by 1
    power--;

    // Display a message to the user
    printf("Robot turns right.\n");
}

void display_position()
{
    // Display the robot's current position and direction
    printf("The robot is at (%d, %d) facing ", x, y);
    switch (dir)
    {
        case 0: // north
            printf("north");
            break;
        case 1: // east
            printf("east");
            break;
        case 2: // south
            printf("south");
            break;
        case 3: // west
            printf("west");
            break;
    }
    printf(". The robot has %d power left.\n", power);
}