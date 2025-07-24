//FormAI DATASET v1.0 Category: Physics simulation ; Style: futuristic
#include <stdio.h>
#include <math.h>

#define GRAVITY 9.81 // gravitational acceleration on Earth

// structure to represent a particle
typedef struct {
  double x, y, z; // position vector
  double vx, vy, vz; // velocity vector
  double ax, ay, az; // acceleration vector
  double mass; // mass of the particle
} Particle;

int main() {
  Particle p[3];
  
  // set initial conditions of particles
  p[0].x = 0.0; p[0].y = 0.0; p[0].z = 0.0;
  p[0].vx = 0.0; p[0].vy = 0.0; p[0].vz = 0.0;
  p[0].ax = 0.0; p[0].ay = 0.0; p[0].az = 0.0;
  p[0].mass = 1.0;

  p[1].x = 2.0; p[1].y = 0.0; p[1].z = 0.0;
  p[1].vx = 0.0; p[1].vy = 1.0; p[1].vz = 0.0;
  p[1].ax = 0.0; p[1].ay = 0.0; p[1].az = 0.0;
  p[1].mass = 2.0;

  p[2].x = 1.0; p[2].y = 3.0; p[2].z = 0.0;
  p[2].vx = 1.0; p[2].vy = -1.0; p[2].vz = 0.0;
  p[2].ax = 0.0; p[2].ay = 0.0; p[2].az = 0.0;
  p[2].mass = 3.0;

  // simulate motion of particles
  double dt = 0.01; // time step
  double t = 0.0; // current time
  int num_steps = 10000; // number of time steps to simulate

  for (int i = 0; i < num_steps; i++) {
    // calculate forces on each particle
    for (int j = 0; j < 3; j++) {
      p[j].ax = 0.0; p[j].ay = 0.0; p[j].az = 0.0;
      for (int k = 0; k < 3; k++) {
        if (j == k) continue;
        double dx = p[k].x - p[j].x;
        double dy = p[k].y - p[j].y;
        double dz = p[k].z - p[j].z;
        double r = sqrt(dx*dx + dy*dy + dz*dz);
        double f = GRAVITY * p[j].mass * p[k].mass / (r*r);
        p[j].ax += f * dx / r / p[j].mass;
        p[j].ay += f * dy / r / p[j].mass;
        p[j].az += f * dz / r / p[j].mass;
      }
    }

    // update positions and velocities using Verlet integration
    for (int j = 0; j < 3; j++) {
      p[j].x += p[j].vx*dt + 0.5*p[j].ax*dt*dt;
      p[j].y += p[j].vy*dt + 0.5*p[j].ay*dt*dt;
      p[j].z += p[j].vz*dt + 0.5*p[j].az*dt*dt;
      p[j].vx += 0.5*p[j].ax*dt;
      p[j].vy += 0.5*p[j].ay*dt;
      p[j].vz += 0.5*p[j].az*dt;
    }

    // output current state of particles
    printf("t = %lf\n", t);
    for (int j = 0; j < 3; j++) {
      printf("Particle %d: (%lf, %lf, %lf) (%lf, %lf, %lf)\n", j,
             p[j].x, p[j].y, p[j].z, p[j].vx, p[j].vy, p[j].vz);
    }

    t += dt;
  }

  return 0;
}