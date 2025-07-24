//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: complete
#include <stdio.h>
#include <math.h>

#define G 6.674E-11 // gravitational constant

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double ax, ay; // acceleration
    double mass; // mass
} Particle;

void update(Particle* p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
}

void apply_force(Particle* p1, Particle* p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double distance = sqrt(dx*dx + dy*dy);
    double f = G * p1->mass * p2->mass / (distance * distance);
    double fx = f * dx / distance;
    double fy = f * dy / distance;
    p1->ax += fx / p1->mass;
    p1->ay += fy / p1->mass;
}

void simulate(Particle particles[], int n, double dt, int steps) {
    for (int s=0; s<steps; s++) {
        // calculate forces
        for (int i=0; i<n; i++) {
            particles[i].ax = 0;
            particles[i].ay = 0;
            for (int j=0; j<n; j++) {
                if (i != j) {
                    apply_force(&particles[i], &particles[j]);
                }
            }
        }
        // update positions and velocities
        for (int i=0; i<n; i++) {
            update(&particles[i], dt);
        }
        // print positions after every 100th step (for visualization purposes)
        if (s % 100 == 0) {
            printf("--- Step %d ---\n", s);
            for (int i=0; i<n; i++) {
                printf("Particle %d: x=%f, y=%f\n", i, particles[i].x, particles[i].y);
            }
        }
    }
}

int main() {
    Particle particles[3] = {
        {0, 0, 0, 0, 0, 1.0E+12}, // large planet at the origin
        {1.0E+11, 0, 0, 30000, 0, 1.0E+6}, // small planet in a circular orbit
        {0, 5.0E+10, -20000, 0, 0, 1.0E+6} // another small planet in a elliptical orbit
    };
    simulate(particles, 3, 10, 10000);
    return 0;
}