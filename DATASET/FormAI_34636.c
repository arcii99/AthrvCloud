//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67428e-11 // gravitational constant
#define dt 0.01 // time step
#define num_of_bodies 3 // number of bodies

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double fx, fy; // force
    double mass; // mass
} body_t;

void update_forces(body_t *bodies) {
    int i, j;

    for (i = 0; i < num_of_bodies; i++) {
        bodies[i].fx = bodies[i].fy = 0.0;
        for (j = 0; j < num_of_bodies; j++) {
            if (i == j) continue;

            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double dist = sqrt(dx * dx + dy * dy);
            double f = G * bodies[i].mass * bodies[j].mass / (dist * dist);

            bodies[i].fx += f * dx / dist;
            bodies[i].fy += f * dy / dist;
        }
    }
}

void update_velocities(body_t *bodies) {
    int i;

    for (i = 0; i < num_of_bodies; i++) {
        bodies[i].vx += bodies[i].fx / bodies[i].mass * dt;
        bodies[i].vy += bodies[i].fy / bodies[i].mass * dt;
    }
}

void update_positions(body_t *bodies) {
    int i;

    for (i = 0; i < num_of_bodies; i++) {
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
    }
}

void print_body(body_t body) {
    printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n", body.x, body.y, body.vx, body.vy, body.fx, body.fy);
}

int main() {
    int i, j;

    // initialize the bodies
    body_t bodies[num_of_bodies] = {
        { .x = 0.0, .y = 0.0, .vx = 0.0, .vy = 0.0, .fx = 0.0, .fy = 0.0, .mass = 1.0 },
        { .x = 10.0, .y = 0.0, .vx = 0.0, .vy = 100.0, .fx = 0.0, .fy = 0.0, .mass = 2.0 },
        { .x = 0.0, .y = 10.0, .vx = -100.0, .vy = 0.0, .fx = 0.0, .fy = 0.0, .mass = 3.0 }
    };

    // simulate the bodies
    for (i = 0; i < 1000; i++) {
        // print the current state of the bodies
        for (j = 0; j < num_of_bodies; j++) {
            print_body(bodies[j]);
        }

        // update the forces, velocities and positions of the bodies
        update_forces(bodies);
        update_velocities(bodies);
        update_positions(bodies);
    }

    return 0;
}