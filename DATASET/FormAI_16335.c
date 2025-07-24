//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: protected
#include <stdio.h>
#include <math.h>

#define GRAVITY_CONSTANT 6.67430e-11

typedef struct {
    double x, y, z;
} vector;

typedef struct {
    double mass;
    vector position;
    vector velocity;
} body;

vector gravity_force(body *b1, body *b2) {
    double dx = b2->position.x - b1->position.x;
    double dy = b2->position.y - b1->position.y;
    double dz = b2->position.z - b1->position.z;
    double dist_sq = dx*dx + dy*dy + dz*dz;
    double force_magnitude = (GRAVITY_CONSTANT * b1->mass * b2->mass) / dist_sq;
    double force_x = force_magnitude * dx / sqrt(dist_sq);
    double force_y = force_magnitude * dy / sqrt(dist_sq);
    double force_z = force_magnitude * dz / sqrt(dist_sq);
    vector force = {force_x, force_y, force_z};
    return force;
}

void update_velocity(body *b, vector acceleration, double time_step) {
    b->velocity.x += acceleration.x * time_step;
    b->velocity.y += acceleration.y * time_step;
    b->velocity.z += acceleration.z * time_step;
}

void update_position(body *b, double time_step) {
    b->position.x += b->velocity.x * time_step;
    b->position.y += b->velocity.y * time_step;
    b->position.z += b->velocity.z * time_step;
}

void apply_gravity(body *bodies, int num_bodies, double time_step) {
    for (int i = 0; i < num_bodies; i++) {
        vector total_force = {0, 0, 0};
        for (int j = 0; j < num_bodies; j++) {
            if (i == j) {
                continue;
            }
            vector force = gravity_force(&bodies[i], &bodies[j]);
            total_force.x += force.x;
            total_force.y += force.y;
            total_force.z += force.z;
        }
        vector acceleration = {total_force.x / bodies[i].mass, total_force.y / bodies[i].mass, total_force.z / bodies[i].mass};
        update_velocity(&bodies[i], acceleration, time_step);
        update_position(&bodies[i], time_step);
    }
}

int main() {
    body bodies[] = {
        {5.97e24, {0, 0, 0}, {0, 0, 0}}, // Earth
        {7.34e22, {384400000, 0, 0}, {0, 1022.057, 0}} // Moon
    };
    int num_bodies = sizeof(bodies) / sizeof(body);
    double time_step = 1.0; // seconds
    int num_steps = 10;
    for (int i = 0; i < num_steps; i++) {
        printf("Step %d:\n", i + 1);
        for (int j = 0; j < num_bodies; j++) {
            printf("Body %d\n", j + 1);
            printf("\tPosition: (%g, %g, %g)\n", bodies[j].position.x, bodies[j].position.y, bodies[j].position.z);
            printf("\tVelocity: (%g, %g, %g)\n", bodies[j].velocity.x, bodies[j].velocity.y, bodies[j].velocity.z);
        }
        apply_gravity(bodies, num_bodies, time_step);
    }
    return 0;
}