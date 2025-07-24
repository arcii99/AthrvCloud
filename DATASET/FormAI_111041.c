//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PLANETS 10
#define G_CONSTANT 6.674E-11

typedef struct {
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

Planet planets[MAX_PLANETS];

void update_acceleration(Planet *p1, Planet *p2, double *ax, double *ay, double *az) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double distance = sqrt(dx * dx + dy * dy + dz * dz);
    double force = G_CONSTANT * p1->mass * p2->mass / (distance * distance);
    *ax += force * dx / distance / p1->mass;
    *ay += force * dy / distance / p1->mass;
    *az += force * dz / distance / p1->mass;
}

void update_velocity(Planet *p, double ax, double ay, double az, double t) {
    p->vx += ax * t;
    p->vy += ay * t;
    p->vz += az * t;
}

void update_position(Planet *p, double t) {
    p->x += p->vx * t;
    p->y += p->vy * t;
    p->z += p->vz * t;
}

void print_planet(Planet *p) {
    printf("mass: %f, x: %f, y: %f, z: %f, vx: %f, vy: %f, vz: %f\n", p->mass, p->x, p->y, p->z, p->vx, p->vy, p->vz);
}

int main() {
    // setup planets
    planets[0].mass = 5.97E24;
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;

    planets[1].mass = 7.34E22;
    planets[1].x = 3.84E8;
    planets[1].y = 0;
    planets[1].z = 0;
    planets[1].vx = 0;
    planets[1].vy = 1022;
    planets[1].vz = 0;

    // simulate gravity
    double t = 3600; // timestep in seconds
    for (int i = 0; i < 10000; i++) {
        // calculate acceleration
        for (int j = 0; j < 2; j++) {
            double ax = 0;
            double ay = 0;
            double az = 0;
            for (int k = 0; k < 2; k++) {
                if (j != k) {
                    update_acceleration(&planets[j], &planets[k], &ax, &ay, &az);
                }
            }
            update_velocity(&planets[j], ax, ay, az, t);
        }

        // update position
        for (int j = 0; j < 2; j++) {
            update_position(&planets[j], t);
        }

        printf("time: %f\n", t);
        print_planet(&planets[0]);
        print_planet(&planets[1]);

        t += 3600;
    }

    return 0;
}