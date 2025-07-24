//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: inquisitive
#include <stdio.h>
#include <math.h>

#define GRAV_CONST 6.6743e-11

struct Vec {
    double x, y, z;
};

struct Body {
    struct Vec pos, vel, acc;
    double mass;
};

void update_acc(struct Body* b1, struct Body* b2) {
    struct Vec d;
    double dist, f;

    d.x = b2->pos.x - b1->pos.x;
    d.y = b2->pos.y - b1->pos.y;
    d.z = b2->pos.z - b1->pos.z;

    dist = sqrt(d.x*d.x + d.y*d.y + d.z*d.z);

    f = GRAV_CONST * b1->mass * b2->mass / (dist * dist);

    b1->acc.x += f * d.x / dist / b1->mass;
    b1->acc.y += f * d.y / dist / b1->mass;
    b1->acc.z += f * d.z / dist / b1->mass;
}

void update_vel(struct Body* b, double dt) {
    b->vel.x += b->acc.x * dt;
    b->vel.y += b->acc.y * dt;
    b->vel.z += b->acc.z * dt;
}

void update_pos(struct Body* b, double dt) {
    b->pos.x += b->vel.x * dt;
    b->pos.y += b->vel.y * dt;
    b->pos.z += b->vel.z * dt;
}

void reset_acc(struct Body* b) {
    b->acc.x = 0;
    b->acc.y = 0;
    b->acc.z = 0;
}

int main() {

    const int num_bodies = 5;
    struct Body bodies[num_bodies];

    // Create the sun
    bodies[0].pos.x = 0;
    bodies[0].pos.y = 0;
    bodies[0].pos.z = 0;

    bodies[0].vel.x = 0;
    bodies[0].vel.y = 0;
    bodies[0].vel.z = 0;

    bodies[0].acc.x = 0;
    bodies[0].acc.y = 0;
    bodies[0].acc.z = 0;

    bodies[0].mass = 1.989e30;

    // Create Earth
    bodies[1].pos.x = -1.471e11;
    bodies[1].pos.y = 0;
    bodies[1].pos.z = 0;

    bodies[1].vel.x = 0;
    bodies[1].vel.y = 2.978e4;
    bodies[1].vel.z = 0;

    bodies[1].acc.x = 0;
    bodies[1].acc.y = 0;
    bodies[1].acc.z = 0;

    bodies[1].mass = 5.972e24;

    // Create Venus
    bodies[2].pos.x = 1.074e11;
    bodies[2].pos.y = 0;
    bodies[2].pos.z = 0;

    bodies[2].vel.x = 0;
    bodies[2].vel.y = -3.504e4;
    bodies[2].vel.z = 0;

    bodies[2].acc.x = 0;
    bodies[2].acc.y = 0;
    bodies[2].acc.z = 0;

    bodies[2].mass = 4.867e24;

    // Create Mars
    bodies[3].pos.x = 0;
    bodies[3].pos.y = -2.279e11;
    bodies[3].pos.z = 0;

    bodies[3].vel.x = 2.41e4;
    bodies[3].vel.y = 0;
    bodies[3].vel.z = 0;

    bodies[3].acc.x = 0;
    bodies[3].acc.y = 0;
    bodies[3].acc.z = 0;

    bodies[3].mass = 6.390e23;

    // Create Jupiter
    bodies[4].pos.x = 0;
    bodies[4].pos.y = 0;
    bodies[4].pos.z = 7.785e11;

    bodies[4].vel.x = 1.307e4;
    bodies[4].vel.y = 0;
    bodies[4].vel.z = 0;

    bodies[4].acc.x = 0;
    bodies[4].acc.y = 0;
    bodies[4].acc.z = 0;

    bodies[4].mass = 1.898e27;

    const double dt = 3600*24; // 1 day

    for (int i = 0; i < num_bodies; i++) {
        reset_acc(&bodies[i]);
    }

    for (int i = 0; i < num_bodies; i++) {
        for (int j = i+1; j < num_bodies; j++) {
            update_acc(&bodies[i], &bodies[j]);
            update_acc(&bodies[j], &bodies[i]);
        }
    }

    for (int i = 0; i < num_bodies; i++) {
        update_vel(&bodies[i], dt);
    }

    for (int i = 0; i < num_bodies; i++) {
        update_pos(&bodies[i], dt);
    }

    return 0;
}