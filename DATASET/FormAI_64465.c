//FormAI DATASET v1.0 Category: Physics simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define num_particles 1000 // number of particles in the system

struct Particle {
    double x, y, z; // particle position
    double vx, vy, vz; // particle velocity
    double mass; // particle mass
};

int main() {
    
    struct Particle Particles[num_particles]; // initialize particle system
    
    // initialize random particle positions, velocities and masses
    for(int i=0; i<num_particles; i++) {
        Particles[i].x = ((double) rand() / RAND_MAX) * 10.0;
        Particles[i].y = ((double) rand() / RAND_MAX) * 10.0;
        Particles[i].z = ((double) rand() / RAND_MAX) * 10.0;
        Particles[i].vx = ((double) rand() / RAND_MAX) * 0.1;
        Particles[i].vy = ((double) rand() / RAND_MAX) * 0.1;
        Particles[i].vz = ((double) rand() / RAND_MAX) * 0.1;
        Particles[i].mass = ((double) rand() / RAND_MAX) * 10.0;
    }
    
    // set up simulation parameters
    double epsilon = 0.1; // epsilon scaling factor
    double timestep = 0.001; // time step for simulation
    double G = 6.674e-11; // gravitational constant
    
    // perform simulation
    for(int t=0; t<10000; t++) { // iterate over time steps
        for(int i=0; i<num_particles; i++) { // iterate over particles
            double ax = 0.0; // initialize acceleration
            double ay = 0.0;
            double az = 0.0;
            for(int j=0; j<num_particles; j++) { // iterate over other particles
                if(i==j) continue; // skip self-interaction
                double dx = Particles[j].x - Particles[i].x; // calculate distance between particles
                double dy = Particles[j].y - Particles[i].y;
                double dz = Particles[j].z - Particles[i].z;
                double dist = sqrt(dx*dx + dy*dy + dz*dz); // calculate magnitude of distance vector
                double force = G * Particles[i].mass * Particles[j].mass / pow(dist+epsilon, 2); // calculate force between particles
                ax += force * dx / dist; // add component of force to x acceleration
                ay += force * dy / dist; // add component of force to y acceleration
                az += force * dz / dist; // add component of force to z acceleration
            }
            Particles[i].vx += ax * timestep; // update particle velocity
            Particles[i].vy += ay * timestep;
            Particles[i].vz += az * timestep;
            Particles[i].x += Particles[i].vx * timestep; // update particle position
            Particles[i].y += Particles[i].vy * timestep;
            Particles[i].z += Particles[i].vz * timestep;
        }
    }
    
    // print final particle positions
    for(int i=0; i<num_particles; i++) {
        printf("%f, %f, %f\n", Particles[i].x, Particles[i].y, Particles[i].z);
    }
    
    return 0;
}