//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11
#define TIMESTEP 0.01

struct planet {
    double x, y;
    double vx, vy;
    double mass;
};

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double acceleration_x(double x1, double x2, double y1, double y2, double mass2) {
    double r = distance(x1, y1, x2, y2);
    double a = G * mass2 / pow(r, 2);
    return a * (x2 - x1) / r;
}

double acceleration_y(double x1, double x2, double y1, double y2, double mass2) {
    double r = distance(x1, y1, x2, y2);
    double a = G * mass2 / pow(r, 2);
    return a * (y2 - y1) / r;
}

void update_velocity(struct planet *p, struct planet *q) {
    double ax = acceleration_x(p->x, q->x, p->y, q->y, q->mass);
    double ay = acceleration_y(p->x, q->x, p->y, q->y, q->mass);
    p->vx += ax * TIMESTEP;
    p->vy += ay * TIMESTEP;
}

void update_position(struct planet *p) {
    p->x += p->vx * TIMESTEP;
    p->y += p->vy * TIMESTEP;
}

void update_all(struct planet *planets, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                update_velocity(&planets[i], &planets[j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        update_position(&planets[i]);
    }
}

int main() {
    struct planet planets[3];
    planets[0].x = 100;
    planets[0].y = 100;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].mass = 1e10;
    planets[1].x = 150;
    planets[1].y = 150;
    planets[1].vx = 0;
    planets[1].vy = 0;
    planets[1].mass = 1e10;
    planets[2].x = 200;
    planets[2].y = 200;
    planets[2].vx = 0;
    planets[2].vy = 0;
    planets[2].mass = 1e10;
    int time = 0;
    while (time < 1000) {
        update_all(planets, 3);
        printf("%f %f\n%f %f\n%f %f\n", planets[0].x, planets[0].y, planets[1].x, planets[1].y, planets[2].x, planets[2].y);
        time++;
    }
    return 0;
}