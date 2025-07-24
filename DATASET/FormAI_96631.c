//FormAI DATASET v1.0 Category: Physics simulation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

#define G 6.67e-11  // Universal gravitational constant

typedef struct {
    double x;
    double y;
} Vector2d;  // Struct to represent a 2D vector

typedef struct {
    Vector2d position;
    Vector2d velocity;
    double mass;
} Body;  // Struct to represent a body in space

void update_position(Body *body, double time_step) {
    body->position.x += body->velocity.x * time_step;
    body->position.y += body->velocity.y * time_step;
}

void update_velocity(Body *body, Vector2d acceleration, double time_step) {
    body->velocity.x += acceleration.x * time_step;
    body->velocity.y += acceleration.y * time_step;
}

double get_distance(Vector2d a, Vector2d b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

Vector2d get_gravity_force(Body *a, Body *b) {
    double distance = get_distance(a->position, b->position);
    double force_magnitude = G * a->mass * b->mass / (distance*distance);
    Vector2d direction;
    direction.x = (b->position.x - a->position.x) / distance;
    direction.y = (b->position.y - a->position.y) / distance;
    Vector2d force;
    force.x = direction.x * force_magnitude;
    force.y = direction.y * force_magnitude;
    return force;
}

int main() {
    // Define the bodies
    Body sun = {
        .position = {0, 0},
        .velocity = {0, 0},
        .mass = 1.989e30  // Mass of the sun in kg
    };
    Body earth = {
        .position = {1.496e11, 0},
        .velocity = {0, 29.29e3},  // Orbital velocity of the earth in m/s
        .mass = 5.972e24  // Mass of the earth in kg
    };
    Body moon = {
        .position = {1.496e11 + 3.844e8, 0},
        .velocity = {0, 29.29e3 + 1.022e3},  // Orbital velocity of the moon in m/s
        .mass = 7.342e22  // Mass of the moon in kg
    };
    
    // Time parameters
    double total_time = 31556926 * 50;  // 50 years in seconds
    double time_step = 86400;  // 1 day in seconds
    int num_steps = (int)(total_time / time_step);
    
    // Simulation loop
    for (int i = 0; i < num_steps; i++) {
        // Calculate the forces
        Vector2d force_sun_earth = get_gravity_force(&sun, &earth);
        Vector2d force_sun_moon = get_gravity_force(&sun, &moon);
        Vector2d force_earth_moon = get_gravity_force(&earth, &moon);
        
        // Update the velocities
        update_velocity(&earth, force_sun_earth, time_step);
        update_velocity(&moon, force_sun_moon, time_step);
        update_velocity(&moon, force_earth_moon, time_step);
        
        // Update the positions
        update_position(&earth, time_step);
        update_position(&moon, time_step);
        
        // Print the positions
        printf("Earth: (%f, %f)\n", earth.position.x, earth.position.y);
        printf("Moon: (%f, %f)\n", moon.position.x, moon.position.y);
    }
    
    return 0;
}