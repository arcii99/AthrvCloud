//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: minimalist
#include <stdio.h>
#include <math.h>

#define DT 0.01
#define G 6.67430e-11
#define MAX_BODIES 100
#define MAX_NAME_LEN 100

typedef struct body {
    double mass;
    double x, y;
    double vx, vy;
    double fx, fy;
    char name[MAX_NAME_LEN];
} body_t;

body_t bodies[MAX_BODIES];
int num_bodies = 0;

void add_body(body_t body) {
    bodies[num_bodies++] = body;
}

void calc_force(body_t body1, body_t body2) {
    double dx = body2.x - body1.x;
    double dy = body2.y - body1.y;

    double dist = sqrt(dx * dx + dy * dy);
    double force = (G * body1.mass * body2.mass) / (dist * dist + 1e-6);

    double fx = force * dx / dist;
    double fy = force * dy / dist;

    body1.fx += fx;
    body2.fx -= fx;
    body1.fy += fy;
    body2.fy -= fy;
}

void calc_forces() {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].fx = 0;
        bodies[i].fy = 0;
        for (int j = i + 1; j < num_bodies; j++) {
            calc_force(bodies[i], bodies[j]);
        }
    }
}

void update_bodies() {
    for (int i = 0; i < num_bodies; i++) {
        body_t *body = &bodies[i];

        double ax = body->fx / body->mass;
        double ay = body->fy / body->mass;

        body->vx += ax * DT;
        body->vy += ay * DT;

        body->x += body->vx * DT;
        body->y += body->vy * DT;
    }
}

void print_bodies() {
    for (int i = 0; i < num_bodies; i++) {
        body_t *body = &bodies[i];

        printf("%s: (%f, %f)\n", body->name, body->x, body->y);
    }
}

int main() {
    body_t sun = {1.989e30, 0, 0, 0, 0, 0, 0, "sun"};
    body_t earth = {5.972e24, 149.6e9, 0, 0, 29.29e3, 0, 0, "earth"};

    add_body(sun);
    add_body(earth);

    for (int i = 0; i < 365 * 24 * 60 * 60 / DT; i++) {
        calc_forces();
        update_bodies();
    }

    print_bodies();

    return 0;
}