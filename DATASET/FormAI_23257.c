//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: expert-level
#include <stdio.h>

struct RemoteControl {
    int forward;
    int backward;
    int left;
    int right;
};

struct Vehicle {
    int x;
    int y;
};

void moveForward(struct Vehicle *vehicle) {
    (*vehicle).x++;
    printf("Vehicle moved forward to (%d,%d).\n", (*vehicle).x, (*vehicle).y);
}

void moveBackward(struct Vehicle *vehicle) {
    (*vehicle).x--;
    printf("Vehicle moved backward to (%d,%d).\n", (*vehicle).x, (*vehicle).y);
}

void moveLeft(struct Vehicle *vehicle) {
    (*vehicle).y--;
    printf("Vehicle turned left and moved to (%d,%d).\n", (*vehicle).x, (*vehicle).y);
}

void moveRight(struct Vehicle *vehicle) {
    (*vehicle).y++;
    printf("Vehicle turned right and moved to (%d,%d).\n", (*vehicle).x, (*vehicle).y);
}

void simulateMovement(struct RemoteControl *remote, struct Vehicle *vehicle) {
    if ((*remote).forward == 1) moveForward(vehicle);
    if ((*remote).backward == 1) moveBackward(vehicle);
    if ((*remote).left == 1) moveLeft(vehicle);
    if ((*remote).right == 1) moveRight(vehicle);
}

int main() {
    struct RemoteControl remote = {0,0,0,1}; // simulate right button press
    struct Vehicle vehicle = {0,0};

    simulateMovement(&remote, &vehicle);
    return 0;
}