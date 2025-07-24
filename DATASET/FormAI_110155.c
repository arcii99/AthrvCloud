//FormAI DATASET v1.0 Category: Physics simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define global constants
#define G 6.6743e-11 // Gravitational constant in m^3/kg/s^2
#define TIME_STEP 3600 // Time step in seconds

// Define struct for storing relevant object information
typedef struct Object {
    double mass; // Mass in kg
    double pos[2]; // Position in m
    double vel[2]; // Velocity in m/s
} Object;

// Define function for calculating distance between two objects
double get_distance(Object obj1, Object obj2) {
    double x_diff = obj2.pos[0] - obj1.pos[0];
    double y_diff = obj2.pos[1] - obj1.pos[1];
    double dist = sqrt(x_diff * x_diff + y_diff * y_diff);
    return dist;
}

// Define function for calculating force between two objects
double get_force(Object obj1, Object obj2) {
    double dist = get_distance(obj1, obj2);
    double force = G * obj1.mass * obj2.mass / (dist * dist);
    return force;
}

int main() {
    // Set up initial objects
    Object sun = {1.989e+30, {0, 0}, {0, 0}}; // Sun
    Object earth = {5.972e+24, {147e+9, 0}, {0, 30e+3}}; // Earth
    Object moon = {7.342e+22, {147e+9 + 384e+6, 0}, {0, 30e+3 + 1e+3}}; // Moon

    // Set up simulation variables
    double t = 0; // Time in seconds
    double sim_length = 365.25 * 24 * 3600; // Simulation length in seconds
    double force; // Force between two objects
    double x_acc, y_acc; // Acceleration in x and y directions
    double x_vel_old, y_vel_old; // Previous velocity in x and y directions

    // Begin simulation loop
    while (t < sim_length) {
        // Calculate force on earth due to sun and moon
        force = get_force(sun, earth) + get_force(moon, earth);

        // Calculate acceleration due to force on earth
        x_acc = force / earth.mass * cos(atan2(earth.pos[1], earth.pos[0]));
        y_acc = force / earth.mass * sin(atan2(earth.pos[1], earth.pos[0]));

        // Calculate new velocity of earth
        earth.vel[0] += (x_acc * TIME_STEP);
        earth.vel[1] += (y_acc * TIME_STEP);

        // Update earth's position based on new velocity
        earth.pos[0] += (earth.vel[0] * TIME_STEP);
        earth.pos[1] += (earth.vel[1] * TIME_STEP);

        // Calculate force on moon due to sun and earth
        force = get_force(sun, moon) + get_force(earth, moon);

        // Calculate acceleration due to force on moon
        x_acc = force / moon.mass * cos(atan2(moon.pos[1], moon.pos[0]));
        y_acc = force / moon.mass * sin(atan2(moon.pos[1], moon.pos[0]));

        // Calculate new velocity of moon
        moon.vel[0] += (x_acc * TIME_STEP);
        moon.vel[1] += (y_acc * TIME_STEP);

        // Update moon's position based on new velocity
        moon.pos[0] += (moon.vel[0] * TIME_STEP);
        moon.pos[1] += (moon.vel[1] * TIME_STEP);

        // Output time and positions of earth and moon
        printf("Time: %lf seconds\n", t);
        printf("Earth position: (%lf, %lf) m\n", earth.pos[0], earth.pos[1]);
        printf("Moon position: (%lf, %lf) m\n\n", moon.pos[0], moon.pos[1]);

        // Update time
        t += TIME_STEP;
    }

    return 0;
}