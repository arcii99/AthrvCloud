//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743 * pow(10, -11) // gravitational constant

typedef struct {
    double x;
    double y;
    double z;
} vector3d;

typedef struct {
    double mass;
    vector3d pos;
    vector3d vel;
} body;

void update_velocity(body *a, body *b, double dt) {
    vector3d r = {b->pos.x - a->pos.x, b->pos.y - a->pos.y, b->pos.z - a->pos.z};
    double distance = sqrt(pow(r.x, 2) + pow(r.y, 2) + pow(r.z, 2));
    double f = G * a->mass * b->mass / pow(distance, 2);
    vector3d force = {f * r.x / distance, f * r.y / distance, f * r.z / distance};
    vector3d acceleration_a = {force.x / a->mass, force.y / a->mass, force.z / a->mass};
    vector3d acceleration_b = {-force.x / b->mass, -force.y / b->mass, -force.z / b->mass};
    a->vel.x += acceleration_a.x * dt;
    a->vel.y += acceleration_a.y * dt;
    a->vel.z += acceleration_a.z * dt;
    b->vel.x += acceleration_b.x * dt;
    b->vel.y += acceleration_b.y * dt;
    b->vel.z += acceleration_b.z * dt;
}

void update_position(body *a, double dt) {
    a->pos.x += a->vel.x * dt;
    a->pos.y += a->vel.y * dt;
    a->pos.z += a->vel.z * dt;
}

void simulate(body *bodies, int num_bodies, double dt, int num_steps) {
    for (int i = 0; i < num_steps; i++) {
        for (int j = 0; j < num_bodies; j++) {
            for (int k = j + 1; k < num_bodies; k++) {
                update_velocity(&bodies[j], &bodies[k], dt);
            }
        }
        for (int j = 0; j < num_bodies; j++) {
            update_position(&bodies[j], dt);
        }
    }
}

int main() {
    body sun = {1.989 * pow(10, 30), {0, 0, 0}, {0, 0, 0}};
    body earth = {5.972 * pow(10, 24), {1.496 * pow(10, 11), 0, 0}, {0, 29783, 0}};
    body moon = {7.342 * pow(10, 22), {1.496 * pow(10, 11) + 3.844 * pow(10, 8), 0, 0}, {0, 29783 + 1023, 0}};
    body mars = {6.39 * pow(10, 23), {0, 0, 2.279 * pow(10, 11)}, {24007, 0, 0}};
    body jupiter = {1.899 * pow(10, 27), {0, 0, 7.785 * pow(10, 11)}, {13069, 0, 0}};
    body saturn = {5.683 * pow(10, 26), {0, 0, 1.429 * pow(10, 12)}, {9691, 0, 0}};
    body uranus = {8.681 * pow(10, 25), {0, 0, 2.871 * pow(10, 12)}, {6813, 0, 0}};
    body neptune = {1.024 * pow(10, 26), {0, 0, 4.498 * pow(10, 12)}, {5433, 0, 0}};
    body bodies[] = {sun, earth, moon, mars, jupiter, saturn, uranus, neptune};
    int num_bodies = 8;
    double dt = 86400;
    int num_steps = 365;
    simulate(bodies, num_bodies, dt, num_steps);
    return 0;
}