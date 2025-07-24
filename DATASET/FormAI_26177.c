//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PLANETS 100

typedef struct {
    double x; /* position x */
    double y; /* position y */
    double vx; /* velocity x */
    double vy; /* velocity y */
    double mass; /* mass of the planet */
} Planet;

int main(int argc, char *argv[]) 
{
    Planet p[MAX_PLANETS]; /* array of planets */
    int count = 0; /* number of planets */

    /* initialization */
    p[0].x = 0;
    p[0].y = 0;
    p[0].vx = 0.1;
    p[0].vy = 0.03;
    p[0].mass = 1;
    count++;

    p[1].x = 10;
    p[1].y = 0;
    p[1].vx = 0;
    p[1].vy = -0.06;
    p[1].mass = 2;
    count++;

    /* simulation parameters */
    double G = 6.67408e-11; /* gravitational constant */
    double dt = 1; /* time step */
    double t = 0; /* simulation time */
    double max_t = 10000; /* maximum simulation time */
    double min_dist = 1e-10; /* minimum distance between planets */

    /* simulation loop */
    while (t < max_t) {
        /* calculate the force and acceleration of each planet */
        int i;
        for (i = 0; i < count; i++) {
            double fx = 0;
            double fy = 0;
            int j;
            for (j = 0; j < count; j++) {
                if (i == j) {
                    continue;
                }
                double dx = p[j].x - p[i].x;
                double dy = p[j].y - p[i].y;
                double r = sqrt(dx * dx + dy * dy);
                if (r < min_dist) {
                    continue;
                }
                double f = G * p[i].mass * p[j].mass / (r * r);
                fx += f * dx / r;
                fy += f * dy / r;
            }
            double ax = fx / p[i].mass;
            double ay = fy / p[i].mass;
            p[i].vx += ax * dt;
            p[i].vy += ay * dt;
        }
        /* update the position of each planet */
        for (i = 0; i < count; i++) {
            p[i].x += p[i].vx * dt;
            p[i].y += p[i].vy * dt;
        }
        /* print the current position of the first planet */
        printf("%lf %lf\n", p[0].x, p[0].y);
        /* increase the simulation time */
        t += dt;
    }

    return EXIT_SUCCESS;
}