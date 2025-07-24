//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant
#define TIMESTEP 3600 // one hour timestep
#define NUM_PLANETS 3 // number of planets in simulation
#define SIM_DURATION 31536000 // one Earth year in seconds

typedef struct {
    char name[20];
    double mass;
    double position[3];
    double velocity[3];
} Planet;

double magnitude(double *v) {
    return sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2));
}

double distance(double *p1, double *p2) {
    return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2) + pow(p1[2] - p2[2], 2));
}

void update_velocity(Planet *p1, Planet *p2, double timestep) {
    double distance_vector[3];
    double force_magnitude;

    for (int i = 0; i < 3; i++) {
        distance_vector[i] = p2->position[i] - p1->position[i];
    }

    force_magnitude = G * p1->mass * p2->mass / pow(distance(distance_vector, distance_vector), 2);

    for (int i = 0; i < 3; i++) {
        p1->velocity[i] += force_magnitude * distance_vector[i] * timestep / (p1->mass * distance(distance_vector, distance_vector));
    }
}

void update_position(Planet *p, double timestep) {
    for (int i = 0; i < 3; i++) {
        p->position[i] += p->velocity[i] * timestep;
    }
}

void sim_duration(double duration, double timestep, Planet *planets) {
    int num_timesteps = duration / timestep;

    for (int i = 0; i < num_timesteps; i++) {
        for (int j = 0; j < NUM_PLANETS; j++) {
            for (int k = j + 1; k < NUM_PLANETS; k++) {
                update_velocity(&planets[j], &planets[k], timestep);
                update_velocity(&planets[k], &planets[j], timestep);
            }
        }
        for (int j = 0; j < NUM_PLANETS; j++) {
            update_position(&planets[j], timestep);
        }
    }
}

int main() {
    Planet planets[NUM_PLANETS] = {
        {"Earth", 5.97e24, {0, 0, 0}, {0, 0, 0}},
        {"Mars", 6.42e23, {2.279e11, 0, 0}, {0, 2.65e4, 0}},
        {"Jupiter", 1.90e27, {7.785e11, 0, 0}, {0, 1.37e4, 0}}
    };

    sim_duration(SIM_DURATION, TIMESTEP, planets);

    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("%s - x: %f km, y: %f km, z: %f km\n", planets[i].name, planets[i].position[0] / 1000, planets[i].position[1] / 1000, planets[i].position[2] / 1000);
    }

    return 0;
}