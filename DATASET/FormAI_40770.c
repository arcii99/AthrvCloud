//FormAI DATASET v1.0 Category: Physics simulation ; Style: interoperable
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.6743e-11 // Gravitational constant

typedef struct {
    double x, y, z; // Position vector
    double vx, vy, vz; // Velocity vector
    double ax, ay, az; // Acceleration vector
    double mass; // Mass of the object
} Body;

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2) + pow(z2-z1, 2));
}

void compute_acceleration(Body *b1, Body *b2, double *ax, double *ay, double *az) {
    double force = GRAV_CONST * b1->mass * b2->mass / pow(distance(b1->x, b1->y, b1->z, b2->x, b2->y, b2->z), 2);
    *ax = force * (b2->x - b1->x) / distance(b1->x, b1->y, b1->z, b2->x, b2->y, b2->z) / b1->mass;
    *ay = force * (b2->y - b1->y) / distance(b1->x, b1->y, b1->z, b2->x, b2->y, b2->z) / b1->mass;
    *az = force * (b2->z - b1->z) / distance(b1->x, b1->y, b1->z, b2->x, b2->y, b2->z) / b1->mass;
}

int main() {
    Body b[2] = {{.x = 0, .y = 0, .z = 0, .vx = 0, .vy = 0, .vz = 0, .ax = 0, .ay = 0, .az = 0, .mass = 1000},
                 {.x = 10, .y = 0, .z = 0, .vx = 0, .vy = 0, .vz = 0, .ax = 0, .ay = 0, .az = 0, .mass = 1000}}; // Two bodies
    const double dt = 0.01; // Time step
    int nsteps = 100; // Number of time steps
    int i, j, step;

    for (step = 0; step < nsteps; step++) {
        // Compute acceleration for each body
        for (i = 0; i < 2; i++) {
            b[i].ax = b[i].ay = b[i].az = 0; // Reset acceleration vector
            for (j = 0; j < 2; j++) {
                if (i == j) continue; // Skip if it's the same body
                double ax, ay, az;
                compute_acceleration(&b[i], &b[j], &ax, &ay, &az);
                b[i].ax += ax;
                b[i].ay += ay;
                b[i].az += az;
            }
        }

        // Compute new position and velocity for each body
        for (i = 0; i < 2; i++) {
            b[i].vx += b[i].ax * dt;
            b[i].vy += b[i].ay * dt;
            b[i].vz += b[i].az * dt;
            b[i].x += b[i].vx * dt;
            b[i].y += b[i].vy * dt;
            b[i].z += b[i].vz * dt;
        }

        // Print position and velocity of each body
        printf("Step %d:\n", step);
        for (i = 0; i < 2; i++) {
            printf("Body %d: (%f, %f, %f) -- (%f, %f, %f)\n", i+1, b[i].x, b[i].y, b[i].z, b[i].vx, b[i].vy, b[i].vz);
        }

        printf("\n");
    }

    return 0;
}