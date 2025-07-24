//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>
#define G 6.674e-11 // gravitational constant
#define TIME_STEP 0.01 // simulation time step

typedef struct {
    double mass;
    double position[3];
    double velocity[3];
    double acceleration[3];
} Planet;

void update_acceleration(Planet* planet, Planet* other_planets, int num_planets) {
    int i;
    double r, r_squared, force;
    for (i = 0; i < 3; ++i) {
        planet->acceleration[i] = 0.0;
    }
    for (i = 0; i < num_planets; ++i) {
        if (planet != &other_planets[i]) {
            r_squared = pow(planet->position[0] - other_planets[i].position[0], 2.0)
                      + pow(planet->position[1] - other_planets[i].position[1], 2.0)
                      + pow(planet->position[2] - other_planets[i].position[2], 2.0);
            r = sqrt(r_squared);
            force = G * planet->mass * other_planets[i].mass / r_squared;
            planet->acceleration[0] += force * (other_planets[i].position[0] - planet->position[0]) / r;
            planet->acceleration[1] += force * (other_planets[i].position[1] - planet->position[1]) / r;
            planet->acceleration[2] += force * (other_planets[i].position[2] - planet->position[2]) / r;
        }
    }
}

void update_velocity(Planet* planet) {
    int i;
    for (i = 0; i < 3; ++i) {
        planet->velocity[i] += planet->acceleration[i] * TIME_STEP;
    }
}

void update_position(Planet* planet) {
    int i;
    for (i = 0; i < 3; ++i) {
        planet->position[i] += planet->velocity[i] * TIME_STEP;
    }
}

void simulate_gravity(Planet* planets, int num_planets, double duration) {
    int i, j, step;
    for (step = 0; step * TIME_STEP < duration; ++step) {
        for (i = 0; i < num_planets; ++i) {
            update_acceleration(&planets[i], planets, num_planets);
        }
        for (i = 0; i < num_planets; ++i) {
            update_velocity(&planets[i]);
        }
        for (i = 0; i < num_planets; ++i) {
            update_position(&planets[i]);
        }
    }
}

int main() {
    Planet planets[3] = {
        { 5.97e24, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 } }, // earth
        { 7.34e22, { 3.84e8, 0.0, 0.0 }, { 0.0, 1022.0, 0.0 } }, // moon
        { 198.9e24, { 147.1e9, 0.0, 0.0 }, { 0.0, 30000.0, 0.0 } }, // jupiter
    };
    int i;
    simulate_gravity(planets, 3, 3600.0 * 24.0 * 365.0); // simulate one earth year
    for (i = 0; i < 3; ++i) {
        printf("Planet %d: position = (%e, %e, %e), velocity = (%e, %e, %e)\n",
               i, planets[i].position[0], planets[i].position[1], planets[i].position[2],
               planets[i].velocity[0], planets[i].velocity[1], planets[i].velocity[2]);
    }
    return 0;
}