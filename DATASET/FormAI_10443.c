//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 3
#define G_CONSTANT 6.67430e-11

typedef struct {
    double x, y, z;
} Vector;

typedef struct {
    double mass;
    Vector pos;
    Vector vel;
} Planet;

static Planet planets[NUM_PLANETS] = 
    {
        { .mass = 5.97e24, .pos = {0, 0, 0}, .vel = {0, 0, 0} },    // Earth
        { .mass = 1.99e30, .pos = {1.496e11, 0, 0}, .vel = {0, 30000, 0} },   // Sun
        { .mass = 3.30e23, .pos = {1.496e11 + 384400000, 0, 0}, .vel = {0, 3070, 0} }  // Moon
    };

static void update_velocity(double t_delta, Planet *p1, Planet *p2) {
    Vector dir;
    double dist, force;

    dir.x = p1->pos.x - p2->pos.x;
    dir.y = p1->pos.y - p2->pos.y;
    dir.z = p1->pos.z - p2->pos.z;

    dist = sqrt(pow(dir.x, 2) + pow(dir.y, 2) + pow(dir.z, 2));
    force = G_CONSTANT * p1->mass * p2->mass / pow(dist, 2);

    p1->vel.x -= dir.x / dist * force / p1->mass * t_delta;
    p1->vel.y -= dir.y / dist * force / p1->mass * t_delta;
    p1->vel.z -= dir.z / dist * force / p1->mass * t_delta;

    p2->vel.x += dir.x / dist * force / p2->mass * t_delta;
    p2->vel.y += dir.y / dist * force / p2->mass * t_delta;
    p2->vel.z += dir.z / dist * force / p2->mass * t_delta;
}

static void update_position(double t_delta, Planet *p) {
    p->pos.x += p->vel.x * t_delta;
    p->pos.y += p->vel.y * t_delta;
    p->pos.z += p->vel.z * t_delta;
}

static void simulate(double t_delta, int num_steps) {
    int i, j, k;
    for (i = 0; i < num_steps; i++) {
        for (j = 0; j < NUM_PLANETS; j++) {
            for (k = j + 1; k < NUM_PLANETS; k++) {
                update_velocity(t_delta, &planets[j], &planets[k]);
            }
        }

        for (j = 0; j < NUM_PLANETS; j++) {
            update_position(t_delta, &planets[j]);
        }
    }
}

int main(void) {
    simulate(3600, 24*365);
    printf("Earth: (%e, %e, %e)\n", planets[0].pos.x, planets[0].pos.y, planets[0].pos.z);
    printf("Sun: (%e, %e, %e)\n", planets[1].pos.x, planets[1].pos.y, planets[1].pos.z);
    printf("Moon: (%e, %e, %e)\n", planets[2].pos.x, planets[2].pos.y, planets[2].pos.z);
    return 0;
}