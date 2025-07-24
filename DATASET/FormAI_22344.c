//FormAI DATASET v1.0 Category: Physics simulation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Define constants for the simulation
#define GRAVITY 9.81 // m/s^2
#define PI 3.14159265359

// Define a structure to hold the properties of a ball
typedef struct {
    double x;
    double y;
    double mass;
    double radius;
    double vx;
    double vy;
} Ball;

// Function to calculate the gravitational force between two balls
double gravitationalForce(Ball b1, Ball b2) {
    double distance = sqrt(pow(b2.x - b1.x, 2) + pow(b2.y - b1.y, 2));
    double force = (GRAVITY * b1.mass * b2.mass) / pow(distance, 2);
    return force;
}

// Function to update the velocity and position of a ball
void updateBall(Ball *b, double dt) {
    b->vx += 0; // There is no horizontal acceleration in this simulation
    b->vy -= GRAVITY * dt; // Vertical acceleration is just gravity
    b->x += b->vx * dt; // Update horizontal position
    b->y += b->vy * dt; // Update vertical position
}

int main() {
    // Create two balls with random properties
    Ball b1 = {0, 10, 1, 0.5, 1, 0};
    Ball b2 = {5, 0, 2, 1, 0, 0};
    // Define the simulation time step
    double dt = 0.01;
    // Define the simulation duration
    double duration = 5.0;
    // Loop through the simulation time
    for (double t = 0; t <= duration; t += dt) {
        // Calculate the gravitational force between the balls
        double force = gravitationalForce(b1, b2);
        // Calculate the acceleration of each ball
        double a1 = force / b1.mass;
        double a2 = force / b2.mass;
        // Update the velocity and position of each ball
        updateBall(&b1, dt);
        updateBall(&b2, dt);
        // Print the current properties of each ball
        printf("Ball 1: x = %lf, y = %lf, vx = %lf, vy = %lf\n", b1.x, b1.y, b1.vx, b1.vy);
        printf("Ball 2: x = %lf, y = %lf, vx = %lf, vy = %lf\n", b2.x, b2.y, b2.vx, b2.vy);
        printf("Time: %lf seconds\n", t);
        printf("--------------------------------------------------\n");
    }
    return 0;
}