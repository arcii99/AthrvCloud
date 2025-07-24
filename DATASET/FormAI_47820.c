//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11      // Gravitational constant
#define TIME_STEP 86400   // One day in seconds

typedef struct {
    double x;
    double y;
    double z;
} vector_t;

typedef struct {
    double mass;
    vector_t pos;
    vector_t vel;
} planet_t;

void update_velocity(planet_t *p1, planet_t *p2) {
    double dx = p1->pos.x - p2->pos.x;
    double dy = p1->pos.y - p2->pos.y;
    double dz = p1->pos.z - p2->pos.z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);
    double force = G * p1->mass * p2->mass / (distance*distance);
    double acceleration = force / p1->mass;
    p1->vel.x -= dx * acceleration / distance;
    p1->vel.y -= dy * acceleration / distance;
    p1->vel.z -= dz * acceleration / distance;
}

void update_position(planet_t *p) {
    p->pos.x += p->vel.x * TIME_STEP;
    p->pos.y += p->vel.y * TIME_STEP;
    p->pos.z += p->vel.z * TIME_STEP;
}

int main() {
    planet_t earth = { 5.97e24, { 0, 0, 0 }, { 0, 0, 0 } };
    planet_t moon = { 7.35e22, { 384400000, 0, 0 }, { 0, 1022, 0 } };

    for (int i = 0; i < 365; i++) {  // simulate one year
        update_velocity(&earth, &moon);
        update_velocity(&moon, &earth);
        update_position(&earth);
        update_position(&moon);
        printf("Day %d: Earth (%f, %f, %f), Moon (%f, %f, %f)\n", i, earth.pos.x, earth.pos.y, earth.pos.z, moon.pos.x, moon.pos.y, moon.pos.z);
    }

    return 0;
}