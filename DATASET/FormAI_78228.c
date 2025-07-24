//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 3 // the number of planets in the simulation
#define G_CONST 6.67e-11 // gravitational constant

struct planet {
    char name[20]; // the name of the planet
    double mass; // the mass of the planet in kg
    double x_pos; // the x position of the planet in m
    double y_pos; // the y position of the planet in m
    double x_vel; // the x velocity of the planet in m/s
    double y_vel; // the y velocity of the planet in m/s
};

void apply_gravity(struct planet *p, int i, int j) {
    double distance = sqrt(pow(p[j].x_pos - p[i].x_pos, 2) + pow(p[j].y_pos - p[i].y_pos, 2));
    double force = G_CONST * p[i].mass * p[j].mass / pow(distance, 2);
    double angle = atan2(p[j].y_pos - p[i].y_pos, p[j].x_pos - p[i].x_pos);
    p[i].x_vel += force / p[i].mass * cos(angle);
    p[i].y_vel += force / p[i].mass * sin(angle);
}

void update_positions(struct planet *p, double dt) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        p[i].x_pos += p[i].x_vel * dt;
        p[i].y_pos += p[i].y_vel * dt;
    }
}

void update_velocities(struct planet *p, double dt) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        for (int j = 0; j < NUM_PLANETS; j++) {
            if (j != i) {
                apply_gravity(p, i, j);
            }
        }
    }
}

void print_positions(struct planet *p) {
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s: (%.2f, %.2f)\n", p[i].name, p[i].x_pos, p[i].y_pos);
    }
}

int main() {
    // set the initial conditions of the planets
    struct planet planets[NUM_PLANETS] = {
        {"Earth", 5.97e24, 0, 0, 0, 0},
        {"Mars", 6.39e23, 2e11, 0, 0, 24000},
        {"Venus", 4.87e24, 1e11, 0, 0, 35000},
    };
    
    double timestep = 3600; // the length of each timestep in seconds
    for (int i = 0; i < 10000; i++) {
        update_velocities(planets, timestep);
        update_positions(planets, timestep);
    }
    
    print_positions(planets);
    
    return 0;
}