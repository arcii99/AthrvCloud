//FormAI DATASET v1.0 Category: Robot movement control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEFT 0
#define RIGHT 1
#define FORWARD 2
#define BACKWARD 3

// define robot structure
typedef struct {
    int x;
    int y;
    bool carrying;
} Robot;

// function declarations
void moveRobot(Robot* r, int direction);
bool pickupObject(Robot* r);
bool dropObject(Robot* r);
void printRobot(Robot r);

int main(void) {
    Robot r = {0, 0, false}; // initialize robot
    printf("Starting position: "); printRobot(r);

    // move forward
    moveRobot(&r, FORWARD);
    printf("Moved forward: "); printRobot(r);

    // pick up object
    bool success = pickupObject(&r);
    if (success) {
        printf("Picked up object: "); printRobot(r);
    }
    else {
        printf("Could not pick up object: "); printRobot(r);
    }

    // move right
    moveRobot(&r, RIGHT);
    printf("Moved right: "); printRobot(r);

    // drop object
    success = dropObject(&r);
    if (success) {
        printf("Dropped object: "); printRobot(r);
    }
    else {
        printf("Could not drop object: "); printRobot(r);
    }
}

// function definitions
void moveRobot(Robot* r, int direction) {
    switch(direction) {
        case LEFT: r->x -= 1; break;
        case RIGHT: r->x += 1; break;
        case FORWARD: r->y += 1; break;
        case BACKWARD: r->y -= 1; break;
    }
}

bool pickupObject(Robot* r) {
    if (r->carrying) {
        return false; // robot is already carrying an object
    }
    else {
        r->carrying = true;
        return true;
    }
}

bool dropObject(Robot* r) {
    if (!r->carrying) {
        return false; // robot is not carrying an object
    }
    else {
        r->carrying = false;
        return true;
    }
}

void printRobot(Robot r) {
    printf("(x=%d, y=%d, carrying=%s)\n", r.x, r.y, r.carrying ? "true" : "false");
}