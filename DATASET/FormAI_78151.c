//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67430e-11

typedef struct {
    double x;
    double y;
} Vector2D;

typedef struct {
    Vector2D position;
    Vector2D velocity;
    double mass;
} Body;

typedef struct {
    Body* bodies;
    int num_bodies;
} SolarSystem;

static void simulate(SolarSystem* system, double dt, int iterations) {
    for (int iter = 0; iter < iterations; iter++) {
        for (int i = 0; i < system->num_bodies; i++) {
            for (int j = i + 1; j < system->num_bodies; j++) {
                Vector2D diff = { system->bodies[j].position.x - system->bodies[i].position.x,
                    system->bodies[j].position.y - system->bodies[i].position.y };
                double r = hypot(diff.x, diff.y);
                double f = G * system->bodies[i].mass * system->bodies[j].mass / (r * r);
                Vector2D n = { diff.x / r, diff.y / r };
                system->bodies[i].velocity.x += f * n.x / system->bodies[i].mass * dt;
                system->bodies[i].velocity.y += f * n.y / system->bodies[i].mass * dt;
                system->bodies[j].velocity.x -= f * n.x / system->bodies[j].mass * dt;
                system->bodies[j].velocity.y -= f * n.y / system->bodies[j].mass * dt;
            }
        }
        for (int i = 0; i < system->num_bodies; i++) {
            system->bodies[i].position.x += system->bodies[i].velocity.x * dt;
            system->bodies[i].position.y += system->bodies[i].velocity.y * dt;
        }
    }
}

int main() {
    srand(time(NULL));

    Body sun = { { 0, 0 }, { 0, 0 }, 1.989e+30 };

    Body planets[] = {
        { { 4.495e+10, 0 }, { 0, 30700 }, 3.29e+23 },
        { { 1.074e+11, 0 }, { 0, 24007 }, 4.87e+24 },
        { { 1.496e+11, 0 }, { 0, 29783 }, 5.97e+24 },
        { { 2.279e+11, 0 }, { 0, 24130 }, 6.42e+23 },
        { { 7.78e+11, 0 }, { 0, 13123 }, 1.9e+27 },
        { { 1.43e+12, 0 }, { 0, 9654 }, 5.68e+26 },
        { { 2.878e+12, 0 }, { 0, 6805 }, 8.68e+25 },
        { { 4.498e+12, 0 }, { 0, 5437 }, 1.03e+26 }
    };

    SolarSystem system = { NULL, 9 };
    system.bodies = (Body*)calloc(system.num_bodies, sizeof(Body));
    system.bodies[0] = sun;
    for (int i = 1; i < system.num_bodies; i++) {
        system.bodies[i] = planets[i - 1];
        system.bodies[i].position.x *= rand() % 100;
        system.bodies[i].position.y *= rand() % 100;
    }

    simulate(&system, 10000, 100000);

    free(system.bodies);
    return 0;
}