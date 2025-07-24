//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAV_CONST 6.673e-11

typedef struct planet {
    double mass;
    double x;
    double y;
    double vx;
    double vy;
    double ax;
    double ay;
} Planet;

void update_velocity(Planet* p1, Planet* p2, double dt) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double r = sqrt(dx*dx + dy*dy);
    double force = GRAV_CONST * p1->mass * p2->mass / (r*r);
    double fx = force * dx / r;
    double fy = force * dy / r;
    p1->ax += fx / p1->mass;
    p1->ay += fy / p1->mass;
    p2->ax -= fx / p2->mass;
    p2->ay -= fy / p2->mass;
}

void update_position(Planet* p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->ax = 0;
    p->ay = 0;
}

int main() {
    int num_planets = 3;
    Planet planets[num_planets];
    planets[0].mass = 2e30;
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[1].mass = 5.97e24;
    planets[1].x = 6.371e6;
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = 7700;
    planets[2].mass = 7.35e22;
    planets[2].x = 0;
    planets[2].y = 3.844e8;
    planets[2].vx = 1000;
    planets[2].vy = 0;
    double dt = 3600;
    int num_steps = 8760;
    for (int step = 0; step < num_steps; step++) {
        for (int i = 0; i < num_planets; i++) {
            for (int j = i+1; j < num_planets; j++) {
                update_velocity(&planets[i], &planets[j], dt);
            }
        }
        for (int i = 0; i < num_planets; i++) {
            update_position(&planets[i], dt);
        }
        printf("Step: %d\n", step+1);
        printf("Planet 1: (%lf, %lf)\n", planets[0].x, planets[0].y);
        printf("Planet 2: (%lf, %lf)\n", planets[1].x, planets[1].y);
        printf("Planet 3: (%lf, %lf)\n\n", planets[2].x, planets[2].y);
        if (step == num_steps - 1) {
            printf("Simulation complete!\n");
        }
    }
    return 0;
}