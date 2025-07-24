//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY 6.67e-11
#define TIMESTEP 86400

typedef struct {
    double x;
    double y;
} vector_t;

typedef struct {
    vector_t pos;
    vector_t vel;
    double mass;
} body_t;

vector_t acceleration(body_t *body, body_t *other) {
    vector_t direction;
    vector_t force;
    double distance;
    double magnitude;

    direction.x = other->pos.x - body->pos.x;
    direction.y = other->pos.y - body->pos.y;

    distance = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    magnitude = (GRAVITY * body->mass * other->mass) / pow(distance, 2);

    force.x = magnitude * direction.x / distance;
    force.y = magnitude * direction.y / distance;

    return (vector_t) {
        .x = force.x / body->mass,
        .y = force.y / body->mass
    };
}

void move(body_t *body, vector_t acceleration) {
    body->vel.x += acceleration.x * TIMESTEP;
    body->vel.y += acceleration.y * TIMESTEP;

    body->pos.x += body->vel.x * TIMESTEP;
    body->pos.y += body->vel.y * TIMESTEP;
}

int main() {
    body_t sun = {
        .pos = (vector_t) { .x = 0, .y = 0 },
        .vel = (vector_t) { .x = 0, .y = 0 },
        .mass = 1.989e30
    };

    body_t earth = {
        .pos = (vector_t) { .x = 1.496e11, .y = 0 },
        .vel = (vector_t) { .x = 0, .y = 29783 },
        .mass = 5.972e24
    };

    body_t moon = {
        .pos = (vector_t) { .x = 1.496e11 + 384400e3, .y = 0 },
        .vel = (vector_t) { .x = 0, .y = 29783 + 1022 },
        .mass = 7.342e22
    };

    for (int i = 0; i < 365; i++) {
        vector_t earth_acc = acceleration(&earth, &sun);
        vector_t moon_acc = acceleration(&moon, &sun);

        vector_t earth_moon_direction = {
            .x = moon.pos.x - earth.pos.x,
            .y = moon.pos.y - earth.pos.y
        };

        double distance_em = sqrt(pow(earth_moon_direction.x, 2) + pow(earth_moon_direction.y, 2));

        vector_t moon_earth_acc = (vector_t) {
            .x = GRAVITY * earth.mass * moon.mass * earth_moon_direction.x / pow(distance_em, 3),
            .y = GRAVITY * earth.mass * moon.mass * earth_moon_direction.y / pow(distance_em, 3)
        };

        vector_t earth_total_acc = {
            .x = earth_acc.x + moon_earth_acc.x,
            .y = earth_acc.y + moon_earth_acc.y
        };

        vector_t moon_total_acc = {
            .x = moon_acc.x - moon_earth_acc.x / moon.mass,
            .y = moon_acc.y - moon_earth_acc.y / moon.mass
        };

        move(&earth, earth_total_acc);
        move(&moon, moon_total_acc);

        printf("Day %d\n", i + 1);
        printf("Earth: (%e, %e)\n", earth.pos.x, earth.pos.y);
        printf("Moon: (%e, %e)\n", moon.pos.x, moon.pos.y);
        printf("\n");
    }

    return 0;
}