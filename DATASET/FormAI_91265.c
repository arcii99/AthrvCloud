//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Gconstants 6.6743e-11

struct vector {
    double x, y, z;
};

struct planet {
    char name[20];
    double mass;
    struct vector position;
    struct vector velocity;
};

double distance(struct vector v1, struct vector v2) {
    double xdiff = v2.x - v1.x;
    double ydiff = v2.y - v1.y;
    double zdiff = v2.z - v1.z;
    return sqrt(xdiff*xdiff + ydiff*ydiff + zdiff*zdiff);
}

struct vector direction(struct vector v1, struct vector v2) {
    double dist = distance(v1, v2);
    struct vector dir;
    dir.x = (v2.x - v1.x) / dist;
    dir.y = (v2.y - v1.y) / dist;
    dir.z = (v2.z - v1.z) / dist;
    return dir;
}

struct vector force(struct planet p1, struct planet p2) {
    double dist = distance(p1.position, p2.position);
    struct vector force;
    double magnitude = Gconstants * p1.mass * p2.mass / (dist * dist);
    struct vector dir = direction(p1.position, p2.position);
    force.x = dir.x * magnitude;
    force.y = dir.y * magnitude;
    force.z = dir.z * magnitude;
    return force;
}

void update(struct planet *p, struct vector totalforce, double timestep) {
    struct vector acceleration;
    acceleration.x = totalforce.x / p->mass;
    acceleration.y = totalforce.y / p->mass;
    acceleration.z = totalforce.z / p->mass;
    p->velocity.x += timestep * acceleration.x;
    p->velocity.y += timestep * acceleration.y;
    p->velocity.z += timestep * acceleration.z;
    p->position.x += timestep * p->velocity.x;
    p->position.y += timestep * p->velocity.y;
    p->position.z += timestep * p->velocity.z;
}

int main() {
    struct planet earth = {"Earth", 5.972e24, {0, 0, 0}, {0, 0, 0}};
    struct planet moon = {"Moon", 7.342e22, {384400000, 0, 0}, {0, 1022, 0}};
    double timestep = 1000;
    int numsteps = 365 * 24 * 60 * 60 / timestep;
    int i;
    for (i=0; i<numsteps; i++) {
        struct vector totalforce = force(earth, moon);
        update(&earth, totalforce, timestep);
        update(&moon, totalforce, timestep);
        printf("Earth's position: (%.0f, %.0f, %.0f)\n", earth.position.x, earth.position.y, earth.position.z);
        printf("Moon's position: (%.0f, %.0f, %.0f)\n\n", moon.position.x, moon.position.y, moon.position.z);
    }
    return 0;
}