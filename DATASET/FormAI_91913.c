//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant

typedef struct {
    double mass;
    double position[3];
    double velocity[3];
} Body;

void update_velocities(Body* bodies, int num_bodies, double time_step) {
    for(int i = 0; i < num_bodies; i++) {
        double total_gravity[3] = {0, 0, 0};
        for(int j = 0; j < num_bodies; j++) {
            if(i == j) continue;
            double r[3];
            for(int k = 0; k < 3; k++) {
                r[k] = bodies[j].position[k] - bodies[i].position[k];
            }
            double distance_squared = r[0]*r[0] + r[1]*r[1] + r[2]*r[2];
            double magnitude = G * bodies[i].mass * bodies[j].mass / distance_squared;
            double direction[3];
            for(int k = 0; k < 3; k++) {
                direction[k] = r[k] / sqrt(distance_squared);
            }
            double gravity[3];
            for(int k = 0; k < 3; k++) {
                gravity[k] = magnitude * direction[k];
            }
            for(int k = 0; k < 3; k++) {
                total_gravity[k] += gravity[k];
            }
        }
        for(int k = 0; k < 3; k++) {
            bodies[i].velocity[k] += total_gravity[k] * time_step / bodies[i].mass;
        }
    }
}

void update_positions(Body* bodies, int num_bodies, double time_step) {
    for(int i = 0; i < num_bodies; i++) {
        for(int k = 0; k < 3; k++) {
            bodies[i].position[k] += bodies[i].velocity[k] * time_step;
        }
    }
}

int main() {
    int num_bodies = 3;
    Body bodies[num_bodies];

    // planet 1
    bodies[0].mass = 5.97e24; // mass of Earth
    bodies[0].position[0] = 0;
    bodies[0].position[1] = 0;
    bodies[0].position[2] = 0;
    bodies[0].velocity[0] = 0;
    bodies[0].velocity[1] = 0;
    bodies[0].velocity[2] = 0;

    // planet 2
    bodies[1].mass = 6.39e23; // mass of Mars
    bodies[1].position[0] = 2.28e11; // 1.5 AU from the Sun
    bodies[1].position[1] = 0;
    bodies[1].position[2] = 0;
    bodies[1].velocity[0] = 0;
    bodies[1].velocity[1] = 2.41e4; // orbital velocity
    bodies[1].velocity[2] = 0;

    // planet 3
    bodies[2].mass = 1.99e30; // mass of the Sun
    bodies[2].position[0] = 0;
    bodies[2].position[1] = 0;
    bodies[2].position[2] = 0;
    bodies[2].velocity[0] = 0;
    bodies[2].velocity[1] = 0;
    bodies[2].velocity[2] = 0;

    double time_step = 86400; // 1 day in seconds
    int num_steps = 365; // simulate for 1 year
    
    for(int i = 0; i < num_steps; i++) {
        update_velocities(bodies, num_bodies, time_step);
        update_positions(bodies, num_bodies, time_step);
        printf("step %d:\n", i+1);
        for(int j = 0; j < num_bodies; j++) {
            printf("  planet %d: (%f, %f, %f)\n", j+1, bodies[j].position[0], bodies[j].position[1], bodies[j].position[2]);
        }
    }

    return 0;
}