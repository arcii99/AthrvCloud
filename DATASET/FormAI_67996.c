//FormAI DATASET v1.0 Category: Physics simulation ; Style: mind-bending
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// Define particle structure
typedef struct
{
    double x, y, z;     // Position vector
    double vx, vy, vz;  // Velocity vector
    double ax, ay, az;  // Acceleration vector
    double mass;        // Mass of particle
} Particle;

// Define gravitational constant
#define G 6.674e-11

// Define function to calculate distance between particles
double distance(Particle p1, Particle p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dz = p1.z - p2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// Define function to calculate gravitational force between particles
void calculateForce(Particle* p1, Particle* p2)
{
    double r = distance(*p1, *p2);
    double f = G * p1->mass * p2->mass / (r*r);
    double fx = f * (p2->x - p1->x) / r;
    double fy = f * (p2->y - p1->y) / r;
    double fz = f * (p2->z - p1->z) / r;
    p1->ax += fx / p1->mass;
    p1->ay += fy / p1->mass;
    p1->az += fz / p1->mass;
    p2->ax -= fx / p2->mass;
    p2->ay -= fy / p2->mass;
    p2->az -= fz / p2->mass;
}

int main()
{
    // Create an array of particles
    Particle p[3];

    // Define mass and position of each particle
    p[0].mass = 1;
    p[0].x = 0;
    p[0].y = 0;
    p[0].z = 0;

    p[1].mass = 1;
    p[1].x = 1;
    p[1].y = 1;
    p[1].z = 0;

    p[2].mass = 1;
    p[2].x = 0.5;
    p[2].y = 0.5;
    p[2].z = sqrt(3)/2;

    // Define initial velocity of each particle
    p[0].vx = 0;
    p[0].vy = 0;
    p[0].vz = 0;

    p[1].vx = 0;
    p[1].vy = 0;
    p[1].vz = 0;

    p[2].vx = 0;
    p[2].vy = 0;
    p[2].vz = 0;

    // Set up simulation parameters
    double dt = 0.001;
    int steps = 10000;

    // Run simulation
    for (int i = 0; i < steps; i++)
    {
        // Calculate forces between particles
        calculateForce(&p[0], &p[1]);
        calculateForce(&p[0], &p[2]);
        calculateForce(&p[1], &p[2]);

        // Update velocities and positions
        for (int j = 0; j < 3; j++)
        {
            p[j].vx += p[j].ax * dt;
            p[j].vy += p[j].ay * dt;
            p[j].vz += p[j].az * dt;
            p[j].x += p[j].vx * dt;
            p[j].y += p[j].vy * dt;
            p[j].z += p[j].vz * dt;
        }

        // Reset acceleration vectors
        for (int j = 0; j < 3; j++)
        {
            p[j].ax = 0;
            p[j].ay = 0;
            p[j].az = 0;
        }
    }

    // Print final positions
    printf("Particle 1: (%f, %f, %f)\n", p[0].x, p[0].y, p[0].z);
    printf("Particle 2: (%f, %f, %f)\n", p[1].x, p[1].y, p[1].z);
    printf("Particle 3: (%f, %f, %f)\n", p[2].x, p[2].y, p[2].z);

    return 0;
}