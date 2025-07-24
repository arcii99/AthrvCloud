//FormAI DATASET v1.0 Category: Physics simulation ; Style: mind-bending
#include <stdio.h>
#include <math.h>

int main() {
  int num_particles = 10; // number of particles to simulate
  double x[num_particles], y[num_particles]; // x, y position arrays
  double vx[num_particles], vy[num_particles]; // x, y velocity arrays
  double dt = 0.001; // time step
  double G = 6.674 * pow(10, -11); // gravitational constant
  double m = 1.0; // mass of particle
  int i, j; // loop indices
  double fx, fy, r, dx, dy; // force components, distance, x and y displacements

  // initialize particle positions and velocities randomly
  for (i = 0; i < num_particles; i++) {
    x[i] = rand() % 100 + 1;
    y[i] = rand() % 100 + 1;
    vx[i] = rand() % 10 + 1;
    vy[i] = rand() % 10 + 1;
  }

  // simulate motion of particles with gravity
  for (i = 0; i < 100000; i++) {
    for (j = 0; j < num_particles; j++) {
      fx = 0;
      fy = 0;
      for (int k = 0; k < num_particles; k++) {
        if(k == j) continue; // skip iteration when k == j to avoid self-interaction
        dx = x[j] - x[k];
        dy = y[j] - y[k];
        r = sqrt(pow(dx, 2) + pow(dy, 2));
        fx -= G * m * m / pow(r, 2) * dx / r;
        fy -= G * m * m / pow(r, 2) * dy / r;
      }
      vx[j] += fx * dt / m;
      vy[j] += fy * dt / m;
      x[j] += vx[j] * dt;
      y[j] += vy[j] * dt;
    }

    // print out the position of the first particle every 1000 time steps
    if (i % 1000 == 0) {
      printf("Particle 1 position: (%f, %f)\n", x[0], y[0]);
    }
  }

  return 0;
}