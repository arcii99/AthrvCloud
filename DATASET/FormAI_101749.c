//FormAI DATASET v1.0 Category: Robot movement control ; Style: shape shifting
#include <stdio.h>

// Function to move the robot up/down
void moveUpDown(int distance) {
    printf("Robot moving up/down by %d meters\n", distance);
}

// Function to move the robot left/right
void moveLeftRight(int distance) {
    printf("Robot moving left/right by %d meters\n", distance);
}

// Function to change the robot shape
void shapeShift(int shape) {
    switch(shape) {
        case 1:
            printf("Robot transforming into a sphere\n");
            break;
        case 2:
            printf("Robot transforming into a cube\n");
            break;
        case 3:
            printf("Robot transforming into a pyramid\n");
            break;
        case 4:
            printf("Robot transforming into a cylinder\n");
            break;
        default:
            printf("Invalid shape selected\n");
    }
}

// Main function
int main() {

    // Initial configuration of the robot
    int shape = 1; // sphere
    int x = 0; // initial x coordinate
    int y = 0; // initial y coordinate

    // Robot movement commands
    moveUpDown(5);
    moveLeftRight(3);
    shapeShift(2);
    moveUpDown(-2);
    moveLeftRight(-4);
    shapeShift(3);
    moveUpDown(4);
    moveLeftRight(2);
    shapeShift(4);

    // Print final position and shape of the robot
    printf("Final position of the robot: (%d,%d)\n", x, y);
    printf("Final shape of the robot: %d\n", shape);

    return 0;
}