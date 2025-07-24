//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

#define G_CONST 6.67430e-11 // gravitational constant
#define DT 0.01 // time interval for simulation

struct planet {
    double mass;
    double x, y; // position
    double vx, vy; //velocity
    double ax, ay; //acceleration
};

void update_position(struct planet *p) {
    p->x += p->vx * DT;
    p->y += p->vy * DT;
}

void update_velocity(struct planet *p) {
    p->vx += p->ax * DT;
    p->vy += p->ay * DT;
}

void update_acceleration(struct planet *p1, struct planet *p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double r = sqrt(dx*dx + dy*dy);
    double f = G_CONST * p1->mass * p2->mass / (r * r);
    p1->ax += f * dx / r / p1->mass;
    p1->ay += f * dy / r / p1->mass;
}

void simulate(int n, struct planet *planets) {
    int t;
    for (t = 0; t < 1000; t++) {
        // calculate acceleration for each planets
        int i, j;
        for (i = 0; i < n; i++) {
            planets[i].ax = 0;
            planets[i].ay = 0;
            for (j = 0; j < n; j++) {
                if (i != j) {
                    update_acceleration(&planets[i], &planets[j]);
                }
            }
        }
        // update position and velocity for each planet
        for (i = 0; i < n; i++) {
            update_position(&planets[i]);
            update_velocity(&planets[i]);
        }
    }
}

int main() {
    struct planet planets[] = {
        {1.0, 0.0, 0.0, 0.0, -2.0, 0.0, 0.0},
        {1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0},
        {1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0},
        {1.0, 1.0, 1.0, -1.0, 0.0, 0.0, 0.0},
    };
    int n = sizeof(planets) / sizeof(planets[0]);
    simulate(n, planets);
    return 0;
}