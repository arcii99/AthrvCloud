//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67E-11 // gravitational constant

typedef struct planet {
    char name[20];
    double mass;
    double x;
    double y;
    double vx;
    double vy;
    double fx;
    double fy;
} Planet;

void calculate_forces(Planet* p1, Planet* p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double distance = sqrt(dx * dx + dy * dy);
    double force = G * p1->mass * p2->mass / distance / distance;
    p1->fx += force * dx / distance;
    p1->fy += force * dy / distance;
    p2->fx -= force * dx / distance;
    p2->fy -= force * dy / distance;
}

void update_position(Planet* p, double dt) {
    p->vx += p->fx / p->mass * dt;
    p->vy += p->fy / p->mass * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->fx = 0;
    p->fy = 0;
}

int main() {
    int n = 3; // number of planets
    double dt = 3600; // time step (in seconds)
    Planet planets[n];

    // initialize planets
    strcpy(planets[0].name, "Earth");
    planets[0].mass = 5.97E24;
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].fx = 0;
    planets[0].fy = 0;

    strcpy(planets[1].name, "Moon");
    planets[1].mass = 7.34E22;
    planets[1].x = 384400000;
    planets[1].y = 0;
    planets[1].vx = 0;
    planets[1].vy = 1022;
    planets[1].fx = 0;
    planets[1].fy = 0;

    strcpy(planets[2].name, "Mars");
    planets[2].mass = 6.39E23;
    planets[2].x = 227939200000;
    planets[2].y = 0;
    planets[2].vx = 0;
    planets[2].vy = 0;
    planets[2].fx = 0;
    planets[2].fy = 0;

    // simulate motion
    int steps = 100000;
    for(int i = 0; i < steps; i++) {
        // calculate forces
        for(int j = 0; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                calculate_forces(&planets[j], &planets[k]);
            }
        }

        // update positions
        for(int j = 0; j < n; j++) {
            update_position(&planets[j], dt);
        }

        // output positions
        printf("Step %d\n", i);
        for(int j = 0; j < n; j++) {
            printf("%s (%.2f, %.2f)\n", planets[j].name, planets[j].x, planets[j].y);
        }
    }

    return 0;
}