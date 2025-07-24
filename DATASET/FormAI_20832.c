//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11  // gravitational constant

typedef struct {
    double x, y;  // position
    double vx, vy;  // velocity
    double fx, fy;  // force
    double mass;  // mass
} Particle;

void compute_force(Particle *a, Particle *b) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double dist = sqrt(dx*dx + dy*dy);
    double f = G * a->mass * b->mass / (dist*dist);
    a->fx += f * dx / dist;
    a->fy += f * dy / dist;
}

void update(Particle *p, int n, double dt) {
    int i, j;

    // calculate all forces
    for (i=0; i<n; i++) {
        p[i].fx = p[i].fy = 0;
        for (j=0; j<n; j++) {
            if (i == j) continue;
            compute_force(&p[i], &p[j]);
        }
    }
    
    // update positions and velocities
    for (i=0; i<n; i++) {
        p[i].vx += p[i].fx / p[i].mass * dt;
        p[i].vy += p[i].fy / p[i].mass * dt;
        p[i].x += p[i].vx * dt;
        p[i].y += p[i].vy * dt;
    }
}

int main() {
    Particle p[3] = {
        {0, 0, 0, 0, 0, 5.97e24},  // Earth
        {150e9, 0, 0, 30000, 0, 1000},  // satellite
        {0, 1.5e11, -30000, 0, 0, 1.5e30}  // Sun
    };
    int i;
    double t = 0;
    double dt = 3600;

    while (1) {
        printf("t = %f\n", t/24/3600);
        for (i=0; i<3; i++) {
            printf("  p[%d]: x=%f\ty=%f\tvx=%f\tvy=%f\n", i, p[i].x, p[i].y, p[i].vx, p[i].vy);
        }
        printf("\n");
        
        update(p, 3, dt);
        t += dt;
    }

    return 0;
}