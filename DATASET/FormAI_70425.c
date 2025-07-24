//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: systematic
#include <stdio.h>
#include <math.h>

#define G 6.67430e-11    // Gravitational constant
#define DELTA_T 0.01     // Timestep for simulation
#define MAX_STEPS 10000  // Maximum number of steps

typedef struct {
  double x, y, z;    // Position
  double vx, vy, vz; // Velocity
  double ax, ay, az; // Acceleration
  double mass;       // Mass
} Particle;

const int NUM_PARTICLES = 3;
Particle particles[] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000 }, // Massive central body
  { 0, 6371000, 0, 7800, 0, 0, 0, 0, 0, 100 }, // Small body in low Earth orbit
  { 0, 0, 384400000, 1022, 0, 0, 0, 0, 0, 10 } // Moon
};

int main() {
  int i, j, step;
  
  // Simulation loop
  for (step = 0; step < MAX_STEPS; step++) {

    // Calculate accelerations of all particles
    for (i = 0; i < NUM_PARTICLES; i++) {
      particles[i].ax = 0;
      particles[i].ay = 0;
      particles[i].az = 0;
      for (j = 0; j < NUM_PARTICLES; j++) {
        if (i != j) {  // Do not calculate the particle's interaction with itself
          double dx = particles[j].x - particles[i].x;
          double dy = particles[j].y - particles[i].y;
          double dz = particles[j].z - particles[i].z;
          double r = sqrt(dx*dx + dy*dy + dz*dz);
          double f = G * particles[i].mass * particles[j].mass / (r*r);
          particles[i].ax += f * dx / r;
          particles[i].ay += f * dy / r;
          particles[i].az += f * dz / r;
        }
      }
    }
    
    // Update positions and velocities of all particles
    for (i = 0; i < NUM_PARTICLES; i++) {
      particles[i].vx += particles[i].ax * DELTA_T;
      particles[i].vy += particles[i].ay * DELTA_T;
      particles[i].vz += particles[i].az * DELTA_T;
      particles[i].x += particles[i].vx * DELTA_T;
      particles[i].y += particles[i].vy * DELTA_T;
      particles[i].z += particles[i].vz * DELTA_T;
    }
    
    // Print the position of the small Earth orbit body every 100 steps
    if (step % 100 == 0) {
      printf("Step %d: Small body position (%lf, %lf, %lf)\n",
             step, particles[1].x, particles[1].y, particles[1].z);
    }
  }
  
  return 0;
}