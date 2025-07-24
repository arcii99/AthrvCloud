//FormAI DATASET v1.0 Category: Physics simulation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67E-11 // gravitational constant
#define DELTAT 0.001 // time step

struct planet {
  double x;
  double y;
  double vx;
  double vy;
  double mass;
};

int main() {
  struct planet sun = {0, 0, 0, 0, 1.989E30}; // initialize sun
  struct planet earth = {1.496E11, 0, 0, 2.978E4, 5.972E24}; // initialize earth
  double r, a, ax, ay; // r: distance between sun and earth, a: acceleration magnitude, ax, ay: acceleration components
  int steps = 365 * 24 * 3600 / DELTAT; // number of time steps per year

  for (int i = 0; i < steps; i++) {
    // calculate distance between sun and earth
    r = sqrt(pow(earth.x - sun.x, 2) + pow(earth.y - sun.y, 2));
    
    // calculate acceleration magnitude
    a = G * sun.mass / pow(r, 2);
    
    // calculate acceleration components
    ax = -a * (earth.x - sun.x) / r;
    ay = -a * (earth.y - sun.y) / r;
    
    // update earth's velocity
    earth.vx += ax * DELTAT;
    earth.vy += ay * DELTAT;
    
    // update earth's position
    earth.x += earth.vx * DELTAT;
    earth.y += earth.vy * DELTAT;
  }

  printf("Final position of earth: (%.2f, %.2f)", earth.x, earth.y);

  return 0;
}