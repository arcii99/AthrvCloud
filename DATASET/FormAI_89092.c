//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: standalone
#include <stdio.h>
#include <math.h>

#define G_CONST 6.67408E-11 // Gravitational constant

typedef struct {
    double x;
    double y;
} Vector;

typedef struct {
    double mass;
    Vector position;
    Vector velocity;
} Body;

void calculate_force(const Body* body_a, const Body* body_b, Vector* force) {
    double dx = body_b->position.x - body_a->position.x;
    double dy = body_b->position.y - body_a->position.y;
    double distance = sqrt(dx*dx + dy*dy);
    double f = G_CONST * body_a->mass * body_b->mass / (distance*distance);
    force->x += f*dx/distance;
    force->y += f*dy/distance;
}

void simulate(Body* bodies, int n, double time_step) {
    for (int i = 0; i < n; i++) {
        Vector force = {0, 0};
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            calculate_force(&bodies[i], &bodies[j], &force);
        }
        double ax = force.x / bodies[i].mass;
        double ay = force.y / bodies[i].mass;
        bodies[i].velocity.x += ax * time_step;
        bodies[i].velocity.y += ay * time_step;
        bodies[i].position.x += bodies[i].velocity.x * time_step;
        bodies[i].position.y += bodies[i].velocity.y * time_step;
    }
}

int main() {
    Body bodies[] = {
        {5.97E+24, {0, 0}, {0, 0}}, // Earth
        {7.36E+22, {384400000, 0}, {0, 1022}}, // Moon
        {1.99E+30, {0, 5.79E+10}, {30330, 0}} // Sun
    };
    int n_bodies = sizeof(bodies) / sizeof(bodies[0]);
    double time_step = 3600; // 1 hour
    int num_steps = 24; // Simulate for 24 hours
    for (int i = 0; i < num_steps; i++) {
        printf("Step %d:\n", i+1);
        for (int j = 0; j < n_bodies; j++) {
            printf("Body %d: x=%.2f, y=%.2f\n", j+1, bodies[j].position.x, bodies[j].position.y);
        }
        printf("\n");
        simulate(bodies, n_bodies, time_step);
    }
    return 0;
}