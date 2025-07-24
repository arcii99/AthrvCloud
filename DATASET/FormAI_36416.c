//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 1.0                                 // Gravitational constant
#define dt 0.01                               // Time step size for simulation
#define tmax 10.0                             // Maximum time for simulation

typedef struct {
    double x, y;                              // Position of planet
    double vx, vy;                            // Velocity of planet
    double ax, ay;                            // Acceleration of planet
    double mass;                              // Mass of planet
} Planet;

// Function to calculate the gravitational force between two planets
void calculate_force(Planet *p1, Planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double r = sqrt(dx*dx + dy*dy);
    double f = G * p1->mass * p2->mass / (r*r);
    double fx = f * dx / r;
    double fy = f * dy / r;
    p1->ax += fx / p1->mass;
    p1->ay += fy / p1->mass;
    p2->ax -= fx / p2->mass;
    p2->ay -= fy / p2->mass;
}

int main() {
    // Define three planets: Earth, Mars, and Jupiter
    Planet earth = { 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };
    Planet mars = { 1.524, 0.0, 0.0, 24.077, 0.0, 0.107 };
    Planet jupiter = { 5.203, 0.0, 0.0, 13.07, 0.0, 318 };

    // Run simulation for specified time
    for (double t = 0; t <= tmax; t += dt) {
        // Calculate forces on planets
        calculate_force(&earth, &mars);
        calculate_force(&earth, &jupiter);
        calculate_force(&mars, &jupiter);

        // Update positions and velocities of planets
        earth.vx += earth.ax * dt;
        earth.vy += earth.ay * dt;
        earth.x += earth.vx * dt;
        earth.y += earth.vy * dt;
        earth.ax = 0.0;
        earth.ay = 0.0;

        mars.vx += mars.ax * dt;
        mars.vy += mars.ay * dt;
        mars.x += mars.vx * dt;
        mars.y += mars.vy * dt;
        mars.ax = 0.0;
        mars.ay = 0.0;

        jupiter.vx += jupiter.ax * dt;
        jupiter.vy += jupiter.ay * dt;
        jupiter.x += jupiter.vx * dt;
        jupiter.y += jupiter.vy * dt;
        jupiter.ax = 0.0;
        jupiter.ay = 0.0;

        // Print positions of planets at current time
        printf("Time: %lf, Earth: (%lf, %lf), Mars: (%lf, %lf), Jupiter: (%lf, %lf)\n", t, earth.x, earth.y, mars.x, mars.y, jupiter.x, jupiter.y);
    }

    return 0;
}