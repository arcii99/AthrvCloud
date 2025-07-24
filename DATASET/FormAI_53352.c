//FormAI DATASET v1.0 Category: Physics simulation ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

// Define constants
#define PI 3.14159265
#define G 6.67430e-11

// Define structures
struct Vector {
    double x;
    double y;
};

struct Body {
    double mass;
    struct Vector position;
    struct Vector velocity;
};

// Define function to calculate the gravitational force between two bodies
struct Vector calc_gravity(struct Body body1, struct Body body2) {
    // Calculate distance between bodies
    double distance = sqrt(pow(body2.position.x - body1.position.x, 2) + pow(body2.position.y - body1.position.y, 2));
    
    // Calculate force magnitude
    double force_mag = (G * body1.mass * body2.mass) / pow(distance, 2);
    
    // Calculate force components
    double force_x = force_mag * (body2.position.x - body1.position.x) / distance;
    double force_y = force_mag * (body2.position.y - body1.position.y) / distance;
    
    // Return force as a vector
    struct Vector force = {force_x, force_y};
    return force;
}

int main() {
    // Initialize bodies
    struct Body earth = {5.972e24, {0, 0}, {0, 0}};
    struct Body moon = {7.342e22, {384.4e6, 0}, {0, 1022}};
    
    // Set simulation parameters
    double time_step = 60;
    double simulation_time = 86400 * 30;
    int num_steps = simulation_time / time_step;
    
    // Simulate motion of moon around earth
    for (int i = 0; i < num_steps; i++) {
        // Calculate gravitational force between earth and moon
        struct Vector gravity1 = calc_gravity(earth, moon);
        struct Vector gravity2 = calc_gravity(moon, earth);
        
        // Calculate acceleration of moon
        struct Vector accel1 = {gravity1.x / moon.mass, gravity1.y / moon.mass};
        struct Vector accel2 = {gravity2.x / earth.mass, gravity2.y / earth.mass};
        struct Vector accel = {accel1.x + accel2.x, accel1.y + accel2.y};
        
        // Update velocity and position of moon
        moon.velocity.x += accel.x * time_step;
        moon.velocity.y += accel.y * time_step;
        moon.position.x += moon.velocity.x * time_step;
        moon.position.y += moon.velocity.y * time_step;
        
        // Print moon position after each time step
        printf("Moon position at time %.2f days: x = %.2f km, y = %.2f km\n", (i+1) * time_step / 86400, moon.position.x / 1000, moon.position.y / 1000);
    }
    
    return 0;
}