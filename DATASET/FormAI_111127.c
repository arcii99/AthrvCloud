//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: safe
#include <stdio.h>

// Constant declarations
#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_ANGLE 360
#define MIN_ANGLE 0

// Struct to hold vehicle information
typedef struct {
    char* name;
    int speed;
    int angle;
} Vehicle;

// Function to set vehicle speed
void set_speed(Vehicle* v, int speed) {
    if (speed < MIN_SPEED) {
        printf("Error: Speed is less than minimum (%d)\n", MIN_SPEED);
    } else if (speed > MAX_SPEED) {
        printf("Error: Speed is greater than maximum (%d)\n", MAX_SPEED);
    } else {
        v->speed = speed;
        printf("%s speed set to %d\n", v->name, v->speed);
    }
}

// Function to set vehicle angle
void set_angle(Vehicle* v, int angle) {
    if (angle < MIN_ANGLE) {
        printf("Error: Angle is less than minimum (%d)\n", MIN_ANGLE);
    } else if (angle > MAX_ANGLE) {
        printf("Error: Angle is greater than maximum (%d)\n", MAX_ANGLE);
    } else {
        v->angle = angle;
        printf("%s angle set to %d\n", v->name, v->angle);
    }
}

int main() {
    // Create two vehicles
    Vehicle vehicle1 = {"Vehicle 1", 0, 0};
    Vehicle vehicle2 = {"Vehicle 2", 50, 180};

    // Set vehicle speeds and angles
    set_speed(&vehicle1, 75);
    set_speed(&vehicle2, 120);
    set_angle(&vehicle1, 45);
    set_angle(&vehicle2, 270);

    return 0;
}