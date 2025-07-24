//FormAI DATASET v1.0 Category: Robot movement control ; Style: peaceful
/* This is a program for controlling the movement of a robot using C language
   It moves smoothly and peacefully */

#include <stdio.h>

// Function to move the robot forward
void move_forward(int distance)
{
    printf("Robot is moving forward %d meters.\n", distance);
}

// Function to move the robot backward
void move_backward(int distance)
{
    printf("Robot is moving backward %d meters.\n", distance);
}

// Function to turn the robot left
void turn_left(int angle)
{
    printf("Robot is turning left %d degrees.\n", angle);
}

// Function to turn the robot right
void turn_right(int angle)
{
    printf("Robot is turning right %d degrees.\n", angle);
}

// Function to stop the robot
void stop_robot()
{
    printf("Robot has stopped.\n");
}

// Main function to test the movement control
int main()
{
    int distance = 5; // distance to move forward/backward (in meters)
    int angle = 45; // angle to turn (in degrees)

    // Move the robot forward
    move_forward(distance);

    // Turn the robot left
    turn_left(angle);

    // Move the robot backward
    move_backward(distance);

    // Turn the robot right
    turn_right(angle);

    // Stop the robot
    stop_robot();

    return 0;
}