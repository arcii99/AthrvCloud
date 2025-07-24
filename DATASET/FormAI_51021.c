//FormAI DATASET v1.0 Category: Robot movement control ; Style: paranoid
#include <stdio.h>

// Define constants for movement directions
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

// Define safety threshold constants
#define OBSTACLE_DISTANCE_THRESHOLD 50
#define BATTERY_LEVEL_THRESHOLD 20

// Function to move the robot forward
void move_forward() {
    printf("Moving forward...\n");
    // Add code to control the robot's motors
}

// Function to move the robot backward
void move_backward() {
    printf("Moving backward...\n");
    // Add code to control the robot's motors
}

// Function to turn the robot left
void turn_left() {
    printf("Turning left...\n");
    // Add code to control the robot's motors
}

// Function to turn the robot right
void turn_right() {
    printf("Turning right...\n");
    // Add code to control the robot's motors
}

int main() {
    int direction = FORWARD;
    int distance_to_obstacle = 1000;
    int battery_level = 100;

    while (1) {
        // Check if there is an obstacle in the way
        if (distance_to_obstacle <= OBSTACLE_DISTANCE_THRESHOLD) {
            printf("Obstacle detected! Stopping...\n");
            // Add code to stop the robot's motors
        } else {
            // Determine the direction to move based on the battery level
            if (battery_level >= BATTERY_LEVEL_THRESHOLD) {
                // Move forward
                if (direction == FORWARD) {
                    move_forward();
                } else if (direction == BACKWARD) {
                    move_backward();
                } else if (direction == LEFT) {
                    turn_left();
                } else if (direction == RIGHT) {
                    turn_right();
                }
            } else {
                // Battery level is too low, turn around and head home
                if (direction == FORWARD) {
                    direction = BACKWARD;
                    move_backward();
                } else {
                    direction = FORWARD;
                    move_forward();
                }
            }
        }

        // Update the distance to the obstacle and battery level
        distance_to_obstacle -= 10;
        battery_level -= 1;

        // Check if the battery level is critically low
        if (battery_level <= BATTERY_LEVEL_THRESHOLD) {
            printf("Battery level critically low! Returning to base...\n");
            // Add code to return the robot to its charging dock
            break;
        }
    }

    return 0;
}