//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11
#define TIME_STEP 86400

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

typedef struct body {
    char name[20];
    vector pos;
    vector vel;
    vector accel;
    double mass;
} body;

void update_accel(body *bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        body *b1 = &bodies[i];
        b1->accel.x = 0;
        b1->accel.y = 0;
        b1->accel.z = 0;

        for (int j = 0; j < num_bodies; j++) {
            if (i == j) {
                continue;
            }

            body *b2 = &bodies[j];

            double dx = b2->pos.x - b1->pos.x;
            double dy = b2->pos.y - b1->pos.y;
            double dz = b2->pos.z - b1->pos.z;

            double dist = sqrt(dx * dx + dy * dy + dz * dz);

            double force = G * b1->mass * b2->mass / (dist * dist);

            b1->accel.x += force * dx / dist / b1->mass;
            b1->accel.y += force * dy / dist / b1->mass;
            b1->accel.z += force * dz / dist / b1->mass;
        }
    }
}

void update_vel(body *b, double dt) {
    b->vel.x += b->accel.x * dt;
    b->vel.y += b->accel.y * dt;
    b->vel.z += b->accel.z * dt;
}

void update_pos(body *b, double dt) {
    b->pos.x += b->vel.x * dt;
    b->pos.y += b->vel.y * dt;
    b->pos.z += b->vel.z * dt;
}

void simulate(body *bodies, int num_bodies, double sim_time, double dt) {
    int num_steps = sim_time / dt;

    for (int i = 0; i < num_steps; i++) {
        update_accel(bodies, num_bodies);

        for (int j = 0; j < num_bodies; j++) {
            update_vel(&bodies[j], dt);
        }

        for (int j = 0; j < num_bodies; j++) {
            update_pos(&bodies[j], dt);
        }
    }
}

int main() {
    body sun = {"Sun", {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, 1.989e30};
    body earth = {"Earth", {1.496e11, 0, 0}, {0, 29.783e3, 0}, {0, 0, 0}, 5.972e24};
    body moon = {"Moon", {1.496e11 + 3.844e8, 0, 0}, {0, 1.022e3 + 29.783e3, 0}, {0, 0, 0}, 7.342e22};
    body mars = {"Mars", {0, 2.279e11, 0}, {-24.077e3, 0, 0}, {0, 0, 0}, 6.39e23};

    body bodies[] = {sun, earth, moon, mars};

    int num_bodies = sizeof(bodies) / sizeof(body);

    double sim_time = 365 * 24 * 60 * 60;
    double dt = TIME_STEP;

    simulate(bodies, num_bodies, sim_time, dt);

    for (int i = 0; i < num_bodies; i++) {
        printf("%s: (%g, %g, %g)\n", bodies[i].name, bodies[i].pos.x, bodies[i].pos.y, bodies[i].pos.z);
    }

    return 0;
}