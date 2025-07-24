//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: artistic
#include <stdio.h>
#include <math.h>

#define NUM_BODIES 9 // Number of Bodies in Solar System

// Define Body structure
struct Body {
    double x, y;
    double mass;
    double vx, vy;
    double ax, ay;
    double fx, fy;
};

// Define Constants
const double G = 6.673 * pow(10, -11);
const double DAY = 86400;
const double YEAR = 365.25 * DAY;

// Function to Calculate Distance between Two Bodies
double distance(struct Body *body1, struct Body *body2) {
    double dx = body1->x - body2->x;
    double dy = body1->y - body2->y;
    return sqrt(dx * dx + dy * dy);
}

// Function to Calculate Gravitational Force between Two Bodies
void calculateForce(struct Body *body1, struct Body *body2) {
    double r = distance(body1, body2);
    double f = G * body1->mass * body2->mass / (r * r);
    double theta = atan2(body2->y - body1->y, body2->x - body1->x);
    body1->fx += f * cos(theta);
    body1->fy += f * sin(theta);
}

// Function to Update Acceleration of a Body
void updateAcceleration(struct Body *body) {
    body->ax = body->fx / body->mass;
    body->ay = body->fy / body->mass;
}

// Function to Update Velocity of a Body
void updateVelocity(struct Body *body, double dt) {
    body->vx += body->ax * dt;
    body->vy += body->ay * dt;
}

// Function to Update Position of a Body
void updatePosition(struct Body *body, double dt) {
    body->x += body->vx * dt;
    body->y += body->vy * dt;
}

// Function to Simulate One Day in Solar System
void simulateDay(struct Body *bodies, double dt) {
    // Reset Forces
    for (int i = 0; i < NUM_BODIES; i++) {
        bodies[i].fx = 0;
        bodies[i].fy = 0;
    }
    // Calculate Forces
    for (int i = 0; i < NUM_BODIES; i++) {
        for (int j = 0; j < NUM_BODIES; j++) {
            if (i != j) {
                calculateForce(&bodies[i], &bodies[j]);
            }
        }
    }
    // Update Accelerations
    for (int i = 0; i < NUM_BODIES; i++) {
        updateAcceleration(&bodies[i]);
    }
    // Update Velocities
    for (int i = 0; i < NUM_BODIES; i++) {
        updateVelocity(&bodies[i], dt);
    }
    // Update Positions
    for (int i = 0; i < NUM_BODIES; i++) {
        updatePosition(&bodies[i], dt);
    }
}

int main() {
    // Define Bodies
    struct Body sun = {0, 0, 1.989 * pow(10, 30), 0, 0, 0, 0, 0, 0};
    struct Body mercury = {0.39 * pow(10, 12), 0, 3.30 * pow(10, 23), 0, 47.4 * pow(10, 3), 0, 0, 0, 0};
    struct Body venus = {0.72 * pow(10, 12), 0, 4.869 * pow(10, 24), 0, 35.0 * pow(10, 3), 0, 0, 0, 0};
    struct Body earth = {1.0 * pow(10, 12), 0, 5.974 * pow(10, 24), 0, 29.8 * pow(10, 3), 0, 0, 0, 0};
    struct Body mars = {1.52 * pow(10, 12), 0, 6.419 * pow(10, 23), 0, 24.1 * pow(10, 3), 0, 0, 0, 0};
    struct Body jupiter = {5.20 * pow(10, 12), 0, 1.899 * pow(10, 27), 0, 13.1 * pow(10, 3), 0, 0, 0, 0};
    struct Body saturn = {9.58 * pow(10, 12), 0, 5.685 * pow(10, 26), 0, 9.7 * pow(10, 3), 0, 0, 0, 0};
    struct Body uranus = {19.18 * pow(10, 12), 0, 8.683 * pow(10, 25), 0, 6.8 * pow(10, 3), 0, 0, 0, 0};
    struct Body neptune = {30.07 * pow(10, 12), 0, 1.024 * pow(10, 26), 0, 5.4 * pow(10, 3), 0, 0, 0, 0};

    // Simulate Solar System
    for (double t = 0; t < YEAR * 10; t += DAY) {
        simulateDay((struct Body[]){sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune}, DAY);
        printf("Day %.0f: Earth (x=%.2f, y=%.2f)\n", t / DAY, earth.x / pow(10, 12), earth.y / pow(10, 12));
    }

    return 0;
}