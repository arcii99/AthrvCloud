//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define G 6.674 * pow(10, -11)  // Gravitational constant
#define TIME_STEP 0.1           // Time step for simulation
#define MAX_TIME 100            // Maximum time for simulation

// Define structure for planet
typedef struct
{
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

// Define function to calculate distance between two planets
double distance(Planet p1, Planet p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Define function to calculate force between two planets
double force(Planet p1, Planet p2)
{
    double r = distance(p1, p2);
    return G * p1.mass * p2.mass / (r*r);
}

// Define function to update planet's position and velocity
void update(Planet *p, double fx, double fy, double fz)
{
    // Calculate acceleration and update velocity
    double ax = fx / p->mass;
    double ay = fy / p->mass;
    double az = fz / p->mass;
    p->vx += ax * TIME_STEP;
    p->vy += ay * TIME_STEP;
    p->vz += az * TIME_STEP;

    // Update position
    p->x += p->vx * TIME_STEP;
    p->y += p->vy * TIME_STEP;
    p->z += p->vz * TIME_STEP;
}

int main()
{
    // Create planets
    Planet planets[3] = {
        {5.97 * pow(10, 24), 0, 0, 0, 0, 0, 0},  // Earth
        {7.35 * pow(10, 22), 384400000, 0, 0, 0, 1022, 0},  // Moon
        {1.989 * pow(10, 30), -149600000000, 0, 0, 0, 0, 0}  // Sun
    };

    // Run simulation
    for (double t = 0; t < MAX_TIME; t += TIME_STEP)
    {
        // Calculate forces between planets
        double fx[3] = {0, 0, 0};
        double fy[3] = {0, 0, 0};
        double fz[3] = {0, 0, 0};
        for (int i = 0; i < 3; i++)
        {
            for (int j = i+1; j < 3; j++)
            {
                double f = force(planets[i], planets[j]);
                double dx = planets[j].x - planets[i].x;
                double dy = planets[j].y - planets[i].y;
                double dz = planets[j].z - planets[i].z;
                fx[i] += f * dx / distance(planets[i], planets[j]);
                fy[i] += f * dy / distance(planets[i], planets[j]);
                fz[i] += f * dz / distance(planets[i], planets[j]);
                fx[j] -= fx[i];
                fy[j] -= fy[i];
                fz[j] -= fz[i];
            }
        }

        // Update planet positions and velocities
        for (int i = 0; i < 3; i++)
        {
            update(&planets[i], fx[i], fy[i], fz[i]);
        }

        // Print planet positions
        printf("Time: %lf\n", t);
        for (int i = 0; i < 3; i++)
        {
            printf("Planet %d: (%lf, %lf, %lf)\n", i+1, planets[i].x, planets[i].y, planets[i].z);
        }
        printf("\n");
    }

    return 0;
}