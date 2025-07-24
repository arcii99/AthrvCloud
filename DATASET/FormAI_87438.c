//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: decentralized
#include <stdio.h>
#include <math.h>

#define PI 3.1415926535
#define G 6.6743e-11

struct Body
{
    double x, y, z;     // coordinates
    double vx, vy, vz;  // velocity
    double m;           // mass
};

struct Body bodies[] = {
    {0, 0, 0, 0, 0, 0, 1.98e30},                 // Sun
    {0, 6.38e6 + 3.84e8, 0, 1022.0, 0, 0, 5.97e24}, // Moon
    {0, 1.50e11, 0, 0, 29800.0, 0, 5.97e24},       // Earth
    {0, 2.28e11, 0, 0, 24100.0, 0, 6.42e23},       // Mars
    {0, 7.78e11, 0, 0, 13070.0, 0, 1.90e27},       // Jupiter
    {0, 1.43e12, 0, 0, 9680.0, 0, 5.68e26},        // Saturn
    {0, 2.87e12, 0, 0, 6810.0, 0, 8.68e25}         // Uranus
};
int nbodies = sizeof(bodies) / sizeof(struct Body);

double distance(double x1, double y1, double z1, double x2, double y2, double z2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main()
{
    double dt = 60 * 60 * 24; // one day
    double t = 0;
    int steps = 365;

    while (steps--)
    {
        // Calculate all forces
        for (int i = 0; i < nbodies; i++)
        {
            double fx = 0, fy = 0, fz = 0;
            struct Body b1 = bodies[i];
            for (int j = 0; j < nbodies; j++)
            {
                if (i == j)
                    continue;

                struct Body b2 = bodies[j];
                double d = distance(b1.x, b1.y, b1.z, b2.x, b2.y, b2.z);
                double f = G * b1.m * b2.m / (d * d);
                fx += f * (b2.x - b1.x) / d;
                fy += f * (b2.y - b1.y) / d;
                fz += f * (b2.z - b1.z) / d;
            }
            bodies[i].vx += fx / b1.m * dt;
            bodies[i].vy += fy / b1.m * dt;
            bodies[i].vz += fz / b1.m * dt;
        }

        // Update positions and velocities
        for (int i = 0; i < nbodies; i++)
        {
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
            bodies[i].z += bodies[i].vz * dt;
        }

        t += dt;
    }

    // Print final positions
    for (int i = 0; i < nbodies; i++)
    {
        printf("%d: %e %e %e\n", i, bodies[i].x, bodies[i].y, bodies[i].z);
    }

    return 0;
}