//FormAI DATASET v1.0 Category: Robot movement control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the robot's position variables
int x = 0;
int y = 0;

// Define functions for robot movement
void move_forward(int distance)
{
    y += distance;
}

void turn_left()
{
    printf("Turning left...\n");
    // Code to turn the robot left
}

void turn_right()
{
    printf("Turning right...\n");
    // Code to turn the robot right
}

// Define the main function
int main()
{
    // Print the starting position of the robot
    printf("Starting position: (%d, %d)\n", x, y);

    // Move the robot forward by 5 units
    move_forward(5);
    printf("New position: (%d, %d)\n", x, y);

    // Turn the robot left and move forward by 3 units
    turn_left();
    move_forward(3);
    printf("New position: (%d, %d)\n", x, y);

    // Turn the robot right and move forward by 2 units
    turn_right();
    move_forward(2);
    printf("New position: (%d, %d)\n", x, y);

    // Turn the robot left and move forward by 7 units
    turn_left();
    move_forward(7);
    printf("New position: (%d, %d)\n", x, y);

    return 0;
}