//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11
#define YEAR 365*24*60*60
#define AU 149597870700.0

typedef struct planet {
    char name[20];
    double mass, radius, x, y, z, vx, vy, vz;
} Planet;

void simulate(Planet *planets, int numplanets, double timestep, int years);
double distance(double x1, double y1, double z1, double x2, double y2, double z2);

int main(void)
{
    // create an array of planets in our solar system
    Planet planets[] = {
        {"Sun", 1.9885e30, 696340000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {"Mercury", 0.33011e24, 2439700.0, -3.481266965483955e10, -1.383895691394111e10, 3.005665474661525e9, 1.069544300461382e4, -4.002434289660905e4, -4.746603009350396e3},
        {"Venus", 4.8675e24, 6051800.0, 2.071158664547666e10, -1.054914747761757e11, -2.476935792918054e9, 3.478689707908983e4, 6.922899392319666e3, -2.012734370783209e3},
        {"Earth", 5.9724e24, 6371000.0, -1.509031053539399e11, 4.472674752304104e9, 1.103238177803381e-2, -1.235113645167819e3, -2.994211666679686e4, 1.015634539455065e-2},
        {"Mars", 0.64171e24, 3396200.0, -2.073375461865238e11, -9.962930794934843e10, 9.443128934250463e9, 9.891880896855295e3, -2.246678590720339e4, -4.504861766454481e2},
        {"Jupiter", 1.8982e27, 69911000.0, 7.741684761901437e11, 7.182285892418129e11, -1.529506748757400e10, -7.450488321049820e3, 8.007901804299636e3, -1.296972336756825e2},
        {"Saturn", 5.6834e26, 58232000.0, 1.437293210193696e12, -9.583877021086106e11, -2.213138047439943e10, 4.288067900585681e3, 6.220851762318102e3, -2.755438471103815e2},
        {"Uranus", 8.6810e25, 25362000.0, 2.870765726320423e12, 1.773594739732589e12, -3.888153303223366e10, -2.500968195102049e3, 4.023214039135104e3, 4.201830336795771e1},
        {"Neptune", 1.0241e26, 24622000.0, 4.498041353858358e12, -1.097625604107368e12, -8.114387189942642e10, 1.325934434464647e3, 5.389611783342025e3, -1.446264286714015e2},
    };

    // get the number of planets in the array
    int numplanets = sizeof(planets) / sizeof(planets[0]);

    // simulate the solar system with a timestep of 1 day for 10 years
    simulate(planets, numplanets, YEAR, 10);

    return 0;
}

void simulate(Planet *planets, int numplanets, double timestep, int years)
{
    // calculate the number of iterations needed
    int iterations = (int)(years * YEAR / timestep);

    // create an array to store the new velocities of the planets
    double vels[numplanets][3];

    // perform the simulation
    for (int i = 0; i < iterations; i++) {
        // reset the new velocities array
        for (int j = 0; j < numplanets; j++) {
            for (int k = 0; k < 3; k++) {
                vels[j][k] = 0.0;
            }
        }

        // calculate the gravitational forces on each planet
        for (int j = 0; j < numplanets; j++) {
            for (int k = 0; k < numplanets; k++) {
                // ignore self-interaction and if planets are the same
                if (j != k) {
                    // calculate the distance between the planets
                    double dist = distance(planets[j].x, planets[j].y, planets[j].z, planets[k].x, planets[k].y, planets[k].z);

                    // calculate the gravitational force between the planets
                    double f = G * planets[j].mass * planets[k].mass / (dist * dist);

                    // calculate the force components
                    double fx = f * (planets[k].x - planets[j].x) / dist;
                    double fy = f * (planets[k].y - planets[j].y) / dist;
                    double fz = f * (planets[k].z - planets[j].z) / dist;

                    // add the forces to the new velocities array
                    vels[j][0] += fx / planets[j].mass * timestep;
                    vels[j][1] += fy / planets[j].mass * timestep;
                    vels[j][2] += fz / planets[j].mass * timestep;
                }
            }
        }

        // update the positions and velocities of each planet
        for (int j = 0; j < numplanets; j++) {
            // calculate the new positions
            planets[j].x += planets[j].vx * timestep + 0.5 * vels[j][0] * timestep * timestep;
            planets[j].y += planets[j].vy * timestep + 0.5 * vels[j][1] * timestep * timestep;
            planets[j].z += planets[j].vz * timestep + 0.5 * vels[j][2] * timestep * timestep;

            // update the velocities with the new forces
            planets[j].vx += vels[j][0];
            planets[j].vy += vels[j][1];
            planets[j].vz += vels[j][2];
        }

        // print the positions of each planet
        printf("Year %d:\n", (int)((i + 1) * timestep / YEAR));
        for (int j = 0; j < numplanets; j++) {
            printf("%s: %lf AU (%lf, %lf, %lf) m/s (%lf, %lf, %lf) m/s^2\n", planets[j].name, sqrt(planets[j].x * planets[j].x + planets[j].y * planets[j].y + planets[j].z * planets[j].z) / AU, planets[j].x, planets[j].y, planets[j].z, planets[j].vx, planets[j].vy, planets[j].vz);
        }
        printf("\n");
    }
}

double distance(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}