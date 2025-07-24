//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY_CONSTANT 6.674e-11 // m^3 kg^-1 s^-2
#define TIME_STEP 0.1 // seconds
#define NUM_PLANETS 3

typedef struct {
    double mass;
    double position[3];
    double velocity[3];
} Planet;

void update_position(Planet * planet, double time_step) {
    for (int i = 0; i < 3; i++) {
        planet->position[i] += planet->velocity[i] * time_step;
    }
}

void update_velocity(Planet * planet, Planet * other_planets, double time_step) {
    double acc[3] = {0, 0, 0};
    for (int i = 0; i < NUM_PLANETS; i++) {
        if (other_planets[i].mass == 0 || planet == &other_planets[i]) {
            continue;
        }
        double distance_squared = 0;
        for (int j = 0; j < 3; j++) {
            double diff = other_planets[i].position[j] - planet->position[j];
            distance_squared += diff * diff;
        }
        double distance = sqrt(distance_squared);
        double force_magnitude = GRAVITY_CONSTANT * planet->mass * other_planets[i].mass / (distance_squared * distance);
        for (int j = 0; j < 3; j++) {
            double force_component = force_magnitude * (other_planets[i].position[j] - planet->position[j]) / distance;
            acc[j] += force_component / planet->mass;
        }
    }
    for (int i = 0; i < 3; i++) {
        planet->velocity[i] += acc[i] * time_step;
    }
}

int main() {
    Planet planets[NUM_PLANETS] = {
        {10, {0, 0, 0}, {0, 0, 0}}, 
        {1, {1e11, 0, 0}, {0, sqrt(GRAVITY_CONSTANT * 10 / 1e11), 0}},
        {1, {0, 1e11, 0}, {-sqrt(GRAVITY_CONSTANT * 10 / 1e11), 0, 0}}
    };

    double time = 0;
    while (1) {
        for (int i = 0; i < NUM_PLANETS; i++) {
            update_velocity(&planets[i], planets, TIME_STEP);
        }
        for (int i = 0; i < NUM_PLANETS; i++) {
            update_position(&planets[i], TIME_STEP);
        }
        time += TIME_STEP;
        printf("t = %lf\n", time);
        for (int i = 0; i < NUM_PLANETS; i++) {
            printf("Planet %d: (%lf, %lf, %lf)\n", i, planets[i].position[0], planets[i].position[1], planets[i].position[2]);
        }
    }

    return 0;
}