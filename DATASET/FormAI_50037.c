//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITATIONAL_CONSTANT 6.67408e-11  // m^3 kg^-1 s^-2

typedef struct {
    double x, y, z;  // position
    double vx, vy, vz;  // velocity
    double fx, fy, fz;  // force
    double mass;
} body;

void compute_force(body *b1, body *b2) {
    double dx = b2->x - b1->x;
    double dy = b2->y - b1->y;
    double dz = b2->z - b1->z;
    
    double dist_squared = dx*dx + dy*dy + dz*dz;
    double dist_cubed = dist_squared * sqrt(dist_squared);
    
    double f = GRAVITATIONAL_CONSTANT * b1->mass * b2->mass / dist_cubed;
    
    b1->fx += f * dx;
    b1->fy += f * dy;
    b1->fz += f * dz;
    
    b2->fx -= f * dx;
    b2->fy -= f * dy;
    b2->fz -= f * dz;
}

void update_position_velocity(body *b, double dt) {
    b->vx += b->fx / b->mass * dt;
    b->vy += b->fy / b->mass * dt;
    b->vz += b->fz / b->mass * dt;
    
    b->x += b->vx * dt;
    b->y += b->vy * dt;
    b->z += b->vz * dt;
}

int main() {
    int num_bodies = 2;
    body b[num_bodies];
    
    // Set up position, velocity, and mass of each body
    b[0].x = 0;
    b[0].y = 0;
    b[0].z = 0;
    b[0].vx = 0;
    b[0].vy = 0;
    b[0].vz = 0;
    b[0].mass = 1;
    
    b[1].x = 1;
    b[1].y = 0;
    b[1].z = 0;
    b[1].vx = 0;
    b[1].vy = 1;
    b[1].vz = 1;
    b[1].mass = 1;
    
    double dt = 0.1;
    
    int num_steps = 100;
    for (int step = 0; step < num_steps; step++) {
        // Compute forces between all pairs of bodies
        for (int i = 0; i < num_bodies-1; i++) {
            for (int j = i+1; j < num_bodies; j++) {
                compute_force(&b[i], &b[j]);
            }
        }
        
        // Update positions and velocities of all bodies
        for (int i = 0; i < num_bodies; i++) {
            update_position_velocity(&b[i], dt);
            
            // Reset force for next step
            b[i].fx = 0;
            b[i].fy = 0;
            b[i].fz = 0;
        }
        
        printf("Step %d\n", step+1);
        printf("Body 1: (%lf, %lf, %lf)\n", b[0].x, b[0].y, b[0].z);
        printf("Body 2: (%lf, %lf, %lf)\n", b[1].x, b[1].y, b[1].z);
    }
    
    return 0;
}