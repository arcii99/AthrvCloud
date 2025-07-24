//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Linus Torvalds
#include <stdio.h>

// Define the values that represent the joystick positions
#define JOY_LEFT 0
#define JOY_RIGHT 255
#define JOY_CENTER 128

// Define the values that represent the drone's movements
#define DRONE_FORWARD 1
#define DRONE_BACKWARD 2
#define DRONE_LEFT 3
#define DRONE_RIGHT 4
#define DRONE_UP 5
#define DRONE_DOWN 6

// Function to move the drone based on the joystick position
void moveDrone(int x, int y)
{
    int moveVal;

    if (x == JOY_LEFT) {
        moveVal = DRONE_LEFT;
    } else if (x == JOY_RIGHT) {
        moveVal = DRONE_RIGHT;
    } else {
        moveVal = 0; // center, no movement
    }

    if (y == JOY_LEFT) {
        moveVal |= DRONE_FORWARD;
    } else if (y == JOY_RIGHT) {
        moveVal |= DRONE_BACKWARD;
    } else {
        // no vertical movement
    }

    if (moveVal == 0) {
        printf("Drone stays in place.\n");
    } else if (moveVal == 1) {
        printf("Drone moves forward to the left.\n");
    } else if (moveVal == 2) {
        printf("Drone moves backward to the right.\n");
    } else if (moveVal == 3) {
        printf("Drone moves to the left.\n");
    } else if (moveVal == 4) {
        printf("Drone moves to the right.\n");
    } else if (moveVal == 5) {
        printf("Drone moves up.\n");
    } else if (moveVal == 6) {
        printf("Drone moves down.\n");
    } else {
        printf("Drone moves in an unknown direction.\n");
    }
}

int main(void)
{
    int joy_x = JOY_CENTER;
    int joy_y = JOY_CENTER;

    // Simulate joystick input:
    joy_x = JOY_LEFT;
    joy_y = JOY_LEFT;
    moveDrone(joy_x, joy_y);

    joy_x = JOY_RIGHT;
    joy_y = JOY_RIGHT;
    moveDrone(joy_x, joy_y);

    joy_x = JOY_CENTER;
    joy_y = JOY_CENTER;
    moveDrone(joy_x, joy_y);

    return 0;
}