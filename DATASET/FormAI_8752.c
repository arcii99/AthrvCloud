//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: configurable
#include <stdio.h>
#include <math.h>

#define G 6.67E-11 // Gravitational constant

typedef struct {
    double x, y;
    double vx, vy;
    double fx, fy;
    double mass;
} Body;

void initialize(Body *b, double x, double y, double vx, double vy, double mass) {
    b->x = x;
    b->y = y;
    b->vx = vx;
    b->vy = vy;
    b->mass = mass;
}

// Add force to body
void addForce(Body *b, double fx, double fy) {
    b->fx += fx;
    b->fy += fy;
}

// Reset force for next iteration
void resetForce(Body *b) {
    b->fx = 0;
    b->fy = 0;
}

// Calculate distance between two bodies
double distance(Body *body1, Body *body2) {
    double dx = body2->x - body1->x;
    double dy = body2->y - body1->y;
    return sqrt(dx * dx + dy * dy);
}

// Calculate force between two bodies
void calculateForce(Body *body1, Body *body2) {
    double dist = distance(body1, body2);
    double force = G * body1->mass * body2->mass / (dist * dist);
    double fx = force * (body2->x - body1->x) / dist;
    double fy = force * (body2->y - body1->y) / dist;
    addForce(body1, fx, fy);
    addForce(body2, -fx, -fy);
}

// Update velocity and position of body
void update(Body *b, double dt) {
    b->vx += b->fx / b->mass * dt;
    b->vy += b->fy / b->mass * dt;
    b->x += b->vx * dt;
    b->y += b->vy * dt;
}

int main() {
    // Configuration
    const double dt = 86400; // 1 day
    const int numBodies = 3;
    Body bodies[numBodies];
    initialize(&bodies[0], 0, 0, 0, 0, 5.97E24); // Earth
    initialize(&bodies[1], -384400000, 0, 0, -1022, 7.34E22); // Moon
    initialize(&bodies[2], 149600000000, 0, 0, 29780, 1.99E30); // Sun

    // Simulation
    for (int i = 0; i < 365; i++) { // Simulate 1 year
        for (int j = 0; j < numBodies; j++) { // Reset force for all bodies
            resetForce(&bodies[j]);
        }
        for (int j = 0; j < numBodies; j++) { // Calculate force for all bodies
            for (int k = j + 1; k < numBodies; k++) {
                calculateForce(&bodies[j], &bodies[k]);
            }
        }
        for (int j = 0; j < numBodies; j++) { // Update all bodies
            update(&bodies[j], dt);
        }
        printf("Day %d: Earth (%f, %f)\n", i + 1, bodies[0].x, bodies[0].y); // Print position of Earth
    }

    return 0;
}