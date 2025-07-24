//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SPEED 10.0f
#define MIN_SPEED 1.0f
#define STEERING_SENSITIVITY 5.0f
#define ACCELERATION_SPEED 2.0f
#define BRAKING_SPEED 3.0f

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point position;
    float speed;
    float direction;
    float steering_angle;
} Vehicle;

void move_forward(Vehicle *vehicle) {
    float dx = ACCELERATION_SPEED * cos(vehicle->direction);
    float dy = ACCELERATION_SPEED * sin(vehicle->direction);
    vehicle->position.x += dx;
    vehicle->position.y += dy;
}

void move_backward(Vehicle *vehicle) {
    float dx = BRAKING_SPEED * cos(vehicle->direction);
    float dy = BRAKING_SPEED * sin(vehicle->direction);
    vehicle->position.x -= dx;
    vehicle->position.y -= dy;
    if (vehicle->speed > MIN_SPEED) {
        vehicle->speed -= BRAKING_SPEED;
    } else {
        vehicle->speed = MIN_SPEED;
    }
}

void turn_left(Vehicle *vehicle) {
    vehicle->steering_angle += STEERING_SENSITIVITY;
    vehicle->direction += vehicle->steering_angle * (M_PI / 180.0f);
}

void turn_right(Vehicle *vehicle) {
    vehicle->steering_angle -= STEERING_SENSITIVITY;
    vehicle->direction += vehicle->steering_angle * (M_PI / 180.0f);
}

void simulate_vehicle(Vehicle *vehicle) {
    char input[10];
    while (1) {
        printf("Enter command (f=forward, b=backward, l=left, r=right, q=quit): ");
        fgets(input, 10, stdin);
        if (strcmp(input, "q\n") == 0) {
            break;
        } else if (strcmp(input, "f\n") == 0) {
            move_forward(vehicle);
            if (vehicle->speed < MAX_SPEED) {
                vehicle->speed += ACCELERATION_SPEED;
            } else {
                vehicle->speed = MAX_SPEED;
            }
        } else if (strcmp(input, "b\n") == 0) {
            move_backward(vehicle);
        } else if (strcmp(input, "l\n") == 0) {
            turn_left(vehicle);
        } else if (strcmp(input, "r\n") == 0) {
            turn_right(vehicle);
        }
        printf("Position: (%.2f, %.2f)\n", vehicle->position.x, vehicle->position.y);
        printf("Speed: %.2f\n", vehicle->speed);
        printf("Direction: %.2f\n", vehicle->direction * (180.0f / M_PI));
        printf("Steering Angle: %.2f\n", vehicle->steering_angle);
    }
}

int main() {
    Vehicle vehicle = {{0.0f, 0.0f}, 0.0f, 0.0f, 0.0f};
    simulate_vehicle(&vehicle);
    return 0;
}