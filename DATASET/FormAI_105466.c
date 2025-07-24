//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // gravitational constant

typedef struct planet {
    double mass;
    double px; // x position
    double py; // y position
    double vx; // x velocity
    double vy; // y velocity
} Planet;

void set_initial_conditions(Planet* p, double mass, double px, double py, double vx, double vy) {
    p->mass = mass;
    p->px = px;
    p->py = py;
    p->vx = vx;
    p->vy = vy;
}

void update_position(Planet* p, double dt) {
    p->px += p->vx * dt;
    p->py += p->vy * dt;
}

void update_velocity(Planet* p1, Planet* p2, double dt) {
    double distance_x = p1->px - p2->px;
    double distance_y = p1->py - p2->py;
    double distance = sqrt(distance_x * distance_x + distance_y * distance_y);
    double force = G * p1->mass * p2->mass / (distance * distance);
    double force_x = force * distance_x / distance;
    double force_y = force * distance_y / distance;
    double acceleration_x = force_x / p1->mass;
    double acceleration_y = force_y / p1->mass;
    p1->vx -= acceleration_x * dt;
    p1->vy -= acceleration_y * dt;
    p2->vx += acceleration_x * dt;
    p2->vy += acceleration_y * dt;
}

int main() {
    Planet earth, moon;
    set_initial_conditions(&earth, 5.97e24, 0, 0, 0, 0);
    set_initial_conditions(&moon, 7.34e22, 384400000, 0, 0, 1022);

    double dt = 60; // time step in seconds
    double total_time = 86400 * 365.25 * 10; // 10 years in seconds
    int num_steps = (int)(total_time / dt);

    for (int i = 0; i < num_steps; i++) {
        update_velocity(&earth, &moon, dt);
        update_velocity(&moon, &earth, dt);
        update_position(&earth, dt);
        update_position(&moon, dt);
        printf("Earth (x,y) = (%.2e, %.2e)  Moon (x,y) = (%.2e, %.2e)\n", earth.px, earth.py, moon.px, moon.py);
    }

    return 0;
}