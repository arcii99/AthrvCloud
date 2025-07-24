//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: innovative
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67408e-11   // Gravitational Constant

typedef struct {
    double x, y;    // Cartesian Coordinates
    double vx, vy;  // Velocity
    double ax, ay;  // Acceleration
    double fx, fy;  // Force
    double mass;    // Mass
    double radius;  // Radius
} body;

int main() {
    // Time Properties
    double t = 0;
    double dt = 3600;

    // Number of Bodies
    int n = 5;

    // Bodies
    body sun, earth, mars, jupiter, saturn;

    // Sun
    sun.x = 0;
    sun.y = 0;
    sun.vx = 0;
    sun.vy = 0;
    sun.ax = 0;
    sun.ay = 0;
    sun.fx = 0;
    sun.fy = 0;
    sun.mass = 1.9882e30;
    sun.radius = 695700e3;

    // Earth
    earth.x = 147e9;
    earth.y = 0;
    earth.vx = 0;
    earth.vy = 29.78e3;
    earth.ax = 0;
    earth.ay = 0;
    earth.fx = 0;
    earth.fy = 0;
    earth.mass = 5.97e24;
    earth.radius = 6.371e6;

    // Mars
    mars.x = 228e9;
    mars.y = 0;
    mars.vx = 0;
    mars.vy = 24.077e3;
    mars.ax = 0;
    mars.ay = 0;
    mars.fx = 0;
    mars.fy = 0;
    mars.mass = 6.42e23;
    mars.radius = 3.3895e6;

    // Jupiter
    jupiter.x = 778e9;
    jupiter.y = 0;
    jupiter.vx = 0;
    jupiter.vy = 13.07e3;
    jupiter.ax = 0;
    jupiter.ay = 0;
    jupiter.fx = 0;
    jupiter.fy = 0;
    jupiter.mass = 1.898e27;
    jupiter.radius = 69.911e6;

    // Saturn
    saturn.x = 1.43e12;
    saturn.y = 0;
    saturn.vx = 0;
    saturn.vy = 9.69e3;
    saturn.ax = 0;
    saturn.ay = 0;
    saturn.fx = 0;
    saturn.fy = 0;
    saturn.mass = 5.68e26;
    saturn.radius = 58.232e6;

    // Array of Bodies
    body bodies[n];
    bodies[0] = sun;
    bodies[1] = earth;
    bodies[2] = mars;
    bodies[3] = jupiter;
    bodies[4] = saturn;

    // Random Seed
    srand(time(NULL));

    // Initial Forces
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double r = sqrt(dx*dx + dy*dy);
                double f = G * bodies[i].mass * bodies[j].mass / (r*r);
                bodies[i].fx += f * dx / r;
                bodies[i].fy += f * dy / r;
            }
        }
    }

    // Integration Loop
    while (1) {
        // Reset Forces
        for (int i = 0; i < n; i++) {
            bodies[i].fx = 0;
            bodies[i].fy = 0;
        }

        // Calculate Forces
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    double dx = bodies[j].x - bodies[i].x;
                    double dy = bodies[j].y - bodies[i].y;
                    double r = sqrt(dx*dx + dy*dy);
                    double f = G * bodies[i].mass * bodies[j].mass / (r*r);
                    bodies[i].fx += f * dx / r;
                    bodies[i].fy += f * dy / r;
                }
            }
        }

        // Update Positions and Velocities
        for (int i = 0; i < n; i++) {
            bodies[i].ax = bodies[i].fx / bodies[i].mass;
            bodies[i].ay = bodies[i].fy / bodies[i].mass;
            bodies[i].vx += bodies[i].ax * dt;
            bodies[i].vy += bodies[i].ay * dt;
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
        }

        // Print Positions
        printf("%.0f %.0f\n", earth.x, earth.y);

        // Increment Time
        t += dt;
    }

    return 0;
}