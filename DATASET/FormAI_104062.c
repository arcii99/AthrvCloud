//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: real-life
#include <stdio.h>
#include <math.h>

/* This program simulates the solar system, where the sun is at the center of the system and the planets orbit around it. */

#define G (6.67430e-11) /* gravitational constant */
#define SUN_MASS (1.989e30) /* mass of the sun */
#define EARTH_DIST (147.09e9) /* average distance between Earth and Sun */
#define EARTH_VEL (29.78e3) /* average velocity of Earth around the Sun */

typedef struct {
    char name[10];
    double mass;
    double radius;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Body; /* define struct for body object */

double distance(Body a, Body b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2));
} /* calculate the distance between two bodies */

void simulate(Body *bodies, int num_bodies, double time_step) {
    /* simulate the movement of the bodies for a time step */
    int i, j;
    double dx, dy, dz, dist, force, accel_x, accel_y, accel_z;
    for (i = 0; i < num_bodies; i++) {
        accel_x = accel_y = accel_z = 0;
        for (j = 0; j < num_bodies; j++) {
            if (i == j) {
                continue; /* ignore force on itself */
            }
            dist = distance(bodies[i], bodies[j]);
            force = G * bodies[i].mass * bodies[j].mass / pow(dist, 2); /* calculate the force between two bodies */
            dx = bodies[j].x - bodies[i].x;
            dy = bodies[j].y - bodies[i].y;
            dz = bodies[j].z - bodies[i].z;
            accel_x += force * dx / dist / bodies[i].mass;
            accel_y += force * dy / dist / bodies[i].mass;
            accel_z += force * dz / dist / bodies[i].mass;
        }
        /* update velocity and position */
        bodies[i].vx += time_step * accel_x;
        bodies[i].vy += time_step * accel_y;
        bodies[i].vz += time_step * accel_z;
        bodies[i].x += time_step * bodies[i].vx;
        bodies[i].y += time_step * bodies[i].vy;
        bodies[i].z += time_step * bodies[i].vz;
    }
}

int main() {
    /* initialize the bodies */
    Body sun = {"Sun", SUN_MASS, 696340e3, 0, 0, 0, 0, 0, 0};
    Body earth = {"Earth", 5.97e24, 6.371e6, 0, EARTH_DIST, 0, EARTH_VEL, 0, 0};
    Body moon = {"Moon", 7.34e22, 1.74e6, 0, EARTH_DIST - 3.84e8, 0, EARTH_VEL + 1.023e3, 0, 0};
    Body mars = {"Mars", 6.39e23, 3.3895e6, 0, -2.28e11, 0, 0, 2.41e3, 0};
    int num_bodies = 4;
    Body bodies[] = {sun, earth, moon, mars};
    double time_step = 86400; /* one day simulation time step */
    int num_steps = 365; /* number of simulation steps to run */
    int i, j;
    for (i = 0; i < num_steps; i++) {
        printf("Day %d\n", i + 1);
        for (j = 0; j < num_bodies; j++) {
            printf("%s position: (%e, %e, %e)\n", bodies[j].name, bodies[j].x, bodies[j].y, bodies[j].z);
        }
        simulate(bodies, num_bodies, time_step);
    }
    return 0;
}