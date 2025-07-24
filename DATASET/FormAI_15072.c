//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // gravitational constant
#define TIME_STEP 0.1 // simulation time step
#define MAX_STEPS 10000 // maximum simulation steps

// Define a planet structure with mass, initial and current position and velocity
typedef struct {
    float mass, x, y, vx, vy;
} Planet;

// Define a function to calculate the distance between two planets
float distance(Planet p1, Planet p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {

    // Create two planets Earth and Moon
    Planet earth = {5.97e24, 0, 0, 0, 0};
    Planet moon = {7.35e22, 384400000, 0, 0, 1022};

    // Calculate the initial distance between Earth and Moon
    float dist = distance(earth, moon);

    // Calculate the initial gravitational force between Earth and Moon
    float force = G * earth.mass * moon.mass / pow(dist, 2);

    // Calculate the initial gravitational acceleration experienced by Moon towards Earth
    float accel = force / moon.mass;

    // Calculate the initial velocity of Moon using v = u + at
    moon.vx = -accel * TIME_STEP;
    moon.vy = -accel * TIME_STEP;

    // Simulate the motion of Moon around Earth
    for (int i = 0; i < MAX_STEPS; i++) {
        
        // Calculate the distance and gravitational force between Earth and Moon
        dist = distance(earth, moon);
        force = G * earth.mass * moon.mass / pow(dist, 2);
        
        // Calculate the gravitational acceleration experienced by Moon towards Earth
        accel = force / moon.mass;
        
        // Calculate the new velocity of Moon using v = u + at
        moon.vx += accel * TIME_STEP;
        moon.vy += accel * TIME_STEP;

        // Calculate the new position of Moon using s = ut + 1/2at^2
        moon.x += moon.vx * TIME_STEP + 0.5 * accel * pow(TIME_STEP, 2);
        moon.y += moon.vy * TIME_STEP + 0.5 * accel * pow(TIME_STEP, 2);

        // Print the current position of Moon
        printf("Step %d: Moon position (%.2f, %.2f)\n", i+1, moon.x, moon.y);
    }

    return 0;
}