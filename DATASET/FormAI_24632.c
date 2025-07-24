//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 4
#define GRAVITY 6.67e-11
#define TIME_STEP 86400.0

struct Vector {
    double x;
    double y;
    double z;
};

struct Planet {
    char name[50];
    double mass;
    struct Vector position;
    struct Vector velocity;
};

void calculate_gravity(struct Planet *planet1, struct Planet *planet2, struct Vector *force) {
    double distance_squared = pow((planet1->position.x - planet2->position.x), 2) + pow((planet1->position.y - planet2->position.y), 2) + pow((planet1->position.z - planet2->position.z), 2);
    double force_magnitude = GRAVITY * planet1->mass * planet2->mass / distance_squared;

    force->x = force_magnitude * (planet2->position.x - planet1->position.x) / sqrt(distance_squared);
    force->y = force_magnitude * (planet2->position.y - planet1->position.y) / sqrt(distance_squared);
    force->z = force_magnitude * (planet2->position.z - planet1->position.z) / sqrt(distance_squared);
}

void update_planet(struct Planet *planet, struct Vector *force) {
    struct Vector acceleration;
    acceleration.x = force->x / planet->mass;
    acceleration.y = force->y / planet->mass;
    acceleration.z = force->z / planet->mass;

    planet->velocity.x += acceleration.x * TIME_STEP;
    planet->velocity.y += acceleration.y * TIME_STEP;
    planet->velocity.z += acceleration.z * TIME_STEP;

    planet->position.x += planet->velocity.x * TIME_STEP;
    planet->position.y += planet->velocity.y * TIME_STEP;
    planet->position.z += planet->velocity.z * TIME_STEP;
}

int main() {
    struct Planet planets[NUM_PLANETS] = {
        {"Mercury", 3.30e23, {0, 0, 0}, {0, 0, 0}},
        {"Venus", 4.87e24, {1.08e11, 0, 0}, {0, 35.0e3, 0}},
        {"Earth", 5.97e24, {1.50e11, 0, 0}, {0, 29.29e3, 0}},
        {"Mars", 6.39e23, {2.28e11, 0, 0}, {0, 21.97e3, 0}}
    };

    int i, j, k;
    struct Vector force;

    for (i = 0; i < NUM_PLANETS; i++) {
        printf("%s: (%.2e, %.2e, %.2e)\n", planets[i].name, planets[i].position.x, planets[i].position.y, planets[i].position.z);
    }

    for (k = 0; k < 365; k++) { // simulate 1 year
        for (i = 0; i < NUM_PLANETS; i++) {
            force.x = 0;
            force.y = 0;
            force.z = 0;

            for (j = 0; j < NUM_PLANETS; j++) {
                if (j != i) {
                    calculate_gravity(&planets[i], &planets[j], &force);
                }
            }

            update_planet(&planets[i], &force);
        }
    }

    for (i = 0; i < NUM_PLANETS; i++) {
        printf("%s: (%.2e, %.2e, %.2e)\n", planets[i].name, planets[i].position.x, planets[i].position.y, planets[i].position.z);
    }

    return 0;
}