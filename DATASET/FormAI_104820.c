//FormAI DATASET v1.0 Category: Physics simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant (in N*(m^2/kg^2))
#define G 6.67408e-11

// Define the mass of Earth (in kg)
#define M_EARTH 5.972e24

// Define the time increment (in seconds)
#define DT 1.0

// Define the number of simulation steps
#define STEPS 1000

// Define the structure for a body in space
typedef struct {
    double mass; // mass in kg
    double x; // x position in meters
    double y; // y position in meters
    double vx; // x velocity in meters per second
    double vy; // y velocity in meters per second
} Body;

// Calculate distance between two bodies
double distance(Body b1, Body b2) {
    return sqrt(pow(b1.x - b2.x, 2) + pow(b1.y - b2.y, 2));
}

// Calculate gravitational force between two bodies
double force(Body b1, Body b2) {
    double r = distance(b1, b2);
    return G * b1.mass * b2.mass / pow(r, 2);
}

// Calculate x acceleration of a body
double acceleration_x(Body b, Body bodies[]) {
    double ax = 0;
    for (int i = 0; i < 2; i++) {
        if (bodies[i].x != b.x || bodies[i].y != b.y) {
            double f = force(b, bodies[i]);
            double r = distance(b, bodies[i]);
            double angle = atan2(bodies[i].y - b.y, bodies[i].x - b.x);
            ax += f / b.mass * cos(angle);
        }
    }
    return ax;
}

// Calculate y acceleration of a body
double acceleration_y(Body b, Body bodies[]) {
    double ay = 0;
    for (int i = 0; i < 2; i++) {
        if (bodies[i].x != b.x || bodies[i].y != b.y) {
            double f = force(b, bodies[i]);
            double r = distance(b, bodies[i]);
            double angle = atan2(bodies[i].y - b.y, bodies[i].x - b.x);
            ay += f / b.mass * sin(angle);
        }
    }
    return ay;
}

// Update the position and velocity of a body
void update(Body *b, Body bodies[]) {
    b->x += b->vx * DT;
    b->y += b->vy * DT;
    b->vx += acceleration_x(*b, bodies) * DT;
    b->vy += acceleration_y(*b, bodies) * DT;
}

int main() {
    // Define the bodies
    Body bodies[2];
    bodies[0].mass = 1000;
    bodies[0].x = 0;
    bodies[0].y = 0;
    bodies[0].vx = 0;
    bodies[0].vy = 0;
    bodies[1].mass = M_EARTH;
    bodies[1].x = 0;
    bodies[1].y = 6.371e6;
    bodies[1].vx = 7900;
    bodies[1].vy = 0;

    // Run the simulation
    for (int step = 0; step < STEPS; step++) {
        update(&bodies[0], bodies);
        update(&bodies[1], bodies);
        printf("Body 1: (%.2f,%.2f) Velocity: (%.2f,%.2f)\n", bodies[0].x, bodies[0].y, bodies[0].vx, bodies[0].vy);
        printf("Body 2: (%.2f,%.2f) Velocity: (%.2f,%.2f)\n", bodies[1].x, bodies[1].y, bodies[1].vx, bodies[1].vy);
        printf("\n");
    }

    return 0;
}