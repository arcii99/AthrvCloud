//FormAI DATASET v1.0 Category: Physics simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants

#define GRAVITY -9.8f      // acceleration due to gravity (m/s^s)
#define FRAMERATE 60       // frame rate (frames per second)
#define TIMESTEP (1.0f/60) // timestep for simulation (seconds)

// Structures

typedef struct {
    float x;    // x-coordinate
    float y;    // y-coordinate
    float z;    // z-coordinate
    float vx;   // velocity in x-direction
    float vy;   // velocity in y-direction
    float vz;   // velocity in z-direction
    float ax;   // acceleration in x-direction
    float ay;   // acceleration in y-direction
    float az;   // acceleration in z-direction
} Particle;

// Functions

void print_particle(Particle p) {
    printf("Position: (%f, %f, %f)\n", p.x, p.y, p.z);
    printf("Velocity: (%f, %f, %f)\n", p.vx, p.vy, p.vz);
    printf("Acceleration: (%f, %f, %f)\n", p.ax, p.ay, p.az);
}

void update_particle(Particle *p) {
    // update acceleration due to gravity
    p->ax = 0;
    p->ay = GRAVITY;
    p->az = 0;
    
    // update velocity using Euler's method
    p->vx += p->ax * TIMESTEP;
    p->vy += p->ay * TIMESTEP;
    p->vz += p->az * TIMESTEP;
    
    // update position using Euler's method
    p->x += p->vx * TIMESTEP;
    p->y += p->vy * TIMESTEP;
    p->z += p->vz * TIMESTEP;
}

// Main function

int main(int argc, char **argv) {
    Particle ball = { 0, 10, 0, 5, 0, 0, 0, 0, 0 }; // create a particle
    
    for (int i = 0; i < FRAMERATE * 10; i++) { // simulate for 10 seconds
        
        printf("----- Frame %d -----\n", i+1);
        print_particle(ball); // print position, velocity, and acceleration
    
        update_particle(&ball); // update position, velocity, and acceleration
    }
    
    return 0;
}