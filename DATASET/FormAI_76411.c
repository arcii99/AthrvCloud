//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67e-11 // Gravitational constant
#define MAX_BODIES 100 // Maximum number of bodies in the simulation
#define MAX_TIME 100000 // Maximum simulation time in seconds
#define TIME_STEP 1 // Time step in seconds

typedef struct {
    double mass; // Mass in kg
    double x; // X coordinate in m
    double y; // Y coordinate in m
    double vx; // Velocity in x direction in m/s
    double vy; // Velocity in y direction in m/s
} Body;

void calculate_force(Body *body1, Body *body2, double *force_x, double *force_y) {
    // Calculate distance between two bodies
    double dx = body1->x - body2->x;
    double dy = body1->y - body2->y;
    double distance = sqrt(dx*dx + dy*dy);
    
    if(distance == 0) { // Avoid division by zero
        return;
    }
    
    // Calculate force between two bodies
    double force = G * body1->mass * body2->mass / (distance*distance);
    
    // Calculate force components in x and y directions
    *force_x = force * dx / distance;
    *force_y = force * dy / distance;
}

void update_body(Body *body, double force_x, double force_y) {
    // Update velocity using the calculated force
    body->vx += force_x / body->mass * TIME_STEP;
    body->vy += force_y / body->mass * TIME_STEP;
    
    // Update position using the updated velocity
    body->x += body->vx * TIME_STEP;
    body->y += body->vy * TIME_STEP;
}

int main() {
    // Initialize bodies
    Body bodies[MAX_BODIES] = {
        {1e15, 0, 0, 0, 0}, // Center body
        {1e10, -1e11, 0, 0, 30e3}, // Orbiting body 1
        {1e10, 1e11, 0, 0, -30e3}, // Orbiting body 2
        {1e9, 0, 1e11, -40e3, 0}, // Moon
        {1e8, 0, -1e11, 25e3, 0} // Asteroid
    };
    
    // Get number of bodies
    int num_bodies = sizeof(bodies) / sizeof(Body);
    
    // Initialize time
    double t = 0;
    
    // Simulate gravity for MAX_TIME seconds
    while(t < MAX_TIME) {
        // Calculate forces between all pairs of bodies
        for(int i=0; i<num_bodies; i++) {
            for(int j=i+1; j<num_bodies; j++) {
                double force_x, force_y; // Temporary variables to hold force components
                calculate_force(&bodies[i], &bodies[j], &force_x, &force_y);
                update_body(&bodies[i], force_x, force_y);
                update_body(&bodies[j], -force_x, -force_y); // Negative force applied to the other body
            }
        }
        
        // Print positions of all bodies
        printf("Time: %.2lf s\n", t);
        for(int i=0; i<num_bodies; i++) {
            printf("Body %d: x=%.2lf m, y=%.2lf m\n", i+1, bodies[i].x, bodies[i].y);
        }
        printf("\n");
        
        // Update time
        t += TIME_STEP;
    }
    
    return 0;
}