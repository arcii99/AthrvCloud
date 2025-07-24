//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 0.00000000006672 // gravitational constant

typedef struct planet {
    char name[20];
    double mass;
    double radius;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double ax;
    double ay;
    double az;
} planet;

void update_acceleration(planet *p, planet *q) {
    double dx = q->x - p->x;
    double dy = q->y - p->y;
    double dz = q->z - p->z;
    double dist = sqrt(dx*dx + dy*dy + dz*dz);

    double f = G * p->mass * q->mass / (dist*dist);

    p->ax += f * dx / (dist * p->mass);
    p->ay += f * dy / (dist * p->mass);
    p->az += f * dz / (dist * p->mass);
}

void update_velocity(planet *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

void update_position(planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

void simulate(planet *ps, int n, double dt, int steps) {
    for (int step = 0; step < steps; step++) {
        for (int i = 0; i < n; i++) {
            ps[i].ax = 0.0;
            ps[i].ay = 0.0;
            ps[i].az = 0.0;

            for (int j = 0; j < n; j++) {
                if (j != i) {
                    update_acceleration(&ps[i], &ps[j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            update_velocity(&ps[i], dt);
            update_position(&ps[i], dt);
        }

        printf("Step %d:\n", step+1);

        for (int i = 0; i < n; i++) {
            printf("%s: (%lf, %lf, %lf)\n", ps[i].name, ps[i].x, ps[i].y, ps[i].z);
        }
    }
}

int main() {
    planet ps[4];
    ps[0].mass = 5.97 * pow(10, 24);
    ps[0].radius = 6371;
    ps[0].x = 0;
    ps[0].y = 0;
    ps[0].z = 0;
    ps[0].vx = 0;
    ps[0].vy = 0;
    ps[0].vz = 0;
    sprintf(ps[0].name, "Earth");

    ps[1].mass = 1.898 * pow(10, 27);
    ps[1].radius = 69911;
    ps[1].x = 4.003 * pow(10, 8);
    ps[1].y = 0;
    ps[1].z = 0;
    ps[1].vx = 0;
    ps[1].vy = 24131;
    ps[1].vz = 0;
    sprintf(ps[1].name, "Jupiter");

    ps[2].mass = 3.3 * pow(10, 23);
    ps[2].radius = 1737;
    ps[2].x = 3.844 * pow(10, 8);
    ps[2].y = 0;
    ps[2].z = 0;
    ps[2].vx = 0;
    ps[2].vy = 1022;
    ps[2].vz = 0;
    sprintf(ps[2].name, "Moon");

    ps[3].mass = 6.39 * pow(10, 23);
    ps[3].radius = 3389.5;
    ps[3].x = 2.279 * pow(10, 8);
    ps[3].y = 0;
    ps[3].z = 0;
    ps[3].vx = 0;
    ps[3].vy = 24131 + 1000;
    ps[3].vz = 0;
    sprintf(ps[3].name, "Mars");

    simulate(ps, 4, 1000, 10);
}