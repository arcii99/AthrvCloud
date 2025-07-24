//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: safe
#include <stdio.h>
#include <math.h>

#define G 6.6743e-11 // Universal Gravitational Constant

struct body {
    double mass; // Mass of the body
    double x; // x-coordinate of the body
    double y; // y-coordinate of the body
    double z; // z-coordinate of the body
    double vx; // x-velocity of the body
    double vy; // y-velocity of the body
    double vz; // z-velocity of the body
};

void update_position(struct body* b, double dt) {
    // Update position based on velocity and time
    b->x += b->vx * dt;
    b->y += b->vy * dt;
    b->z += b->vz * dt;
}

void update_velocity(struct body* b, struct body other, double dt) {
    // Compute the gravitational force between two bodies
    double dx = other.x - b->x;
    double dy = other.y - b->y;
    double dz = other.z - b->z;
    double distance = sqrt(dx*dx + dy*dy + dz*dz);
    
    double force = G * b->mass * other.mass / (distance * distance);
    
    // Compute the components of the gravitational force
    double fx = force * dx / distance;
    double fy = force * dy / distance;
    double fz = force * dz / distance;
    
    // Update velocity based on force and time
    b->vx += fx / b->mass * dt;
    b->vy += fy / b->mass * dt;
    b->vz += fz / b->mass * dt;
}

int main() {
    struct body sun = {1.989e30, 0, 0, 0, 0, 0, 0}; // Sun
    struct body earth = {5.972e24, 1.496e11, 0, 0, 0, 29783, 0}; // Earth
    struct body moon = {7.342e22, 1.496e11 + 3.844e8, 0, 0, 0, 29783 + 1023, 0}; // Moon
    
    double t = 0; // Time in seconds
    double dt = 3600; // Time step in seconds
    
    printf("Starting simulation of the Solar System (press Ctrl+C to quit):\n");
    printf("Time: %.2f days, Earth position: (%.2f, %.2f, %.2f), Moon position: (%.2f, %.2f, %.2f)\n", 
           t / 86400, earth.x, earth.y, earth.z, moon.x, moon.y, moon.z);
    
    // Simulation loop
    while (1) {
        // Update positions
        update_position(&earth, dt);
        update_position(&moon, dt);
        
        // Update velocities
        update_velocity(&earth, sun, dt);
        update_velocity(&earth, moon, dt);
        update_velocity(&moon, sun, dt);
        update_velocity(&moon, earth, dt);
        
        t += dt;
        
        printf("Time: %.2f days, Earth position: (%.2f, %.2f, %.2f), Moon position: (%.2f, %.2f, %.2f)\n", 
               t / 86400, earth.x, earth.y, earth.z, moon.x, moon.y, moon.z);
    }
    
    return 0;
}