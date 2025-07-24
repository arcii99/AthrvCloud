//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

/* Constants for the simulation */
#define G 6.67e-11
#define SUN_MASS 1.989e30
#define EARTH_MASS 5.972e24
#define EARTH_DISTANCE 147e9
#define EARTH_VELOCITY 30e3

/* Structures to hold data for each celestial object */
typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Body;

/* Function to calculate distance between two bodies */
double distance(Body a, Body b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    double dz = a.z - b.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

/* Function to calculate force between two bodies */
double force(Body a, Body b) {
    double dist = distance(a, b);
    return G * a.mass * b.mass / (dist*dist);
}

/* Function to update velocity of a single body */
void update_velocity(Body *a, Body *b, double dt) {
    double f = force(*a, *b);
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double dz = b->z - a->z;
    double dist = distance(*a, *b);
    double ax = f * dx / (dist * a->mass);
    double ay = f * dy / (dist * a->mass);
    double az = f * dz / (dist * a->mass);
    a->vx += ax * dt;
    a->vy += ay * dt;
    a->vz += az * dt;
}

/* Function to update position of a single body */
void update_position(Body *a, double dt) {
    a->x += a->vx * dt;
    a->y += a->vy * dt;
    a->z += a->vz * dt;
}

int main() {
    /* Create the celestial bodies */
    Body sun, earth;
    sun.mass = SUN_MASS;
    sun.x = 0;
    sun.y = 0;
    sun.z = 0;
    sun.vx = 0;
    sun.vy = 0;
    sun.vz = 0;
    earth.mass = EARTH_MASS;
    earth.x = EARTH_DISTANCE;
    earth.y = 0;
    earth.z = 0;
    earth.vx = 0;
    earth.vy = EARTH_VELOCITY;
    earth.vz = 0;

    /* Run the simulation for one year */
    double dt = 1000; /* Time step is one day */
    double t = 0;
    double year = 365.25 * 24 * 3600;
    while (t < year) {
        /* Print the current positions of the bodies */
        printf("Time: %lf\n", t);
        printf("Sun: (%lf, %lf, %lf)\n", sun.x, sun.y, sun.z);
        printf("Earth: (%lf, %lf, %lf)\n", earth.x, earth.y, earth.z);

        /* Update the velocities of the bodies */
        update_velocity(&earth, &sun, dt);
        update_velocity(&sun, &earth, dt);

        /* Update the positions of the bodies */
        update_position(&earth, dt);
        update_position(&sun, dt);

        /* Increment the time */
        t += dt;
    }

    return 0;
}