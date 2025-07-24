//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_ANGLE 360
#define MIN_ANGLE 0

// Define struct for vehicle
struct vehicle {
    int speed;
    int angle;
};

// Define function to check if input is within range
int inRange(int value, int min, int max) {
    return value >= min && value <= max;
}

// Define function to set speed of vehicle
void setSpeed(struct vehicle *v, int speed) {
    if (inRange(speed, MIN_SPEED, MAX_SPEED)) {
        v->speed = speed;
    } else {
        printf("Error: Speed must be between %d and %d.\n", MIN_SPEED, MAX_SPEED);
    }
}

// Define function to set angle of vehicle
void setAngle(struct vehicle *v, int angle) {
    if (inRange(angle, MIN_ANGLE, MAX_ANGLE)) {
        v->angle = angle;
    } else {
        printf("Error: Angle must be between %d and %d.\n", MIN_ANGLE, MAX_ANGLE);
    }
}

// Define function to print vehicle status
void printVehicle(struct vehicle v) {
    printf("Vehicle status: Speed = %d, Angle = %d\n", v.speed, v.angle);
}

int main() {
    // Initialize vehicle
    struct vehicle v;
    setSpeed(&v, 50);
    setAngle(&v, 180);
    printVehicle(v);
    
    // Simulate remote control commands
    setSpeed(&v, 80);
    setAngle(&v, 270);
    printVehicle(v);
    
    setSpeed(&v, 120);
    setAngle(&v, 45);
    printVehicle(v);
    
    setSpeed(&v, -20);
    setAngle(&v, 500);
    printVehicle(v);

    return 0;
}