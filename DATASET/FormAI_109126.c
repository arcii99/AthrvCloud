//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: optimized
#include <stdio.h> 

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_ANGLE 90
#define MIN_ANGLE -90

void move_forward(int* speed, int angle) {
    if (*speed + angle > MAX_SPEED) {
        *speed = MAX_SPEED;
    } else if (*speed + angle < MIN_SPEED) {
        *speed = MIN_SPEED;
    } else {
        *speed += angle;
    }
    printf("Moved forward at speed %d and angle %d\n", *speed, angle);
}

void move_backward(int* speed, int angle) {
    if (*speed - angle > MAX_SPEED) {
        *speed = MAX_SPEED;
    } else if (*speed - angle < MIN_SPEED) {
        *speed = MIN_SPEED;
    } else {
        *speed -= angle;
    }
    printf("Moved backward at speed %d and angle %d\n", *speed, angle);
}

void turn_left(int* angle) {
    if (*angle - 10 < MIN_ANGLE) {
        *angle = MIN_ANGLE;
    } else {
        *angle -= 10;
    }
    printf("Turned left to angle %d\n", *angle);
}

void turn_right(int* angle) {
    if (*angle + 10 > MAX_ANGLE) {
        *angle = MAX_ANGLE;
    } else {
        *angle += 10;
    }
    printf("Turned right to angle %d\n", *angle);
}

int main() {
    int speed = 0;
    int angle = 0;

    move_forward(&speed, 50);
    move_backward(&speed, 20);
    turn_left(&angle);
    turn_right(&angle);
    move_forward(&speed, 30);
    return 0;
}