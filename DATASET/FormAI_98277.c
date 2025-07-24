//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: calm
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define G 6.67428e-11
#define SOLAR_MASS 1.98892e30
#define EARTH_MOON_MASS 5.97219e24 + 7.349e22
#define EARTH_RADIUS 6.371e6
#define PI 3.14159265359

typedef struct {
    double x;
    double y;
} vector;

typedef struct {
    vector position;
    vector velocity;
    double mass;
} body;

void update_position(body *b, double timestep) {
    b->position.x += b->velocity.x * timestep;
    b->position.y += b->velocity.y * timestep;
}

void update_velocity(body *b, vector force, double timestep) {
    b->velocity.x += force.x * timestep / b->mass;
    b->velocity.y += force.y * timestep / b->mass;
}

vector compute_force(body *a, body *b) {
    vector r;
    r.x = b->position.x - a->position.x;
    r.y = b->position.y - a->position.y;
    double distance = sqrt(pow(r.x, 2) + pow(r.y, 2));
    double magnitude = G * a->mass * b->mass / pow(distance, 2);
    r.x *= magnitude / distance;
    r.y *= magnitude / distance;
    return r;
}

void simulate(body *bodies, int num_bodies, double timestep, int num_steps) {
    for(int step = 0; step < num_steps; step++) {
        vector forces[num_bodies];
        for(int i = 0; i < num_bodies; i++) {
            body *a = &bodies[i];
            vector total_force = {0,0};
            for(int j = 0; j < num_bodies; j++) {
                if(i == j) continue;
                body *b = &bodies[j];
                vector force = compute_force(a, b);
                total_force.x += force.x;
                total_force.y += force.y;
            }
            forces[i] = total_force;
        }
        for(int i = 0; i < num_bodies; i++) {
            body *b = &bodies[i];
            vector force = forces[i];
            update_velocity(b, force, timestep);
        }
        for(int i = 0; i < num_bodies; i++) {
            body *b = &bodies[i];
            update_position(b, timestep);
        }
    }
}

int main() {
    srand(time(NULL));

    body sun = {{0, 0}, {0, 0}, SOLAR_MASS};
    body earth = {{149.6e9, 0}, {0, 29.29e3}, EARTH_MOON_MASS * 0.97};
    body moon = {{149.6e9+384.4e6, 0}, {0, 29.29e3 + 1022}, EARTH_MOON_MASS * 0.03};
    body mars = {{-227.9e9, 0}, {0, -24.077e3}, 6.39e23};
    body venus = {{108.2e9, 0}, {0, 35.02e3}, 4.87e24};
    body mercury = {{46.0e9, 0}, {0, 47.362e3}, 3.285e23};
    body jupiter = {{-778.5e9, 0}, {0, -13.07e3}, 1.898e27};
    body saturn = {{-1433.5e9, 0}, {0, -9.69e3}, 5.683e26};
    body uranus = {{-2872.5e9, 0}, {0, -6.81e3}, 8.681e25};
    body neptune = {{-4495.1e9, 0}, {0, -5.43e3}, 1.024e26};

    body bodies[] = {
            sun,
            earth,
            moon,
            mars,
            venus,
            mercury,
            jupiter,
            saturn,
            uranus,
            neptune
    };

    int num_bodies = 10;

    double timestep = 3600*24*365;
    int num_steps = 10000;

    simulate(bodies, num_bodies, timestep, num_steps);

    for(int i = 0; i < num_bodies; i++) {
        printf("Body %d position: %f, %f\n", i, bodies[i].position.x, bodies[i].position.y);
    }

    return 0;
}