//FormAI DATASET v1.0 Category: Robot movement control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Struct to store coordinates of robot
struct coordinates {
    int x;
    int y;
};

// Function to calculate distance between two points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    // Initialize robot coordinates
    struct coordinates robot = {0, 0};

    // Initialize target coordinates
    struct coordinates target = {5, 5};

    // Move robot towards target until it reaches within 1 unit of the target
    while (distance(robot.x, robot.y, target.x, target.y) > 1) {
        // Calculate angle between robot and target
        double angle = atan2(target.y - robot.y, target.x - robot.x);

        // Move the robot 1 unit in the direction of the target
        robot.x += round(cos(angle));
        robot.y += round(sin(angle));

        // Print current robot coordinates
        printf("Robot is at (%d, %d)\n", robot.x, robot.y);
    }

    // Print message when the robot reaches the target
    printf("Robot has reached the target!\n");

    return 0;
}