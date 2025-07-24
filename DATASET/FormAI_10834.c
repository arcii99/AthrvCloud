//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PLANETS 10

typedef struct Vector {
    double x;
    double y;
} Vector;

typedef struct Planet {
    Vector position;
    Vector velocity;
    Vector acceleration;
    double mass;
} Planet;

typedef struct SolarSystem {
    Planet planets[MAX_PLANETS];
    int count;
} SolarSystem;

const double GRAV_CONST = 6.67e-11;

void calculate_gravity(Planet *p1, Planet *p2) {
    Vector diff = { p2->position.x - p1->position.x, p2->position.y - p1->position.y };
    double distance = sqrt(diff.x * diff.x + diff.y * diff.y);
    double force = GRAV_CONST * (p1->mass * p2->mass) / (distance * distance);
    Vector direction = { diff.x / distance, diff.y / distance };
    Vector gravity1 = { direction.x * force / p1->mass, direction.y * force / p1->mass };
    Vector gravity2 = { direction.x * force / p2->mass, direction.y * force / p2->mass };
    p1->acceleration.x += gravity2.x;
    p1->acceleration.y += gravity2.y;
    p2->acceleration.x -= gravity1.x;
    p2->acceleration.y -= gravity1.y;
}

void calculate_accelerations(SolarSystem *system) {
    for (int i = 0; i < system->count; i++) {
        system->planets[i].acceleration.x = 0;
        system->planets[i].acceleration.y = 0;
        for (int j = 0; j < system->count; j++) {
            if (i != j) {
                calculate_gravity(&system->planets[i], &system->planets[j]);
            }
        }
    }
}

void update_positions(SolarSystem *system, double time_step) {
    for (int i = 0; i < system->count; i++) {
        Planet *p = &system->planets[i];
        p->position.x += p->velocity.x * time_step + 0.5 * p->acceleration.x * time_step * time_step;
        p->position.y += p->velocity.y * time_step + 0.5 * p->acceleration.y * time_step * time_step;
    }
}

void update_velocities(SolarSystem *system, double time_step) {
    for (int i = 0; i < system->count; i++) {
        Planet *p = &system->planets[i];
        p->velocity.x += p->acceleration.x * time_step;
        p->velocity.y += p->acceleration.y * time_step;
    }
}

void simulate(SolarSystem *system, double time_step, int num_steps) {
    for (int i = 0; i < num_steps; i++) {
        calculate_accelerations(system);
        update_positions(system, time_step);
        calculate_accelerations(system);
        update_velocities(system, time_step);
    }
}

int main() {
    SolarSystem solar_system = { .count = 2 };
    solar_system.planets[0] = (Planet) { .position = { 0, 0 }, .velocity = { 0, 0 }, .acceleration = { 0, 0 }, .mass = 1.989e30 };
    solar_system.planets[1] = (Planet) { .position = { 0, 149.6e9 }, .velocity = { 29.29e3, 0 }, .acceleration = { 0, 0 }, .mass = 5.97e24 };
    double time_step = 3600;
    int num_steps = 24 * 365;
    simulate(&solar_system, time_step, num_steps);
    printf("Position of the Earth: (%lf, %lf)\n", solar_system.planets[1].position.x, solar_system.planets[1].position.y);
    return 0;
}