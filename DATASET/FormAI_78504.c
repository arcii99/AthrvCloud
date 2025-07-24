//FormAI DATASET v1.0 Category: Physics simulation ; Style: medieval
#include <stdio.h>
#include <math.h>
#include <time.h>

#define GRAV_CONST 6.674e-11
#define GROUND_LEVEL 0

struct Vector {
    double x, y;
};

struct Body {
    struct Vector pos;
    struct Vector vel;
    struct Vector force;
    double mass;
};

double distance(struct Body *a, struct Body *b) {
    double diff_x = a->pos.x - b->pos.x;
    double diff_y = a->pos.y - b->pos.y;
    return sqrt(diff_x * diff_x + diff_y * diff_y);
}

void gravitational_force(struct Body *a, struct Body *b) {
    double r = distance(a, b);
    double f = GRAV_CONST * a->mass * b->mass / (r * r);
    double theta = atan2(b->pos.y - a->pos.y, b->pos.x - a->pos.x);
    a->force.x += f * cos(theta);
    a->force.y += f * sin(theta);
}

void update_body_state(struct Body *b, double delta_t) {
    double total_force = sqrt(b->force.x * b->force.x + b->force.y * b->force.y);
    double accel = total_force / b->mass;
    double accel_x = accel * cos(atan2(b->force.y, b->force.x));
    double accel_y = accel * sin(atan2(b->force.y, b->force.x));
    b->pos.x += b->vel.x * delta_t + 0.5 * accel_x * delta_t * delta_t;
    b->pos.y += b->vel.y * delta_t + 0.5 * accel_y * delta_t * delta_t;
    b->vel.x += accel_x * delta_t;
    b->vel.y += accel_y * delta_t;
    b->force.x = 0.0;
    b->force.y = 0.0;
}

int main() {
    srand(time(NULL));
    struct Body sun = {
        .pos = {0, 0},
        .vel = {0, 0},
        .force = {0, 0},
        .mass = 1.9891e30
    };
    struct Body planet = {
        .pos = {100, 0},
        .vel = {0, 30000},
        .force = {0, 0},
        .mass = 5.9722e24
    };
    double delta_t = 0.1;
    double simulation_time = 100000.0;
    for (double time = 0; time < simulation_time; time += delta_t) {
        gravitational_force(&sun, &planet);
        gravitational_force(&planet, &sun);
        update_body_state(&sun, delta_t);
        update_body_state(&planet, delta_t);
        if (planet.pos.y <= GROUND_LEVEL) {
            printf("The planet has crashed into the ground!");
            break;
        }
        printf("Planet position: (%f, %f) Velocity: (%f, %f)\n", planet.pos.x, planet.pos.y, planet.vel.x, planet.vel.y);
    }
    return 0;
}