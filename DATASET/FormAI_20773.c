//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: active
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // Gravitational Constant in m^3.kg^-1.s^-2

// Structure to hold information about celestial bodies
typedef struct {
    double mass; // in kg
    double position[3]; // in m
    double velocity[3]; // in m/s
    double acceleration[3]; // in m/s^2
} Body;

// Function to calculate the distance between two points in 3D space
double distance(double point1[], double point2[]) {
    double x_diff = point1[0] - point2[0];
    double y_diff = point1[1] - point2[1];
    double z_diff = point1[2] - point2[2];
    return sqrt(x_diff*x_diff + y_diff*y_diff + z_diff*z_diff);
}

// Function to calculate the gravitational force between two bodies
double gravitational_force(Body body1, Body body2) {
    double r = distance(body1.position, body2.position);
    return G * body1.mass * body2.mass / (r*r);
}

int main() {
    // Set up initial conditions for the solar system
    Body sun = {1.989e30, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    Body earth = {5.972e24, {-1.471e11, 0, 0}, {0, 3.0287e4, 0}, {0, 0, 0}};
    Body moon = {7.348e22, {-1.471e11 - 3.844e8, 0, 0}, {0, 3.0287e4 + 1.022e3, 0}, {0, 0, 0}};
    
    double dt = 3600; // Time step in seconds
    double simulation_time = 31536000; // Total simulation time in seconds (1 year)
    int iterations = simulation_time / dt;
    
    // Run simulation
    for (int i = 0; i < iterations; i++) {
        // Calculate gravitational forces
        double force_earth_sun = gravitational_force(earth, sun);
        double force_moon_earth = gravitational_force(moon, earth);
        double force_moon_sun = gravitational_force(moon, sun);
        
        // Calculate accelerations
        
        // Earth
        double acceleration_earth_x = force_earth_sun * (sun.position[0] - earth.position[0]) / (earth.mass);
        double acceleration_earth_y = force_earth_sun * (sun.position[1] - earth.position[1]) / (earth.mass);
        double acceleration_earth_z = force_earth_sun * (sun.position[2] - earth.position[2]) / (earth.mass);
        earth.acceleration[0] = acceleration_earth_x;
        earth.acceleration[1] = acceleration_earth_y;
        earth.acceleration[2] = acceleration_earth_z;
        
        // Moon
        double acceleration_moon_x = force_moon_earth * (earth.position[0] - moon.position[0]) / (moon.mass);
        acceleration_moon_x += force_moon_sun * (sun.position[0] - moon.position[0]) / (moon.mass);
        double acceleration_moon_y = force_moon_earth * (earth.position[1] - moon.position[1]) / (moon.mass);
        acceleration_moon_y += force_moon_sun * (sun.position[1] - moon.position[1]) / (moon.mass);
        double acceleration_moon_z = force_moon_earth * (earth.position[2] - moon.position[2]) / (moon.mass);
        acceleration_moon_z += force_moon_sun * (sun.position[2] - moon.position[2]) / (moon.mass);
        moon.acceleration[0] = acceleration_moon_x;
        moon.acceleration[1] = acceleration_moon_y;
        moon.acceleration[2] = acceleration_moon_z;
        
        // Update velocities
        
        // Earth
        earth.velocity[0] += earth.acceleration[0] * dt;
        earth.velocity[1] += earth.acceleration[1] * dt;
        earth.velocity[2] += earth.acceleration[2] * dt;
        
        // Moon
        moon.velocity[0] += moon.acceleration[0] * dt;
        moon.velocity[1] += moon.acceleration[1] * dt;
        moon.velocity[2] += moon.acceleration[2] * dt;
        
        // Update positions
        
        // Earth
        earth.position[0] += earth.velocity[0] * dt;
        earth.position[1] += earth.velocity[1] * dt;
        earth.position[2] += earth.velocity[2] * dt;
        
        // Moon
        moon.position[0] += moon.velocity[0] * dt;
        moon.position[1] += moon.velocity[1] * dt;
        moon.position[2] += moon.velocity[2] * dt;
        
        // Print current positions
        printf("Iteration: %d\n", i+1);
        printf("Earth position: (%f, %f, %f)\n", earth.position[0], earth.position[1], earth.position[2]);
        printf("Moon position: (%f, %f, %f)\n\n", moon.position[0], moon.position[1], moon.position[2]);
    }
    
    return 0;
}