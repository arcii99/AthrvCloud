//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11  // gravitational constant

typedef struct planet {
    double mass;
    double x, y;  // position
    double vx, vy;  // velocity
    double ax, ay;  // acceleration
} Planet;

void update_acceleration(Planet *p1, Planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dist2 = dx*dx + dy*dy;
    double f = G * p1->mass * p2->mass / dist2;
    double theta = atan2(dy, dx);
    double fx = f * cos(theta);
    double fy = f * sin(theta);
    p1->ax += fx / p1->mass;
    p1->ay += fy / p1->mass;
    p2->ax -= fx / p2->mass;
    p2->ay -= fy / p2->mass;
}

void update_velocity(Planet *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
}

void update_position(Planet *p, double dt) {
    p->x += p->vx * dt + 0.5 * p->ax * dt * dt;
    p->y += p->vy * dt + 0.5 * p->ay * dt * dt;
}

int main() {
    Planet planets[] = {
        {.mass=5.97e24, .x=0, .y=0, .vx=0, .vy=0},
        {.mass=6.39e23, .x=0, .y=384402e3, .vx=1022, .vy=0}
    };
    int n = sizeof(planets) / sizeof(Planet);
    double dt = 1.0;  // time step

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            update_acceleration(&planets[i], &planets[j]);  // calculate initial accelerations
        }
    }

    for (double t = 0; t < 3600*24*30; t += dt) {  // simulate for 30 days
        for (int i = 0; i < n; i++) {
            update_velocity(&planets[i], dt);
            update_position(&planets[i], dt);
            planets[i].ax = planets[i].ay = 0;  // reset accelerations for next update
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                update_acceleration(&planets[i], &planets[j]);  // calculate new accelerations
            }
        }
    }

    printf("Final positions:\n");
    for (int i = 0; i < n; i++) {
        printf("Planet %d: (%.1f, %.1f)\n", i+1, planets[i].x, planets[i].y);
    }

    return 0;
}