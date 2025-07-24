//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include <stdio.h>

#define MAX_SPEED 50
#define MAX_ANGLE 90

typedef struct {
    int speed;
    int angle;
} RemoteControl;

void drive(RemoteControl* rc) {
    printf("Driving at speed %d and angle %d degrees.\n", rc->speed, rc->angle);
}

void accelerate(RemoteControl* rc, int amount) {
    rc->speed += amount;
    if (rc->speed > MAX_SPEED) {
        rc->speed = MAX_SPEED;
    }
    printf("Accelerating to speed %d.\n", rc->speed);
}

void decelerate(RemoteControl* rc, int amount) {
    rc->speed -= amount;
    if (rc->speed < 0) {
        rc->speed = 0;
    }
    printf("Decelerating to speed %d.\n", rc->speed);
}

void turn_left(RemoteControl* rc, int amount) {
    rc->angle -= amount;
    if (rc->angle < -MAX_ANGLE) {
        rc->angle = -MAX_ANGLE;
    }
    printf("Turning left to angle %d degrees.\n", rc->angle);
}

void turn_right(RemoteControl* rc, int amount) {
    rc->angle += amount;
    if (rc->angle > MAX_ANGLE) {
        rc->angle = MAX_ANGLE;
    }
    printf("Turning right to angle %d degrees.\n", rc->angle);
}

int main() {
    printf("Initializing remote control...\n");
    RemoteControl rc = {0, 0};
    printf("Remote control initialized.\n");

    drive(&rc);
    accelerate(&rc, 20);
    turn_left(&rc, 45);
    drive(&rc);
    decelerate(&rc, 10);
    turn_right(&rc, 25);
    turn_right(&rc, 70);
    drive(&rc);
    accelerate(&rc, 40);
    turn_left(&rc, 10);
    drive(&rc);

    return 0;
}