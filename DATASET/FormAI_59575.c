//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 8

struct planet {
    char name[9];
    double mass; // in kg
    double x, y; // position relative to sun in AU (astronomical units)
    double vx, vy; // velocity relative to sun in AU/day
};

double G = 6.674e-11; // gravitational constant in m^3/kg s^2

void update_velocity(struct planet* p, struct planet* other) {
    double dx = other->x - p->x;
    double dy = other->y - p->y;
    double dist_squared = dx*dx + dy*dy;
    double force = G * p->mass * other->mass / dist_squared;
    double angle = atan2(dy, dx);
    double fx = force * cos(angle);
    double fy = force * sin(angle);
    p->vx += fx / p->mass;
    p->vy += fy / p->mass;
}

void update_position(struct planet* p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

void update_system(struct planet planets[NUM_PLANETS], double dt) {
    int i, j;
    for (i = 0; i < NUM_PLANETS; i++) {
        for (j = 0; j < NUM_PLANETS; j++) {
            if (i != j) {
                update_velocity(&planets[i], &planets[j]);
            }
        }
    }
    for (i = 0; i < NUM_PLANETS; i++) {
        update_position(&planets[i], dt);
    }
}

void print_planet(struct planet p) {
    printf("%8s: (%.2f, %.2f) AU\n", p.name, p.x, p.y);
}

void print_system(struct planet planets[NUM_PLANETS]) {
    int i;
    for (i = 0; i < NUM_PLANETS; i++) {
        print_planet(planets[i]);
    }
}

int main() {
    struct planet planets[NUM_PLANETS] = {
        {"Sun", 1.989e30, 0, 0, 0, 0},
        {"Mercury", 3.301e23, 0.387, 0, 0, 47870},
        {"Venus", 4.867e24, 0.723, 0, 0, 35020},
        {"Earth", 5.972e24, 1, 0, 0, 29783},
        {"Mars", 6.417e23, 1.524, 0, 0, 24077},
        {"Jupiter", 1.899e27, 5.204, 0, 0, 13070},
        {"Saturn", 5.685e26, 9.582, 0, 0, 9690},
        {"Uranus", 8.683e25, 19.18, 0, 0, 6810},
        {"Neptune", 1.024e26, 30.07, 0, 0, 5430}
    };
    double dt = 0.01;
    int num_steps = 1000;
    int i, j;
    for (i = 0; i < num_steps; i++) {
        for (j = 0; j < NUM_PLANETS; j++) {
            update_system(planets, dt);
        }
        print_system(planets);
    }
    return 0;
}