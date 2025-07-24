//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: active
#include <stdio.h>
#include <math.h>

#define NUM_PLANETS 8        // number of planets in the solar system
#define NUM_STEPS    500000  // number of time steps in the simulation

struct planet {
    char name[20];
    double mass;
    double pos[3];
    double vel[3];
};

struct planet planets[NUM_PLANETS] = {
    {"Sun",     1.989e30, {0, 0, 0}, {0, 0, 0}},
    {"Mercury", 3.30e23,  {0, 4.6e10, 0}, {47890, 0, 0}},
    {"Venus",   4.87e24,  {0, 1.08e11, 0}, {35040, 0, 0}},
    {"Earth",   5.97e24,  {0, 1.5e11, 0},  {29790, 0, 0}},
    {"Mars",    6.42e23,  {0, 2.28e11, 0}, {24140, 0, 0}},
    {"Jupiter", 1.89e27,  {0, 7.78e11, 0}, {13070, 0, 0}},
    {"Saturn",  5.68e26,  {0, 1.43e12, 0}, {9690,  0, 0}},
    {"Uranus",  8.68e25,  {0, 2.87e12, 0}, {6810,  0, 0}},
    {"Neptune", 1.02e26,  {0, 4.5e12, 0},  {5430,  0, 0}}
};

void update_velocity(double dt) {
    int i, j;
    double r, fg;
    for (i = 1; i < NUM_PLANETS; i++) {
        for (j = 0; j < i; j++) {
            r = sqrt(pow(planets[i].pos[0] - planets[j].pos[0], 2)
                   + pow(planets[i].pos[1] - planets[j].pos[1], 2)
                   + pow(planets[i].pos[2] - planets[j].pos[2], 2));
            fg = 6.67e-11 * planets[i].mass * planets[j].mass / pow(r, 2);
            planets[i].vel[0] -= fg * (planets[i].pos[0] - planets[j].pos[0]) / (r * planets[i].mass) * dt;
            planets[i].vel[1] -= fg * (planets[i].pos[1] - planets[j].pos[1]) / (r * planets[i].mass) * dt;
            planets[i].vel[2] -= fg * (planets[i].pos[2] - planets[j].pos[2]) / (r * planets[i].mass) * dt;
            planets[j].vel[0] += fg * (planets[i].pos[0] - planets[j].pos[0]) / (r * planets[j].mass) * dt;
            planets[j].vel[1] += fg * (planets[i].pos[1] - planets[j].pos[1]) / (r * planets[j].mass) * dt;
            planets[j].vel[2] += fg * (planets[i].pos[2] - planets[j].pos[2]) / (r * planets[j].mass) * dt;
        }
    }
}

void update_position(double dt) {
    int i;
    for (i = 1; i < NUM_PLANETS; i++) {
        planets[i].pos[0] += planets[i].vel[0] * dt;
        planets[i].pos[1] += planets[i].vel[1] * dt;
        planets[i].pos[2] += planets[i].vel[2] * dt;
    }
}

int main() {
    int i, j;
    double dt = 1000, t;
    printf("Welcome to Solar System Simulator 1.0\n");
    printf("Initializing simulation...\n");
    for (i = 0; i < NUM_PLANETS; i++) {
        printf("Planet: %s, Mass: %g kg, Position: (%g, %g, %g) m, Velocity: (%g, %g, %g) m/s\n",
               planets[i].name, planets[i].mass,
               planets[i].pos[0], planets[i].pos[1], planets[i].pos[2],
               planets[i].vel[0], planets[i].vel[1], planets[i].vel[2]);
    }
    printf("Running simulation...\n");
    for (i = 0; i < NUM_STEPS; i++) {
        update_velocity(dt);
        update_position(dt);
        t = dt * i;
        if (i % 10000 == 0) {
            printf("Time: %g s\n", t);
            for (j = 0; j < NUM_PLANETS; j++) {
                printf("Planet: %s, Position: (%g, %g, %g) m, Velocity: (%g, %g, %g) m/s\n",
                       planets[j].name,
                       planets[j].pos[0], planets[j].pos[1], planets[j].pos[2],
                       planets[j].vel[0], planets[j].vel[1], planets[j].vel[2]);
            }
        }
    }
    return 0;
}