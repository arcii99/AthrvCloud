//FormAI DATASET v1.0 Category: Physics simulation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define G 6.67430e-11  // Gravitational constant

typedef struct{
    double x, y;       // Position vector
    double vx, vy;     // Velocity vector
    double fx, fy;     // Force vector
    double mass, radius;
} Body;

// Compute the force between two bodies using gravity equation
void computeForce(Body *a, Body *b){
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    double d = sqrt(dx*dx + dy*dy);
    double f = G * a->mass * b->mass / (d*d);
    double fx = f * dx / d;
    double fy = f * dy / d;
    a->fx += fx;
    a->fy += fy;
    b->fx -= fx;
    b->fy -= fy;
}

// Perform one timestep of the simulation
void timestep(Body *bodies, int n, double dt){
    int i;
    // Reset all forces to zero
    for(i=0; i<n; i++){
        bodies[i].fx = bodies[i].fy = 0.0;
    }
    // Compute forces between bodies
    for(i=0; i<n-1; i++){
        int j;
        for(j=i+1; j<n; j++){
            computeForce(&bodies[i], &bodies[j]);
        }
    }
    // Update positions and velocities using Euler's method
    for(i=0; i<n; i++){
        Body *b = &bodies[i];
        b->x += b->vx * dt + 0.5 * b->fx / b->mass * dt*dt;
        b->y += b->vy * dt + 0.5 * b->fy / b->mass * dt*dt;
        b->vx += b->fx / b->mass * dt;
        b->vy += b->fy / b->mass * dt;
    }
}

int main(){
    // Create some bodies
    Body bodies[] = {
        {0.0, 0.0, 0.0, 0.0, 5.97e24, 6.371e6},
        {1000.0, 0.0, 0.0, 8000.0, 1.0, 1.0},
        {0.0, 1000.0, -8000.0, 0.0, 1.0, 1.0},
        {-1000.0, 0.0, 0.0, -8000.0, 1.0, 1.0},
        {0.0, -1000.0, 8000.0, 0.0, 1.0, 1.0}
    };
    int n = sizeof(bodies) / sizeof(Body);
    // Set initial positions and velocities
    int i;
    for(i=0; i<n; i++){
        double r = bodies[i].radius;
        double v = sqrt(G * bodies[0].mass / r);
        double theta = i * 2 * M_PI / n;
        bodies[i].x = r * cos(theta);
        bodies[i].y = r * sin(theta);
        bodies[i].vx = v * sin(theta);
        bodies[i].vy = -v * cos(theta);
    }
    // Run simulation
    double t = 0.0;
    double dt = 100.0;
    int steps = 1000;
    for(i=0; i<steps; i++){
        printf("%f,%f,%f,%f\n", bodies[1].x, bodies[1].y, bodies[2].x, bodies[2].y);
        timestep(bodies, n, dt);
        t += dt;
    }
    return 0;
}