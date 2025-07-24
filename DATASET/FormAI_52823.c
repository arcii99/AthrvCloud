//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRAVITATIONAL_CONSTANT 6.674E-11 // m^3 kg^-1 s^-2
#define TIME_STEP 1000 // seconds
#define NUM_PLANETS 6
#define MAX_INITIAL_VELOCITY 100 // m/s
#define MAX_INITIAL_MASS 5E24 // kg
#define MAX_INITIAL_DISTANCE 1E10 // m

typedef struct {
    double x;
    double y;
    double z;
} Vector;

typedef struct {
    double mass;
    Vector position;
    Vector velocity;
} Planet;

Planet planets[NUM_PLANETS];

void initialize_planets() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize planets with random properties
    for (int i = 0; i < NUM_PLANETS; i++) {
        planets[i].mass = (double) rand() / RAND_MAX * MAX_INITIAL_MASS;
        planets[i].position.x = (double) rand() / RAND_MAX * MAX_INITIAL_DISTANCE;
        planets[i].position.y = (double) rand() / RAND_MAX * MAX_INITIAL_DISTANCE;
        planets[i].position.z = (double) rand() / RAND_MAX * MAX_INITIAL_DISTANCE;
        planets[i].velocity.x = (double) rand() / RAND_MAX * MAX_INITIAL_VELOCITY;
        planets[i].velocity.y = (double) rand() / RAND_MAX * MAX_INITIAL_VELOCITY;
        planets[i].velocity.z = (double) rand() / RAND_MAX * MAX_INITIAL_VELOCITY;
    }
}

Vector calculate_gravitational_force(Planet planet1, Planet planet2) {
    Vector force;
    double distance_squared = pow(planet1.position.x - planet2.position.x, 2) 
                            + pow(planet1.position.y - planet2.position.y, 2) 
                            + pow(planet1.position.z - planet2.position.z, 2);
    double distance = sqrt(distance_squared);
    double force_magnitude = GRAVITATIONAL_CONSTANT * planet1.mass * planet2.mass / distance_squared;
    force.x = force_magnitude * (planet1.position.x - planet2.position.x) / distance;
    force.y = force_magnitude * (planet1.position.y - planet2.position.y) / distance;
    force.z = force_magnitude * (planet1.position.z - planet2.position.z) / distance;
    return force;
}

void update_planets() {
    // Calculate net forces
    Vector forces[NUM_PLANETS] = {{0.0, 0.0, 0.0}};
    for (int i = 0; i < NUM_PLANETS; i++) {
        for (int j = i + 1; j < NUM_PLANETS; j++) {
            Vector force = calculate_gravitational_force(planets[i], planets[j]);
            forces[i].x += force.x;
            forces[i].y += force.y;
            forces[i].z += force.z;
            forces[j].x -= force.x;
            forces[j].y -= force.y;
            forces[j].z -= force.z;
        }
    }
    
    // Update positions and velocities
    for (int i = 0; i < NUM_PLANETS; i++) {
        Vector acceleration = { forces[i].x / planets[i].mass, forces[i].y / planets[i].mass, forces[i].z / planets[i].mass };
        planets[i].velocity.x += acceleration.x * TIME_STEP;
        planets[i].velocity.y += acceleration.y * TIME_STEP;
        planets[i].velocity.z += acceleration.z * TIME_STEP;
        planets[i].position.x += planets[i].velocity.x * TIME_STEP;
        planets[i].position.y += planets[i].velocity.y * TIME_STEP;
        planets[i].position.z += planets[i].velocity.z * TIME_STEP;
    }
}

void print_planets() {
    for (int i = 0; i < NUM_PLANETS; i++) {
        printf("Planet %d\n", i + 1);
        printf("Mass: %e kg\n", planets[i].mass);
        printf("Position: (%e, %e, %e) m\n", planets[i].position.x, planets[i].position.y, planets[i].position.z);
        printf("Velocity: (%e, %e, %e) m/s\n", planets[i].velocity.x, planets[i].velocity.y, planets[i].velocity.z);
    }
}

int main() {
    initialize_planets();
    printf("Initial state:\n");
    print_planets();
    for (int i = 1; i <= 10; i++) {
        printf("After %d seconds:\n", i * TIME_STEP);
        update_planets();
        print_planets();
    }
    return 0;
}