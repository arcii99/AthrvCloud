//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: creative
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SPEED 10
#define MAXTurningAngle 45

typedef enum { Left, Right } TurnDirection;

typedef struct {
    int speed;
    int turningAngle;
    bool isMovingForward;
    bool isTurning;
} Vehicle;

void setSpeed(Vehicle *V, int speed) {
    if (speed <= MAX_SPEED && speed >= 0) {
        V->speed = speed;
        printf("Vehicle Speed set to %d\n", speed);
    }
    else {
        printf("Invalid Speed value\n");
    }
}

void setTurningAngle(Vehicle *V, int angle) {
    if (angle <= MAXTurningAngle && angle >= 0) {
        V->turningAngle = angle;
        printf("Vehicle Turning Angle set to %d\n", angle);
    }
    else {
        printf("Invalid Turning Angle\n");
    }
}

void turn(Vehicle *V, TurnDirection direction) {
    V->isTurning = true;
    if (direction == Left) {
        printf("Vehicle is turning Left with an angle of %d degrees.\n", V->turningAngle);
    }
    else {
        printf("Vehicle is turning Right with an angle of %d degrees.\n", V->turningAngle);
    }
}

void stopTurn(Vehicle *V) {
    V->isTurning = false;
    printf("Vehicle ceased turning.\n");
}

void moveForward(Vehicle *V) {
    V->isMovingForward = true;
    printf("Vehicle is moving forward with speed %d.\n", V->speed);
}

void moveBackward(Vehicle *V) {
    V->isMovingForward = false;
    printf("Vehicle is moving backward with speed %d.\n", V->speed);
}

int main() {
    Vehicle myVehicle;
    setSpeed(&myVehicle, 5);
    setTurningAngle(&myVehicle, 30);
    
    moveForward(&myVehicle);
    turn(&myVehicle, Right);
    stopTurn(&myVehicle);
    moveBackward(&myVehicle);

    return 0;
}