//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: portable
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11      // gravitational constant

typedef struct {
    double x;
    double y;
} Vector;

typedef struct {
    Vector r;             // position vector
    Vector v;             // velocity vector
    double m;             // mass
} Body;

void update_position(Body *b, double dt) {
    // update position using current velocity
    b->r.x += b->v.x * dt;
    b->r.y += b->v.y * dt;
}

void update_velocity(Body *b1, Body *b2, double dt) {
    // calculate force between two bodies
    Vector rij = {b2->r.x - b1->r.x, b2->r.y - b1->r.y};
    double r = sqrt(rij.x * rij.x + rij.y * rij.y);
    double f = G * b1->m * b2->m / (r * r);
    Vector fij = {f * rij.x / r, f * rij.y / r};

    // update velocity using force
    b1->v.x += fij.x / b1->m * dt;
    b1->v.y += fij.y / b1->m * dt;
    b2->v.x -= fij.x / b2->m * dt;
    b2->v.y -= fij.y / b2->m * dt;
}

int main() {
    // initialize four bodies
    Body sun = {{0, 0}, {0, 0}, 1.989e30};
    Body earth = {{-147e9, 0}, {0, 30300}, 5.972e24};
    Body moon = {{-147e9, -385000}, {-1022, 0}, 7.342e22};
    Body mars = {{0, 228e9}, {-24000, 0}, 6.39e23};

    double dt = 3600;     // time step in seconds
    double t = 0;         // current time
    int n_steps = 365 * 24;  // number of time steps in one year

    // simulate one year
    for (int i = 0; i < n_steps; i++) {
        // update positions of all bodies
        update_position(&sun, dt);
        update_position(&earth, dt);
        update_position(&moon, dt);
        update_position(&mars, dt);

        // update velocities of earth and moon due to sun's gravity
        update_velocity(&earth, &sun, dt);
        update_velocity(&moon, &sun, dt);

        // update velocities of moon and earth due to each other's gravity
        update_velocity(&earth, &moon, dt);

        // update velocities of mars and sun due to each other's gravity
        update_velocity(&mars, &sun, dt);
        
        t += dt;
    }

    // print final positions of all bodies
    printf("Final positions of all bodies after one year:\n");
    printf("Sun: (%lf, %lf)\n", sun.r.x, sun.r.y);
    printf("Earth: (%lf, %lf)\n", earth.r.x, earth.r.y);
    printf("Moon: (%lf, %lf)\n", moon.r.x, moon.r.y);
    printf("Mars: (%lf, %lf)\n", mars.r.x, mars.r.y);

    return 0;
}