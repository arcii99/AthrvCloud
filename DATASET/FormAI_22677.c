//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constants
#define G 6.674e-11  // Gravitational constant
#define timestep 3600 // Simulation timestep in seconds
#define duration 86400 // Simulation duration in seconds
#define num_bodies 3 // Number of bodies in the system

// Struct for holding body data
typedef struct {
  double mass;
  double x_pos;
  double y_pos;
  double x_vel;
  double y_vel;
} body;

// Recursive function for calculating position and velocity at each timestep
void position(body* b, int i) {
  if (i == duration / timestep) {
    return; // Base case: end of simulation
  }

  // Calculate the force acting on this body from all other bodies in the system
  double fx = 0, fy = 0;
  for (int j = 0; j < num_bodies; j++) {
    if (j != i) {
      double dx = b[j].x_pos - b[i].x_pos;
      double dy = b[j].y_pos - b[i].y_pos;
      double r = sqrt(dx*dx + dy*dy);
      double f = G * b[i].mass * b[j].mass / (r*r);
      fx += f * dx / r;
      fy += f * dy / r;
    }
  }

  // Update position and velocity based on the force acting on this body
  b[i].x_vel += fx / b[i].mass * timestep;
  b[i].y_vel += fy / b[i].mass * timestep;
  b[i].x_pos += b[i].x_vel * timestep;
  b[i].y_pos += b[i].y_vel * timestep;

  // Recursively call function for next timestep
  position(b, i+1);
}

int main() {
  // Initialize bodies in the system
  body b[num_bodies] = {
    {5.97e24, 0, 0, 0, 0},
    {6.39e23, 3.84e8, 0, 0, 1022},
    {7.34e22, 3.84e8, 3.84e8, -1022, 0}
  };

  // Run simulation
  position(b, 0);

  // Print final positions and velocities of bodies
  for (int i = 0; i < num_bodies; i++) {
    printf("Body %d:\n", i+1);
    printf("Position (m): x=%.2f y=%.2f\n", b[i].x_pos, b[i].y_pos);
    printf("Velocity (m/s): x=%.2f y=%.2f\n", b[i].x_vel, b[i].y_vel);
  }

  return 0;
}