//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Definition of a planet struct */
typedef struct planet {
    float x, y, z;          // position
    float vel_x, vel_y, vel_z;  // velocity
    float mass;             // mass
} Planet;

/* Definition of a simulation struct */
typedef struct simulation {
    int num_planets;        // number of planets
    Planet *planets;        // array of planets
    float time_step;        // time step for integration
    float gravitational_constant;   // gravitational constant
} Simulation;

/* Function to calculate the gravitational force between two planets */
void gravitational_force(Planet p1, Planet p2, float gravitational_constant, float *force_x, float *force_y, float *force_z) {
    float distance = sqrt((p1.x-p2.x)*(p1.x-p2.x) + 
                          (p1.y-p2.y)*(p1.y-p2.y) + 
                          (p1.z-p2.z)*(p1.z-p2.z));
    float force_magnitude = gravitational_constant * p1.mass * p2.mass / (distance * distance);
    *force_x = force_magnitude * (p2.x - p1.x) / distance;
    *force_y = force_magnitude * (p2.y - p1.y) / distance;
    *force_z = force_magnitude * (p2.z - p1.z) / distance;
}

/* Function to update the velocity and position of a planet */
void update_planet(Planet *p, float force_x, float force_y, float force_z, float time_step) {
    p->vel_x += force_x / p->mass * time_step;
    p->vel_y += force_y / p->mass * time_step;
    p->vel_z += force_z / p->mass * time_step;
    p->x += p->vel_x * time_step;
    p->y += p->vel_y * time_step;
    p->z += p->vel_z * time_step;
}

/* Function to simulate the gravity of planets */
void simulate_gravity(Simulation *sim, int num_steps) {
    for (int step = 0; step < num_steps; step++) {
        // Calculate forces on each planet
        for (int i = 0; i < sim->num_planets; i++) {
            float force_x = 0, force_y = 0, force_z = 0;
            for (int j = 0; j < sim->num_planets; j++) {
                if (i == j) continue;
                float this_force_x, this_force_y, this_force_z;
                gravitational_force(sim->planets[i], sim->planets[j], sim->gravitational_constant, &this_force_x, &this_force_y, &this_force_z);
                force_x += this_force_x;
                force_y += this_force_y;
                force_z += this_force_z;
            }
            update_planet(&sim->planets[i], force_x, force_y, force_z, sim->time_step);
        }
    }
}

/* Function to print the planets' positions */
void print_planets(Planet *planets, int num_planets) {
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d: x=%.2f y=%.2f z=%.2f\n", i, planets[i].x, planets[i].y, planets[i].z);
    }
}

int main() {
    // Create a simulation with 3 planets
    Planet p1 = {0, 0, 0, 0, 0, 0, 1};
    Planet p2 = {5, 0, 0, 0, 10, 0, 2};
    Planet p3 = {0, 5, 0, -10, 0, 0, 3};
    Simulation sim = {3, (Planet[]){p1, p2, p3}, 0.01, 1};
    
    // Simulate the gravity for 1000 time steps
    simulate_gravity(&sim, 1000);
    
    // Print the final positions of the planets
    print_planets(sim.planets, sim.num_planets);
    
    return 0;
}