//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PLANETS 10
#define G 6.6743e-11  // gravitational constant

// Structure representing a planet
struct planet {
    char name[20];
    double mass;  // in kg
    double radius;  // in m
    double position[3];  // in m
    double velocity[3];  // in m/s
};

// Structure representing a simulation
struct simulation {
    struct planet planets[MAX_PLANETS];
    int num_planets;
    double time_step;  // in s
    double duration;  // in s
};

// Function to calculate the distance between two planets
double distance(double position1[], double position2[]) {
    double x = position2[0] - position1[0];
    double y = position2[1] - position1[1];
    double z = position2[2] - position1[2];
    return sqrt(x * x + y * y + z * z);
}

// Function to calculate the force between two planets
void force(double position1[], double position2[], double mass1, double mass2, double *force_x, double *force_y, double *force_z) {
    double dist = distance(position1, position2);
    double f = G * mass1 * mass2 / (dist * dist);
    *force_x = f * (position2[0] - position1[0]) / dist;
    *force_y = f * (position2[1] - position1[1]) / dist;
    *force_z = f * (position2[2] - position1[2]) / dist;
}

// Function to update the position and velocity of a planet
void update_planet(struct planet *p, double force_x, double force_y, double force_z, double time_step) {
    double acceleration_x = force_x / p->mass;
    double acceleration_y = force_y / p->mass;
    double acceleration_z = force_z / p->mass;
    p->position[0] += p->velocity[0] * time_step + 0.5 * acceleration_x * time_step * time_step;
    p->position[1] += p->velocity[1] * time_step + 0.5 * acceleration_y * time_step * time_step;
    p->position[2] += p->velocity[2] * time_step + 0.5 * acceleration_z * time_step * time_step;
    p->velocity[0] += acceleration_x * time_step;
    p->velocity[1] += acceleration_y * time_step;
    p->velocity[2] += acceleration_z * time_step;
}

// Function to run a simulation
void run_simulation(struct simulation *sim) {
    int i, j;
    for (double t = 0; t < sim->duration; t += sim->time_step) {
        for (i = 0; i < sim->num_planets; i++) {
            double fx = 0, fy = 0, fz = 0;
            for (j = 0; j < sim->num_planets; j++) {
                if (i != j) {
                    double force_x, force_y, force_z;
                    force(sim->planets[i].position, sim->planets[j].position, sim->planets[i].mass, sim->planets[j].mass, &force_x, &force_y, &force_z);
                    fx += force_x;
                    fy += force_y;
                    fz += force_z;
                }
            }
            update_planet(&sim->planets[i], fx, fy, fz, sim->time_step);
        }
    }
}

int main() {
    struct simulation sim;
    sim.num_planets = 2;
    sim.time_step = 1;
    sim.duration = 86400;  // 1 day
    // Planet 1
    struct planet p1;
    strcpy(p1.name, "Earth");
    p1.mass = 5.97e24;
    p1.radius = 6.37e6;
    p1.position[0] = 0;
    p1.position[1] = 0;
    p1.position[2] = 0;
    p1.velocity[0] = 0;
    p1.velocity[1] = 0;
    p1.velocity[2] = 0;
    // Planet 2
    struct planet p2;
    strcpy(p2.name, "Moon");
    p2.mass = 7.34e22;
    p2.radius = 1.74e6;
    p2.position[0] = 3.84e8;
    p2.position[1] = 0;
    p2.position[2] = 0;
    p2.velocity[0] = 0;
    p2.velocity[1] = 1022;  // orbital velocity around Earth
    p2.velocity[2] = 0;
    sim.planets[0] = p1;
    sim.planets[1] = p2;
    run_simulation(&sim);
    for (int i = 0; i < sim.num_planets; i++) {
        printf("%s: (%f, %f, %f)\n", sim.planets[i].name, sim.planets[i].position[0], sim.planets[i].position[1], sim.planets[i].position[2]);
    }
    return 0;
}