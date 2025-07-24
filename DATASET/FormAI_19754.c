//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5         // number of planets
#define G 6.67e-11  // gravitational constant

// planet struct
typedef struct Planet {
    double x, y;     // position
    double vx, vy;   // velocity
    double mass;     // mass
} Planet;

// calculate distance between two planets
double distance(Planet p1, Planet p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    double dist = sqrt(dx*dx + dy*dy);
    return dist;
}

int main() {
    // create an array of planets
    Planet planets[N] = {
        {1e11, 0, 0, 3e4, 5.97e24},   // Earth
        {-1e11, 0, 0, -3e4, 6.39e23}, // Mars
        {0, 1.5e11, -2e4, 0, 2.0e30}, // Sun
        {0, -2e11, 1.5e4, 0, 3.3e23}, // Venus
        {0, 0, 0, 0, 0}               // empty planet, acts as a reference point
    };

    // set up the time step and simulation duration
    double dt = 86400; // 1 day
    double t = 0;
    double duration = 365*86400; // 1 year

    // run the simulation
    while (t < duration) {
        // calculate gravitational forces between all pairs of planets
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                double r = distance(planets[i], planets[j]);
                double F = G * planets[i].mass * planets[j].mass / (r*r);
                double fx = F * (planets[j].x - planets[i].x) / r;
                double fy = F * (planets[j].y - planets[i].y) / r;
                planets[i].vx += fx / planets[i].mass * dt;
                planets[i].vy += fy / planets[i].mass * dt;
                planets[j].vx -= fx / planets[j].mass * dt;
                planets[j].vy -= fy / planets[j].mass * dt;
            }
        }
        
        // move each planet according to its velocity
        for (int i = 0; i < N-1; i++) {
            planets[i].x += planets[i].vx * dt;
            planets[i].y += planets[i].vy * dt;
        }

        // update time
        t += dt;

        // print out the coordinates of the Earth and the Sun every 100 days
        if (fmod(t, 100*86400) == 0) {
            printf("t = %.0f days:\n", t/86400);
            printf("  Earth: (%.3e, %.3e)\n", planets[0].x, planets[0].y);
            printf("  Sun: (%.3e, %.3e)\n", planets[2].x, planets[2].y);
            printf("\n");
        }
    }

    return 0;
}