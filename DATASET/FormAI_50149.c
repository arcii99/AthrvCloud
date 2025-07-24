//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: grateful
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // gravitational constant
#define TIME_STEP 3600 // time step in seconds

typedef struct {
    double x, y;
} Vector2D;

typedef struct {
    Vector2D position, velocity, acceleration;
    double mass;
} Planet;

int main() {
    // Set up the initial conditions of the system
    Planet earth = { { 0, 0 }, { 0, 0 }, { 0, 0 }, 5.97e24 };
    Planet moon = { { 3.8e8, 0 }, { 0, 1022 }, { 0, 0 }, 7.35e22 };
    
    // Calculate the initial gravitational forces
    Vector2D force = { (G * earth.mass * moon.mass) / pow(moon.position.x - earth.position.x, 2), 0 };
    
    // Simulate the system for one day
    int num_steps = 24 * 60 * 60 / TIME_STEP;
    for(int i = 0; i < num_steps; i++) {
        // Update the positions of the planets based on their velocities
        earth.position.x += earth.velocity.x * TIME_STEP;
        earth.position.y += earth.velocity.y * TIME_STEP;
        moon.position.x += moon.velocity.x * TIME_STEP;
        moon.position.y += moon.velocity.y * TIME_STEP;
        
        // Calculate the new gravitational forces based on the updated positions
        double distance = sqrt(pow(moon.position.x - earth.position.x, 2) + pow(moon.position.y - earth.position.y, 2));
        force.x = (G * earth.mass * moon.mass) / pow(distance, 2);
        force.y = (G * earth.mass * moon.mass) / pow(distance, 2) * (moon.position.y - earth.position.y) / distance;
        
        // Update the accelerations based on the new forces
        earth.acceleration.x = force.x / earth.mass;
        earth.acceleration.y = force.y / earth.mass;
        moon.acceleration.x = -force.x / moon.mass;
        moon.acceleration.y = -force.y / moon.mass;
        
        // Update the velocities based on the new accelerations
        earth.velocity.x += earth.acceleration.x * TIME_STEP;
        earth.velocity.y += earth.acceleration.y * TIME_STEP;
        moon.velocity.x += moon.acceleration.x * TIME_STEP;
        moon.velocity.y += moon.acceleration.y * TIME_STEP;
        
        // Output the current positions of the planets
        printf("Earth: (%f, %f)\nMoon: (%f, %f)\n", earth.position.x, earth.position.y, moon.position.x, moon.position.y);
    }
    
    return 0;
}