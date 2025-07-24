//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define G_CONSTANT 6.67428E-11 // Gravitational Constant

// Define a structure for planet containing name, mass, position, and velocity
typedef struct {
    char* name;
    double mass;
    double position[3];
    double velocity[3];
} Planet;

// Define a structure for thread arguments
typedef struct {
    Planet* planets;
    int num_planets;
    int interval; // Time interval in seconds
    int num_iterations;
} ThreadArgs;

// Calculate gravitational force between two planets
// Return the force vector
double* calculate_gravity(Planet planet1, Planet planet2) {
    double distance = 0;
    double force_magnitude = 0;
    double force_vector[3] = {0, 0, 0};
    double unit_vector[3] = {0, 0, 0};
    double* return_vector = (double*)malloc(3 * sizeof(double));
    
    // Calculate distance between the two planets
    for (int i = 0; i < 3; i++) {
        distance += pow((planet1.position[i] - planet2.position[i]), 2);
    }
    distance = sqrt(distance);
    
    // Calculate gravitational force between the two planets
    force_magnitude = G_CONSTANT * planet1.mass * planet2.mass / pow(distance, 2);
    
    // Calculate unit vector of force direction
    for (int i = 0; i < 3; i++) {
        unit_vector[i] = (planet1.position[i] - planet2.position[i]) / distance;
    }
    
    // Calculate force vector
    for (int i = 0; i < 3; i++) {
        force_vector[i] = force_magnitude * unit_vector[i];
    }
    
    // Set the return vector to the force vector
    for (int i = 0; i < 3; i++) {
        return_vector[i] = force_vector[i];
    }
    
    return return_vector;
}

// Update position and velocity of a planet based on net force vector and time interval
void update_planet(Planet* planet, double net_force[3], int interval) {
    double acceleration[3] = {0, 0, 0};
    double velocity_change[3] = {0, 0, 0};
    
    // Calculate acceleration based on net force
    for (int i = 0; i < 3; i++) {
        acceleration[i] = net_force[i] / planet->mass;
    }
    
    // Calculate velocity change based on acceleration and time interval
    for (int i = 0; i < 3; i++) {
        velocity_change[i] = acceleration[i] * interval;
    }
    
    // Update velocity
    for (int i = 0; i < 3; i++) {
        planet->velocity[i] += velocity_change[i];
    }
    
    // Update position based on new velocity and time interval
    for (int i = 0; i < 3; i++) {
        planet->position[i] += planet->velocity[i] * interval;
    }
}

// Thread function for updating the position and velocity of a planet over a certain time interval
void* update_thread(void* args) {
    ThreadArgs* t_args = (ThreadArgs*)args;
    Planet* planets = t_args->planets;
    int num_planets = t_args->num_planets;
    int interval = t_args->interval;
    int num_iterations = t_args->num_iterations;
    
    for (int i = 0; i < num_iterations; i++) {
        // Calculate net force for each planet
        double net_force[num_planets][3];
        for (int j = 0; j < num_planets; j++) {
            net_force[j][0] = 0;
            net_force[j][1] = 0;
            net_force[j][2] = 0;
            for (int k = 0; k < num_planets; k++) {
                if (j == k) {
                    continue;
                }
                double* force = calculate_gravity(planets[j], planets[k]);
                net_force[j][0] += force[0];
                net_force[j][1] += force[1];
                net_force[j][2] += force[2];
                free(force);
            }
        }
        
        // Update position and velocity for each planet
        for (int j = 0; j < num_planets; j++) {
            update_planet(&planets[j], net_force[j], interval);
        }
    }
    
    pthread_exit(NULL);
}

int main() {
    // Create planets
    Planet earth = {"Earth", 5.972E24, {0, 0, 0}, {0, 0, 0}};
    Planet moon = {"Moon", 7.342E22, {384400000, 0, 0}, {0, 1022, 0}};
    Planet mars = {"Mars", 6.39E23, {227936640, 0, 0}, {0, 24130, 0}};
    Planet planets[] = {earth, moon, mars};
    
    // Start simulation with multi-threading
    pthread_t threads[3];
    ThreadArgs args[3];
    
    for (int i = 0; i < 3; i++) {
        args[i].planets = planets;
        args[i].num_planets = 3;
        args[i].interval = 86400;
        args[i].num_iterations = 36500;
        pthread_create(&threads[i], NULL, update_thread, (void*)&args[i]);
    }
    
    // Wait for all threads to finish
    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Print final positions of planets
    printf("Final Positions:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: (%.3e, %.3e, %.3e)\n", planets[i].name, planets[i].position[0], planets[i].position[1], planets[i].position[2]);
    }
    
    return 0;
}