//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408E-11 // Universal Gravitational Constant

typedef struct {
    double x, y, z; // Position vector
    double vx, vy, vz; // Velocity vector
    double m; // Mass
} Body;

int main() {
    // Declare and initialize Sun and planets
    Body sun = {0, 0, 0, 0, 0, 0, 1.989E30};
    Body mercury = {4.60E10, 0, 0, 0, 47890, 0, 3.30E23};
    Body venus = {1.08E11, 0, 0, 0, 35020, 0, 4.87E24};
    Body earth = {1.50E11, 0, 0, 0, 29783, 0, 5.97E24};
    Body mars = {2.28E11, 0, 0, 0, 24140, 0, 6.42E23};
    Body jupiter = {7.78E11, 0, 0, 0, 13060, 0, 1.90E27};
    Body saturn = {1.43E12, 0, 0, 0, 9690, 0, 5.68E26};
    Body uranus = {2.87E12, 0, 0, 0, 6810, 0, 8.68E25};
    Body neptune = {4.50E12, 0, 0, 0, 5430, 0, 1.02E26};

    Body bodies[9] = {sun, mercury, venus, earth, mars, jupiter, saturn, uranus, neptune};
    const int num_bodies = 9;

    // Set time step and end time
    const double dt = 86400; // One day in seconds
    const double t_end = 365 * 86400; // One year in seconds

    // Run simulation
    for (double t = 0; t <= t_end; t += dt) {

        // Calculate acceleration for each body due to gravity from other bodies
        for (int i = 0; i < num_bodies; i++) {
            Body *body1 = &bodies[i];
            double ax = 0, ay = 0, az = 0; // Acceleration components
            for (int j = 0; j < num_bodies; j++) {
                if (i != j) {
                    Body *body2 = &bodies[j];

                    // Calculate distance between bodies
                    double dx = body2->x - body1->x;
                    double dy = body2->y - body1->y;
                    double dz = body2->z - body1->z;
                    double r = sqrt(dx*dx + dy*dy + dz*dz);

                    // Calculate acceleration
                    double a = G * body2->m / (r*r);
                    ax += a * dx / r;
                    ay += a * dy / r;
                    az += a * dz / r;
                }
            }
            // Update velocity and position of body 
            body1->vx += ax * dt;
            body1->vy += ay * dt;
            body1->vz += az * dt;
            body1->x += body1->vx * dt;
            body1->y += body1->vy * dt;
            body1->z += body1->vz * dt;
        }
    }

    // Print final positions of planets
    printf("Final positions:\n");
    for (int i = 0; i < num_bodies; i++) {
        Body body = bodies[i];
        printf("%-8s x: %.2E m, y: %.2E m, z: %.2E m\n", (i == 0 ? "Sun" : (i == 1 ? "Mercury" : (i == 2 ? "Venus" : (i == 3 ? "Earth" : (i == 4 ? "Mars" : (i == 5 ? "Jupiter" : (i == 6 ? "Saturn" : (i == 7 ? "Uranus" : "Neptune")))))))), body.x, body.y, body.z);
    }

    return 0;
}