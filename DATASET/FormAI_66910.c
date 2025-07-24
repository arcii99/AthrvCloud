//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: dynamic
#include <stdio.h>
#include <math.h>

#define G 6.67384E-11 // Gravitational constant

typedef struct {
    double x, y; // Position
    double vx, vy; // Velocity
    double mass; // Mass
    double fx, fy; // Accumulated force (for simulation)
} Body;

void calculate_forces(Body* bodies, int num_bodies) {
    // For each pair of bodies, calculate the force between them
    for(int i = 0; i < num_bodies; i++) {
        for(int j = i+1; j < num_bodies; j++) {
            // Calculate distance between bodies
            double dx = bodies[j].x - bodies[i].x;
            double dy = bodies[j].y - bodies[i].y;
            double dist_squared = dx*dx + dy*dy;
            double dist = sqrt(dist_squared);
            
            // Calculate force between the bodies
            double force = G * bodies[i].mass * bodies[j].mass / dist_squared;
            double fx = force * dx / dist;
            double fy = force * dy / dist;
            
            // Add force to each body's accumulated force
            bodies[i].fx += fx;
            bodies[i].fy += fy;
            bodies[j].fx -= fx;
            bodies[j].fy -= fy;
        }
    }
}

void step_simulation(Body* bodies, int num_bodies, double timestep) {
    // Calculate forces between bodies
    calculate_forces(bodies, num_bodies);
    
    // Update positions and velocities of bodies
    for(int i = 0; i < num_bodies; i++) {
        // Update velocity using accumulated force
        bodies[i].vx += timestep * bodies[i].fx / bodies[i].mass;
        bodies[i].vy += timestep * bodies[i].fy / bodies[i].mass;
        
        // Update position using updated velocity
        bodies[i].x += timestep * bodies[i].vx;
        bodies[i].y += timestep * bodies[i].vy;
        
        // Reset accumulated force for next timestep
        bodies[i].fx = 0;
        bodies[i].fy = 0;
    }
}

int main() {
    // Set up initial state of the simulation
    int num_bodies = 3;
    Body bodies[3] = {
        {1e6, 0, 0, 5, 1e18},
        {0, 1e6, -5, 0, 1e18},
        {-1e6, 0, 0, -5, 1e18}
    };
    double timestep = 1e-5;
    double total_time = 1;
    
    // Run the simulation for the specified time
    int num_steps = total_time / timestep;
    for(int step = 0; step < num_steps; step++) {
        // Print the current state of the simulation
        printf("Step %d:\n", step);
        for(int i = 0; i < num_bodies; i++) {
            printf("  Body %d:\n", i);
            printf("    Position: (%f, %f)\n", bodies[i].x, bodies[i].y);
            printf("    Velocity: (%f, %f)\n", bodies[i].vx, bodies[i].vy);
        }
        
        // Step the simulation forward one timestep
        step_simulation(bodies, num_bodies, timestep);
    }
    
    return 0;
}