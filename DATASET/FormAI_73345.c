//FormAI DATASET v1.0 Category: Robot movement control ; Style: invasive
#include <stdio.h>

// Function to initialize the robot
void init_robot() {
    // Code to turn on the robot's hardware
    printf("Robot initialized successfully!\n");
}

// Function to move the robot forward
void move_forward(int distance) {
    // Code to move the robot forward by distance units
    printf("Robot moved forward by %d units\n", distance);
}

// Function to move the robot backward
void move_backward(int distance) {
    // Code to move the robot backward by distance units
    printf("Robot moved backward by %d units\n", distance);
}

// Function to turn the robot left
void turn_left(int angle) {
    // Code to turn the robot left by angle degrees
    printf("Robot turned left by %d degrees\n", angle);
}

// Function to turn the robot right
void turn_right(int angle) {
    // Code to turn the robot right by angle degrees
    printf("Robot turned right by %d degrees\n", angle);
}

// Function to stop the robot
void stop_robot() {
    // Code to stop the robot's movement
    printf("Robot has stopped moving.\n");
}

// Main function to control the robot's movements
int main() {
    // Initialize the robot
    init_robot();

    // Move the robot forward by 5 units
    move_forward(5);

    // Turn the robot left by 90 degrees
    turn_left(90);

    // Move the robot forward by 10 units
    move_forward(10);

    // Stop the robot's movement
    stop_robot();

    // Turn the robot right by 45 degrees
    turn_right(45);

    // Move the robot backward by 3 units
    move_backward(3);

    return 0;
}