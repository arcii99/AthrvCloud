//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.67e-11 // Gravitational constant in m^3 kg^-1 s^-2
#define SUN_MASS 1.989e30 // Mass of the sun in kg

typedef struct {
    double x, y, z; // Position vector in metres
} Vector;

typedef struct {
    Vector position; // Position vector in metres
    Vector velocity; // Velocity vector in metres per second
    double mass; // Mass of the body in kg
} Body;

Vector add_vectors(Vector v1, Vector v2) { // Function to add two vectors
    Vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    result.z = v1.z + v2.z;
    return result;
}

Vector subtract_vectors(Vector v1, Vector v2) { // Function to subtract two vectors
    Vector result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    result.z = v1.z - v2.z;
    return result;
}

Vector multiply_vector_by_scalar(Vector v, double scalar) { // Function to multiply a vector by a scalar
    Vector result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    result.z = v.z * scalar;
    return result;
}

double calculate_distance(Vector v1, Vector v2) { // Function to calculate the distance between two points
    double dx = v1.x - v2.x;
    double dy = v1.y - v2.y;
    double dz = v1.z - v2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

Vector calculate_gravitational_force(Body body1, Body body2) { // Function to calculate the gravitational force between two bodies
    Vector force;
    double distance = calculate_distance(body1.position, body2.position);
    double force_magnitude = GRAVITATIONAL_CONSTANT * body1.mass * body2.mass / (distance*distance);
    force = subtract_vectors(body1.position, body2.position);
    force = multiply_vector_by_scalar(force, force_magnitude);
    force = multiply_vector_by_scalar(force, 1 / distance);
    return force;
}

int main() {
    // Define the bodies in our solar system
    Body sun = {{0, 0, 0}, {0, 0, 0}, SUN_MASS};
    Body earth = {{147e9, 0, 0}, {0, 30e3, 0}, 5.97e24};
    Body moon = {{147e9 + 384e6, 0, 0}, {0, 30e3 + 1e3, 0}, 7.342e22};

    // Define the time step and simulation duration
    double time_step = 86400; // One day in seconds
    double simulation_duration = 365 * time_step; // One year in days

    // Run the simulation
    for (double t = 0; t < simulation_duration; t += time_step) {
        // Calculate the gravitational forces on each body
        Vector sun_to_earth_force = calculate_gravitational_force(sun, earth);
        Vector earth_to_sun_force = multiply_vector_by_scalar(sun_to_earth_force, -1);
        Vector earth_to_moon_force = calculate_gravitational_force(earth, moon);
        Vector moon_to_earth_force = multiply_vector_by_scalar(earth_to_moon_force, -1);

        // Update the velocities of each body
        earth.velocity = add_vectors(earth.velocity, multiply_vector_by_scalar(add_vectors(sun_to_earth_force, earth_to_moon_force), time_step / earth.mass));
        moon.velocity = add_vectors(moon.velocity, multiply_vector_by_scalar(add_vectors(earth_to_moon_force, moon_to_earth_force), time_step / moon.mass));

        // Update the positions of each body
        earth.position = add_vectors(earth.position, multiply_vector_by_scalar(earth.velocity, time_step));
        moon.position = add_vectors(moon.position, multiply_vector_by_scalar(moon.velocity, time_step));
    }

    return 0;
}