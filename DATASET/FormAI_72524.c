//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: dynamic
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11 // gravitational constant

typedef struct {
    double x, y, z; // position
    double vx, vy, vz; // velocity
    double mass; // mass
} Planet;

void updateVelocity(Planet *p, double ax, double ay, double az, double dt) {
    p->vx += ax * dt;
    p->vy += ay * dt;
    p->vz += az * dt;
}

void updatePosition(Planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    double dz = z2 - z1;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

void simulate(Planet *p, int np, double dt, int steps) {
    for (int s = 0; s < steps; s++) {
        for (int i = 0; i < np; i++) {
            double ax = 0, ay = 0, az = 0; // acceleration
            for (int j = 0; j < np; j++) {
                if (i == j) continue;
                double dist = distance(p[i].x, p[i].y, p[i].z, p[j].x, p[j].y, p[j].z);
                double f = G * p[i].mass * p[j].mass / (dist*dist);
                double fx = f * (p[j].x - p[i].x) / dist;
                double fy = f * (p[j].y - p[i].y) / dist;
                double fz = f * (p[j].z - p[i].z) / dist;
                ax += fx / p[i].mass;
                ay += fy / p[i].mass;
                az += fz / p[i].mass;
            }
            updateVelocity(&p[i], ax, ay, az, dt);
        }
        for (int i = 0; i < np; i++) {
            updatePosition(&p[i], dt);
        }
    }
}

int main() {
    int np = 2;
    Planet p[np];
    p[0].x = 0;
    p[0].y = 0;
    p[0].z = 0;
    p[0].vx = 0;
    p[0].vy = 0;
    p[0].vz = 0;
    p[0].mass = 5.97e24; // earth mass
    p[1].x = 400000;
    p[1].y = 0;
    p[1].z = 0;
    p[1].vx = 0;
    p[1].vy = 7671; // orbital velocity of ISS
    p[1].vz = 0;
    p[1].mass = 419725; // ISS mass
    double dt = 1;
    int steps = 86400; // simulate one day
    simulate(p, np, dt, steps);
    printf("Earth position: (%lf, %lf, %lf)\n", p[0].x, p[0].y, p[0].z);
    printf("ISS position:   (%lf, %lf, %lf)\n", p[1].x, p[1].y, p[1].z);
    return 0;
}