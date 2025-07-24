//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11

typedef struct {
    double mass;
    double pos_x;
    double pos_y;
    double vel_x;
    double vel_y;
    double acc_x;
    double acc_y;
} body;

void update_velocity(body *b1, body *b2, double dt) {
    double dist_x = b2 -> pos_x - b1 -> pos_x;
    double dist_y = b2 -> pos_y - b1 -> pos_y;
    double dist = sqrt(dist_x * dist_x + dist_y * dist_y);
    double force = G * b1 -> mass * b2 -> mass / (dist * dist);
    double fx = force * dist_x / dist;
    double fy = force * dist_y / dist;
    b1 -> vel_x += fx / b1 -> mass * dt;
    b1 -> vel_y += fy / b1 -> mass * dt;
    b2 -> vel_x -= fx / b2 -> mass * dt;
    b2 -> vel_y -= fy / b2 -> mass * dt;
}

void update_position(body *b, double dt) {
    b -> pos_x += b -> vel_x * dt;
    b -> pos_y += b -> vel_y * dt;
}

void update_acceleration(body *b1, body *b2) {
    double dist_x = b2 -> pos_x - b1 -> pos_x;
    double dist_y = b2 -> pos_y - b1 -> pos_y;
    double dist = sqrt(dist_x * dist_x + dist_y * dist_y);
    double force = G * b2 -> mass / (dist * dist);
    double fx = force * dist_x / dist;
    double fy = force * dist_y / dist;
    b1 -> acc_x += fx / b1 -> mass;
    b1 -> acc_y += fy / b1 -> mass;    
}

void update_all(body *bodies, int num_bodies, double dt) {
    int i, j;
    for (i = 0; i < num_bodies; i++) {
        bodies[i].acc_x = 0.0;
        bodies[i].acc_y = 0.0;
    }
    for (i = 0; i < num_bodies; i++) {
        for (j = i + 1; j < num_bodies; j++) {
            update_acceleration(&bodies[i], &bodies[j]);
            update_acceleration(&bodies[j], &bodies[i]);
            update_velocity(&bodies[i], &bodies[j], dt);
        }
        update_position(&bodies[i], dt);
    }    
}

int main() {
    body bodies[] = {
        {5.97e24, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        {1000.0, 3000.0, 5000.0, 50.0, 0.0, 0.0, 0.0},
        {2000.0, -4000.0, 2000.0, 0.0, -50.0, 0.0, 0.0},
    };
    int num_bodies = sizeof(bodies) / sizeof(body);
    double dt = 60.0 * 60.0;
    int n_steps = 24;
    int i, j;
    for (i = 0; i < n_steps; i++) {
        printf("Step %d:\n", i);
        for (j = 0; j < num_bodies; j++) {
            printf("Body %d, mass = %gkg, pos = (%g, %g)m, vel = (%g, %g)m/s\n", j, bodies[j].mass, bodies[j].pos_x, bodies[j].pos_y, bodies[j].vel_x, bodies[j].vel_y);
        }
        update_all(bodies, num_bodies, dt);
    }
    return 0;
}