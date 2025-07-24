//FormAI DATASET v1.0 Category: Physics simulation ; Style: future-proof
#include <stdio.h>

#define DELTA_T 0.01 // time step size

// Define a structure to store the position and velocity components of a particle
typedef struct
{
    double x, y; // position
    double vx, vy; // velocity
} Particle;

// Define a function to update the velocity and position of a particle due to gravity and air resistance
void update_particle(Particle *p, double mass, double k, double g)
{
    double Fgx = -mass * g; // force due to gravity in the x direction
    double Fgy = -mass * g; // force due to gravity in the y direction
    double Fdx = -k * p->vx * p->vx; // force due to air resistance in the x direction
    double Fdy = -k * p->vy * p->vy; // force due to air resistance in the y direction
    
    // Calculate the acceleration components
    double ax = (Fgx + Fdx) / mass;
    double ay = (Fgy + Fdy) / mass;
    
    // Update the velocity using the acceleration
    p->vx += ax * DELTA_T;
    p->vy += ay * DELTA_T;
    
    // Update the position using the velocity
    p->x += p->vx * DELTA_T;
    p->y += p->vy * DELTA_T;
}

int main()
{
    Particle p; // create a particle
    p.x = 0;
    p.y = 0;
    p.vx = 10;
    p.vy = 20;
    
    double mass = 1;
    double k = 0.1;
    double g = 9.8;
    
    int i;
    for (i = 0; i < 100; i++)
    {
        update_particle(&p, mass, k, g); // update the particle's position and velocity
        
        printf("Particle position: (%f, %f)\n", p.x, p.y);
    }
    
    return 0;
}