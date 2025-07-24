//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 8
#define G_CONST 6.6743015e-11 // Gravitational Constant

struct vector {
    double x, y, z;
};

struct planet {
    char name[20];
    double mass;
    struct vector position;
    struct vector velocity;
    struct vector acceleration;
};

static const char* planet_names[NUM_PLANETS] = {
    "Mercury",
    "Venus",
    "Earth",
    "Mars",
    "Jupiter",
    "Saturn",
    "Uranus",
    "Neptune"
};

static const double planet_masses[NUM_PLANETS] = {
    0.330e24,
    4.87e24,
    5.97e24,
    0.642e24,
    1898e24,
    568e24,
    86.8e24,
    102e24
};

static const double planet_distances[NUM_PLANETS] = {
    57.9e6,
    108.2e6,
    149.6e6,
    227.9e6,
    778.5e6,
    1433.5e6,
    2872.5e6,
    4495.1e6
};

static const double planet_velocities[NUM_PLANETS] = {
    47.4e3,
    35.0e3,
    29.8e3,
    24.1e3,
    13.1e3,
    9.7e3,
    6.8e3,
    5.4e3
};

void set_initial_conditions(struct planet planets[NUM_PLANETS])
{
    int i;
    struct vector zero_vector = {0, 0, 0};

    for (i = 0; i < NUM_PLANETS; i++) {
        struct planet *p = &planets[i];

        sprintf(p->name, "%s", planet_names[i]);
        p->mass = planet_masses[i];
        p->position.x = planet_distances[i];
        p->velocity.y = planet_velocities[i];
        p->velocity.x = -p->velocity.y;
        p->position.y = p->position.z = p->velocity.z = 0;
        p->acceleration = zero_vector;
    }
}

void compute_forces(struct planet planets[NUM_PLANETS])
{
    int i, j;
    struct vector force_ij, distance_ij;
    double distance_ij_scalar, force_ij_scalar;

    for (i = 0; i < NUM_PLANETS; i++) {
        for (j = i+1; j < NUM_PLANETS; j++) {
            struct planet *p_i = &planets[i];
            struct planet *p_j = &planets[j];

            distance_ij.x = p_j->position.x - p_i->position.x;
            distance_ij.y = p_j->position.y - p_i->position.y;
            distance_ij.z = p_j->position.z - p_i->position.z;

            distance_ij_scalar = sqrt(distance_ij.x * distance_ij.x +
                                       distance_ij.y * distance_ij.y +
                                       distance_ij.z * distance_ij.z);

            force_ij_scalar = G_CONST * p_i->mass * p_j->mass / (distance_ij_scalar * distance_ij_scalar);

            force_ij.x = force_ij_scalar * distance_ij.x / distance_ij_scalar;
            force_ij.y = force_ij_scalar * distance_ij.y / distance_ij_scalar;
            force_ij.z = force_ij_scalar * distance_ij.z / distance_ij_scalar;

            p_i->acceleration.x += force_ij.x / p_i->mass;
            p_i->acceleration.y += force_ij.y / p_i->mass;
            p_i->acceleration.z += force_ij.z / p_i->mass;

            p_j->acceleration.x -= force_ij.x / p_j->mass;
            p_j->acceleration.y -= force_ij.y / p_j->mass;
            p_j->acceleration.z -= force_ij.z / p_j->mass;
        }
    }
}

void update_positions(struct planet planets[NUM_PLANETS], double delta_t)
{
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        struct planet *p = &planets[i];
        p->position.x += p->velocity.x * delta_t + 0.5 * p->acceleration.x * delta_t * delta_t;
        p->position.y += p->velocity.y * delta_t + 0.5 * p->acceleration.y * delta_t * delta_t;
        p->position.z += p->velocity.z * delta_t + 0.5 * p->acceleration.z * delta_t * delta_t;

        p->velocity.x += p->acceleration.x * delta_t;
        p->velocity.y += p->acceleration.y * delta_t;
        p->velocity.z += p->acceleration.z * delta_t;
    }
}

void print_planets(struct planet planets[NUM_PLANETS])
{
    printf("Solar System:\n");
    printf("Name         Mass (kg)    x (m)           y (m)           z (m)\n");

    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        struct planet *p = &planets[i];
        printf("%-12s %0.4e  %+0.4e  %+0.4e  %+0.4e\n",
               p->name, p->mass, p->position.x, p->position.y, p->position.z);
    }
}

int main(int argc, char **argv)
{
    double total_time = 365 * 24 * 3600; // 365 days in seconds
    double delta_t = 3600; // 1 hour in seconds
    struct planet planets[NUM_PLANETS];

    set_initial_conditions(planets);

    int num_steps = (int) round(total_time / delta_t);
    for (int step = 0; step < num_steps; step++) {
        compute_forces(planets);
        update_positions(planets, delta_t);
    }

    print_planets(planets);

    return 0;
}