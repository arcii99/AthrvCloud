//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67430e-11 // Gravitational Constant
#define MAX_PLANETS 10 // Maximum Number of Planets
#define MAX_RADIUS 100 // Maximum radius of planets

typedef struct Planet {
    double x, y; // Position of planet
    double vx, vy; // Velocity of planet
    double fx, fy; // Force acting on planet
    double mass; // Mass of planet
} planet_t;

planet_t planets[MAX_PLANETS]; // Array of planets
int num_planets = 0; // number of planets

// Randomly initialize planet positions and velocities
void init_planets() {
    int i;
    for(i = 0; i < num_planets; i++) {
        planets[i].x = rand() % (2 * MAX_RADIUS) - MAX_RADIUS;
        planets[i].y = rand() % (2 * MAX_RADIUS) - MAX_RADIUS;
        planets[i].vx = rand() % 200 - 100;
        planets[i].vy = rand() % 200 - 100;
        planets[i].fx = 0;
        planets[i].fy = 0;
        planets[i].mass = rand() % 100 + 1;
    }
}

// Compute the gravitational force between two planets
void compute_force(planet_t *p1, planet_t *p2) {
    double dx, dy, distance, force;
    
    dx = p2->x - p1->x;
    dy = p2->y - p1->y;
    distance = sqrt(dx * dx + dy * dy);
    
    force = G * p1->mass * p2->mass / (distance * distance);
    
    p1->fx += force * dx / distance;
    p1->fy += force * dy / distance;
    
    p2->fx -= force * dx / distance;
    p2->fy -= force * dy / distance;
}

// Compute forces acting on each planet
void compute_forces() {
    int i, j;
    for(i = 0; i < num_planets - 1; i++) {
        for(j = i+1; j < num_planets; j++) {
            compute_force(&planets[i], &planets[j]);
        }
    }
}

// Update the position and velocity of each planet based on the forces acting on it
void update_planets(double dt) {
    int i;
    for(i = 0; i < num_planets; i++) {
        // Update velocity
        planets[i].vx += planets[i].fx / planets[i].mass * dt;
        planets[i].vy += planets[i].fy / planets[i].mass * dt;
        
        // Update position
        planets[i].x += planets[i].vx * dt;
        planets[i].y += planets[i].vy * dt;
        
        // Reset forces
        planets[i].fx = 0;
        planets[i].fy = 0;
    }
}

// Print the positions of each planet
void print_positions() {
    int i;
    for(i = 0; i < num_planets; i++) {
        printf("Planet %d: (%f, %f)\n", i+1, planets[i].x, planets[i].y);
    }
}

int main() {
    double dt = 0.1;
    int i;
    
    srand(time(NULL));
    
    // Initialize planets
    num_planets = rand() % MAX_PLANETS + 1;
    init_planets();
    
    // Run simulation
    for(i = 0; i < 100; i++) {
        compute_forces();
        update_planets(dt);
    }
    
    // Print positions
    print_positions();
    
    return 0;
}