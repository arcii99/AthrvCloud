//FormAI DATASET v1.0 Category: Physics simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int num_particles = 100;
  double x[num_particles], y[num_particles], vx[num_particles], vy[num_particles], m[num_particles];

  // initialize initial conditions
  for(int i = 0; i < num_particles; i++) {
    x[i] = rand()%100 + 1; // random x coordinate from 1 to 100
    y[i] = rand()%100 + 1; // random y coordinate from 1 to 100
    vx[i] = rand()%10 - 5; // random x velocity from -5 to 5
    vy[i] = rand()%10 - 5; // random y velocity from -5 to 5
    m[i] = rand()%10 + 1; // random mass from 1 to 10
  }

  double G = 6.674e-11; // gravitational constant

  double dt = 0.1; // time step
  for (int t = 0; t < 1000; t++) { // loop over time steps
    for (int i = 0; i < num_particles; i++) { // loop over particles
      double ax = 0, ay = 0; // acceleration for particle i
      
      for (int j = 0; j < num_particles; j++) { // loop over other particles
        if (i == j) {
          continue; // skip calculations when i = j
        }
        
        double dx = x[j] - x[i];
        double dy = y[j] - y[i];
        double r = sqrt(dx*dx + dy*dy); // distance between particles
        double f = G*m[i]*m[j]/(r*r); // force between particles

        ax += f/m[i] * dx/r; // x component of acceleration
        ay += f/m[i] * dy/r; // y component of acceleration
      }

      // update position and velocity
      x[i] += vx[i]*dt + 0.5*ax*dt*dt;
      y[i] += vy[i]*dt + 0.5*ay*dt*dt;
      vx[i] += ax*dt;
      vy[i] += ay*dt;
    }
  }

  for (int i = 0; i < num_particles; i++) {
    printf("Particle %d final position: (%.2f, %.2f)\n", i+1, x[i], y[i]);
  }

  return 0;
}