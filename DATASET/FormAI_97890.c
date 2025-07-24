//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct planet {
    char name[10];
    double mass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
};

void update_position(struct planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

void update_velocity(struct planet *p, double ax, double ay, double az, double dt) {
    p->vx += ax * dt;
    p->vy += ay * dt;
    p->vz += az * dt;
}

double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

void update_acceleration(struct planet *p, struct planet *planets, int n, double G) {
    double ax = 0;
    double ay = 0;
    double az = 0;
    for (int i = 0; i < n; i++) {
        if (p == &planets[i]) {
            continue;
        }
        double d = distance(p->x, p->y, p->z, planets[i].x, planets[i].y, planets[i].z);
        double f = G * p->mass * planets[i].mass / pow(d, 2);
        ax += f * (planets[i].x - p->x) / d;
        ay += f * (planets[i].y - p->y) / d;
        az += f * (planets[i].z - p->z) / d;
    }
    update_velocity(p, ax, ay, az, 1);
}

void simulate(struct planet *planets, int n, double G, double dt, int iters) {
    for (int t = 0; t < iters; t++) {
        for (int i = 0; i < n; i++) {
            update_acceleration(&planets[i], planets, n, G);
            update_position(&planets[i], dt);
        }
    }
}

int main() {
    int n = 9;
    double G = 6.674 * pow(10, -11);
    double dt = 1;
    int iters = 1000;

    struct planet planets[] = {
        {"Sun",     1.989 * pow(10, 30),     0,      0,      0,      0,      0,      0},
        {"Mercury", 3.285 * pow(10, 23),     0,      -4.6e10,0,      47000,  0,      0},
        {"Venus",   4.867 * pow(10, 24),     0,      -1.1e11,0,      35000,  0,      0},
        {"Earth",   5.972 * pow(10, 24),     0,      -1.5e11,0,      30000,  0,      0},
        {"Mars",    6.39 * pow(10, 23),      0,      -2.2e11,0,      24000,  0,      0},
        {"Jupiter", 1.898 * pow(10, 27),     0,      -7.7e11,0,      13000,  0,      0},
        {"Saturn",  5.683 * pow(10, 26),     0,      -1.4e12,0,      9000,   0,      0},
        {"Uranus",  8.681 * pow(10, 25),     0,      -2.7e12,0,      6835,   0,      0},
        {"Neptune", 1.024 * pow(10, 26),     0,      -4.3e12,0,      5477,   0,      0},
    };

    simulate(planets, n, G, dt, iters);

    for (int i = 0; i < n; i++) {
        printf("%s: (%f, %f, %f)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }

    return 0;
}