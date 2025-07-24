//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Constants
#define G 6.6743e-11     // Gravitational Constant
#define AU 149597870700  // Astronomical Unit (in meters)
#define YEAR 31536000    // Number of seconds in a year

// Structure to store properties of a planet
typedef struct
{
    char name[20];
    double mass;        // In kg
    double radius;      // In meters
    double x;           // x coordinate (in AU)
    double y;           // y coordinate (in AU)
    double z;           // z coordinate (in AU)
    double vx;          // velocity in x direction (in m/s)
    double vy;          // velocity in y direction (in m/s)
    double vz;          // velocity in z direction (in m/s)
} Planet;

// Function to calculate the force between two planets
void calculate_force(Planet planet1, Planet planet2, double *fx, double *fy, double *fz)
{
    double dx, dy, dz, dist, force;

    dx = (planet2.x - planet1.x) * AU;
    dy = (planet2.y - planet1.y) * AU;
    dz = (planet2.z - planet1.z) * AU;

    dist = sqrt(dx*dx + dy*dy + dz*dz);
    force = G * planet1.mass * planet2.mass / (dist*dist);

    *fx = force * dx / dist;
    *fy = force * dy / dist;
    *fz = force * dz / dist;
}

int main()
{
    // Randomly initialize the planets
    srand(time(NULL));

    Planet sun = {"Sun", 1.989e30, 695700000, 0, 0, 0, 0, 0, 0};

    Planet earth = {"Earth", 5.972e24, 6378000,
                    1.0 * (rand() % 300) + 1.0,  // Random x coordinate (between 1 and 300 AU)
                    1.0 * (rand() % 300) + 1.0,  // Random y coordinate (between 1 and 300 AU)
                    0,                              // We assume all planets are in the same plane
                    0,                              // No initial velocity in x direction
                    29783,                          // Initial velocity in y direction (7.5 km/s)
                    0};                             // No initial velocity in z direction

    Planet mars = {"Mars", 6.39e23, 3390000,
                    -1.0 * (rand() % 300) - 1.0,  // Random x coordinate (between -300 and -1 AU)
                    -1.0 * (rand() % 300) - 1.0,  // Random y coordinate (between -300 and -1 AU)
                    0,                              // We assume all planets are in the same plane
                    0,                              // No initial velocity in x direction
                    -24130,                         // Initial velocity in y direction (-6.1 km/s)
                    0};                             // No initial velocity in z direction

    double fx1, fy1, fz1, fx2, fy2, fz2;
    double ax1, ay1, az1, ax2, ay2, az2;

    for (int i = 0; i < 1000; i++)
    {
        // Calculate the accelerations due to gravity
        calculate_force(sun, earth, &fx1, &fy1, &fz1);
        ax1 = fx1 / earth.mass;
        ay1 = fy1 / earth.mass;
        az1 = fz1 / earth.mass;

        calculate_force(sun, mars, &fx2, &fy2, &fz2);
        ax2 = fx2 / mars.mass;
        ay2 = fy2 / mars.mass;
        az2 = fz2 / mars.mass;

        // Update the velocities and positions of the planets
        earth.vx += ax1 * YEAR;
        earth.vy += ay1 * YEAR;
        earth.vz += az1 * YEAR;
        earth.x += earth.vx * YEAR / AU;
        earth.y += earth.vy * YEAR / AU;
        earth.z += earth.vz * YEAR / AU;

        mars.vx += ax2 * YEAR;
        mars.vy += ay2 * YEAR;
        mars.vz += az2 * YEAR;
        mars.x += mars.vx * YEAR / AU;
        mars.y += mars.vy * YEAR / AU;
        mars.z += mars.vz * YEAR / AU;

        // Print the positions of the planets every 10 steps
        if (i % 10 == 0)
        {
            printf("%10s (%.2f, %.2f, %.2f)\n", earth.name, earth.x, earth.y, earth.z);
            printf("%10s (%.2f, %.2f, %.2f)\n", mars.name, mars.x, mars.y, mars.z);
            printf("\n");
        }
    }

    return 0;
}