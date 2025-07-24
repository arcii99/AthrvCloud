//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: multivariable
#include <stdio.h>
#include <math.h>

#define MAX_BODY 10
#define G 6.674e-11   

struct Body {
    double mass, x, y, z, vx, vy, vz, fx, fy, fz;
};

void compute_forces(struct Body bodies[]) {
    int i, j;
    double dx, dy, dz, d, f;

    for (i = 0; i < MAX_BODY; i++) {
        bodies[i].fx = bodies[i].fy = bodies[i].fz = 0.0;
        for (j = 0; j < MAX_BODY; j++) {
            if (i == j) {
                continue;
            }
            dx = bodies[j].x - bodies[i].x;
            dy = bodies[j].y - bodies[i].y;
            dz = bodies[j].z - bodies[i].z;
            d = sqrt(dx * dx + dy * dy + dz * dz);
            if (d < 1.0) {
                d = 1.0;
            }
            f = G * bodies[i].mass * bodies[j].mass / (d * d);
            bodies[i].fx += f * dx / d;
            bodies[i].fy += f * dy / d;
            bodies[i].fz += f * dz / d;
        }
    }
}

void update_bodies(struct Body bodies[], double dt) {
    int i;
    for (i = 0; i < MAX_BODY; i++) {
        double ax = bodies[i].fx / bodies[i].mass;
        double ay = bodies[i].fy / bodies[i].mass;
        double az = bodies[i].fz / bodies[i].mass;
        bodies[i].vx += ax * dt;
        bodies[i].vy += ay * dt;
        bodies[i].vz += az * dt;
        bodies[i].x += bodies[i].vx * dt;
        bodies[i].y += bodies[i].vy * dt;
        bodies[i].z += bodies[i].vz * dt;
    }
}

void print_body(struct Body *body) {
    printf("Body mass:%lf, x:%lf, y:%lf, z:%lf, vx:%lf, vy:%lf, vz:%lf\n",
        body->mass,
        body->x,
        body->y,
        body->z,
        body->vx,
        body->vy,
        body->vz);
}

void simulate() {
    struct Body bodies[MAX_BODY] = {
        { 1.0e+18, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
        { 5.9e+22, 1.0e+11, 0.0, 0.0, 0.0, 3.0e+4, 0.0 },
        { 1.9e+30, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },
        { 5.97e+24, 0.0, 6.4e+6, 0.0, -30e+3, 0.0, 0.0 },
        { 6.4e+23, 0.0, 3.5e+6, 0.0, 42e+3, 0.0, 0.0 },
        { 1.9e+27, 0.0, 4.5e+10, 0.0, -1.0e+4, 0.0, 0.0},
        { 1.0e+26, 2.5e+11, 2.5e+11, 0.0, -1.4e+4, -1.4e+4, 0.0 },
        { 1.02e+23, 3.0e+8, 0.0, 0.0, 0.0, 30e+3, 0.0 },
        { 8.7e+25, 5.2e+11, -7.59e+11, 0.0, 1.0e+4, -7.0e+3, 0.0 },
        { 1.0e+22, -2e+11, 5.0e+12, 0.0, 6.0e+3, -3.0e+2, 0.0 },
    };
    int i;

    for (i = 0; i < 300000; i++) {
        compute_forces(bodies);
        update_bodies(bodies, 10);
        if (i % 1000 == 0) {
            printf("------------------frame %d------------------\n", i);
            for (int j = 0; j < MAX_BODY; j++) {
                print_body(&bodies[j]);
            }
        }
    }
}

int main() {
    simulate();
    return 0;
}