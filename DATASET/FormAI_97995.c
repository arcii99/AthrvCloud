//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants for direction and speed values
#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3
#define SLOW 0
#define MEDIUM 1
#define FAST 2

// function prototypes
void init(int *x, int *y, int *dir, int *speed);
void move(int *x, int *y, int *dir, int *speed);
void printStatus(int x, int y, int dir, int speed);

int main() {
    int x, y, dir, speed;
    srand(time(NULL)); // seed random number generator
    
    init(&x, &y, &dir, &speed); // initialize variables
    
    // simulate movement
    for (int i = 0; i < 50; i++) {
        move(&x, &y, &dir, &speed);
        printStatus(x, y, dir, speed);
    }
    
    return 0;
}

// initialize variables to random values
void init(int *x, int *y, int *dir, int *speed) {
    *x = rand() % 100;
    *y = rand() % 100;
    *dir = rand() % 4;
    *speed = rand() % 3;
}

// update position and direction based on speed and direction values
void move(int *x, int *y, int *dir, int *speed) {
    switch (*dir) {
        case LEFT:
            *x -= 5 * (*speed + 1);
            break;
        case RIGHT:
            *x += 5 * (*speed + 1);
            break;
        case FORWARD:
            *y += 5 * (*speed + 1);
            break;
        case BACKWARD:
            *y -= 5 * (*speed + 1);
            break;
        default:
            printf("Invalid direction value\n");
    }
    *dir = rand() % 4;
    *speed = rand() % 3;
}

// print current status of vehicle
void printStatus(int x, int y, int dir, int speed) {
    printf("Vehicle status:\n");
    printf("Position: (%d, %d)\n", x, y);
    switch (dir) {
        case LEFT:
            printf("Direction: LEFT\n");
            break;
        case RIGHT:
            printf("Direction: RIGHT\n");
            break;
        case FORWARD:
            printf("Direction: FORWARD\n");
            break;
        case BACKWARD:
            printf("Direction: BACKWARD\n");
            break;
        default:
            printf("Invalid direction value\n");
    }
    switch (speed) {
        case SLOW:
            printf("Speed: SLOW\n");
            break;
        case MEDIUM:
            printf("Speed: MEDIUM\n");
            break;
        case FAST:
            printf("Speed: FAST\n");
            break;
        default:
            printf("Invalid speed value\n");
    }
    printf("--------------------\n");
}