//FormAI DATASET v1.0 Category: Robot movement control ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants for the robot's movements
#define MOVE_FORWARD 0
#define MOVE_BACKWARD 1
#define TURN_LEFT 2
#define TURN_RIGHT 3

// Define constants for the robot's velocity and acceleration
#define MAX_VELOCITY 5.0
#define MAX_ACCELERATION 2.0

// Define a struct to hold the robot's position and orientation
typedef struct {
    double x;
    double y;
    double theta;
} RobotPosition;

// Define a function to calculate the distance between two points
double distance(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

// Define a function to calculate the angle between two points
double angle(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return atan2(dy, dx);
}

int main() {
    // Initialize the robot's position and velocity
    RobotPosition position = {0.0, 0.0, 0.0};
    double velocity = 0.0;
    double acceleration = 0.0;

    // Initialize the list of movements
    int movements[] = {MOVE_FORWARD, TURN_RIGHT, MOVE_FORWARD, TURN_LEFT, MOVE_BACKWARD, TURN_LEFT, MOVE_FORWARD};

    // Initialize the robot's movement iterator
    int iterator = 0;

    // Iterate through the movements list
    while(1) {
        // Get the next movement
        int movement = movements[iterator];

        // Check if the robot has reached its goal
        if(distance(position.x, position.y, 10.0, 10.0) < 0.1) {
            printf("Robot has reached the goal!\n");
            break;
        }

        // Perform the movement
        if(movement == MOVE_FORWARD) {
            acceleration = MAX_ACCELERATION;
        } else if(movement == MOVE_BACKWARD) {
            acceleration = -MAX_ACCELERATION;
        } else if(movement == TURN_LEFT) {
            acceleration = 0.0;
            position.theta += M_PI/4;
        } else if(movement == TURN_RIGHT) {
            acceleration = 0.0;
            position.theta -= M_PI/4;
        }

        // Update the robot's velocity and position
        velocity += acceleration;
        if(velocity > MAX_VELOCITY) {
            velocity = MAX_VELOCITY;
        } else if(velocity < -MAX_VELOCITY) {
            velocity = -MAX_VELOCITY;
        }
        position.x += velocity*cos(position.theta);
        position.y += velocity*sin(position.theta);

        // Print the robot's position
        printf("Robot at (%f, %f) facing %f radians\n", position.x, position.y, position.theta);

        // Increment the movement iterator
        iterator++;
        if(iterator >= sizeof(movements)/sizeof(int)) {
            iterator = 0;
        }
    }

    return 0;
}