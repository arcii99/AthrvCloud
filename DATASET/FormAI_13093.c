//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define MAX_TURN_ANGLE 45
#define MIN_TURN_ANGLE -45

struct Vehicle {
    int speed;
    int direction_angle;
    bool is_engine_on;
};

void start_engine(struct Vehicle* vehicle) {
    vehicle->is_engine_on = true;
    printf("Vehicle engine turned on.\n");
}

void stop_engine(struct Vehicle* vehicle) {
    vehicle->is_engine_on = false;
    printf("Vehicle engine turned off.\n");
}

void set_speed(struct Vehicle* vehicle, int speed) {
    if (speed > MAX_SPEED) {
        speed = MAX_SPEED;
    } else if (speed < MIN_SPEED) {
        speed = MIN_SPEED;
    }
    vehicle->speed = speed;
    printf("Vehicle speed set to %d.\n", vehicle->speed);
}

void turn(struct Vehicle* vehicle, int angle) {
    if (angle > MAX_TURN_ANGLE) {
        angle = MAX_TURN_ANGLE;
    } else if (angle < MIN_TURN_ANGLE) {
        angle = MIN_TURN_ANGLE;
    }
    vehicle->direction_angle += angle;
    printf("Vehicle direction angle set to %d.\n", vehicle->direction_angle);
}

void print_vehicle_info(struct Vehicle* vehicle) {
    printf("Vehicle is %s.\n", vehicle->is_engine_on ? "on" : "off");
    printf("Vehicle speed: %d\n", vehicle->speed);
    printf("Vehicle direction angle: %d\n", vehicle->direction_angle);
}

int main() {
    struct Vehicle my_vehicle = {0, 0, false};

    start_engine(&my_vehicle);
    set_speed(&my_vehicle, 80);
    turn(&my_vehicle, -30);
    print_vehicle_info(&my_vehicle);
    stop_engine(&my_vehicle);

    return EXIT_SUCCESS;
}