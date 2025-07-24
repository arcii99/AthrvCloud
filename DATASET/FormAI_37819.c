//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: visionary
#include <stdio.h>
#include <math.h>

#define NUM_PLANETS 5 // number of planets
#define G_CONST 6.674E-11 // gravitational constant

typedef struct {
    double x, y; // position
    double vx, vy; // velocity
    double ax, ay; // acceleration
    double mass; // mass
} Planet;

void update_acceleration(Planet *p, Planet planets[]) {
    int i;
    double d, f;
    p->ax = p->ay = 0;
    for (i = 0; i < NUM_PLANETS; i++) {
        if (p != &planets[i]) {
            d = sqrt(pow(p->x - planets[i].x, 2) + pow(p->y - planets[i].y, 2));
            f = G_CONST * p->mass * planets[i].mass / pow(d, 2);
            p->ax += f * (planets[i].x - p->x) / d / p->mass;
            p->ay += f * (planets[i].y - p->y) / d / p->mass;
        }
    }
}

void update_velocity(Planet *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
}

void update_position(Planet *p, double dt) {
    p->x += p->vx * dt + 0.5 * p->ax * pow(dt, 2);
    p->y += p->vy * dt + 0.5 * p->ay * pow(dt, 2);
}

void simulate(double dt, double time_limit, Planet planets[]) {
    int i, j;
    double t;
    for (t = 0; t <= time_limit; t += dt) {
        for (i = 0; i < NUM_PLANETS; i++) {
            update_acceleration(&planets[i], planets);
        }
        for (i = 0; i < NUM_PLANETS; i++) {
            update_velocity(&planets[i], dt);
        }
        for (i = 0; i < NUM_PLANETS; i++) {
            update_position(&planets[i], dt);
        }
        printf("Time: %lf\n", t);
        for (i = 0; i < NUM_PLANETS; i++) {
            printf("Planet %d: x=%lf, y=%lf, vx=%lf, vy=%lf\n", i+1, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
        }
    }
}

int main() {
    Planet planets[NUM_PLANETS] = {
        {-0.5E11, 0, 0, -29.29E3, 0, 5.97E24}, // Earth
        {1E11, 0, 0, 24.07E3, 0, 6.42E23}, // Mars
        {0, 0, 0, 0, 0, 1.99E30}, // Sun
        {0, 1.5E11, -29.29E3, 0, 0, 1.9E27}, // Jupiter
        {0, -1E11, 40E3, 0, 0, 3.3E23} // Venus
    };
    simulate(3600, 24*3600*365, planets);
    return 0;
}