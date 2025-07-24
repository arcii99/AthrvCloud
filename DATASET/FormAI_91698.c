//FormAI DATASET v1.0 Category: Physics simulation ; Style: Donald Knuth
/* A Simple Physics Simulation Program in C */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 9.81 // gravitational constant
#define DT 0.01 // time step

int main() {
  double m1 = 0.5, m2 = 0.2; // masses of the two objects
  double r1[2] = {1.0, 1.0}, r2[2] = {1.0, 2.0}; // initial positions of the two objects
  double v1[2] = {0.0, 0.0}, v2[2] = {0.0, 0.0}; // initial velocities of the two objects
  double d[2], f[2], r[2], a1[2], a2[2]; // variables for position, force, acceleration
  int i;

  // simulate motion for 10 seconds
  for (double t = 0.0; t < 10.0; t += DT) {

    // calculate displacement between the two objects
    for (i = 0; i < 2; i++)
      r[i] = r2[i] - r1[i];

    // calculate distance and force between the two objects
    double distance = sqrt(r[0]*r[0] + r[1]*r[1]);
    double force = G * m1 * m2 / (distance * distance);
    for (i = 0; i < 2; i++)
      f[i] = force * r[i] / distance;

    // calculate acceleration
    for (i = 0; i < 2; i++)
      a1[i] = f[i] / m1;
    for (i = 0; i < 2; i++)
      a2[i] = -f[i] / m2;

    // update velocities
    for (i = 0; i < 2; i++)
      v1[i] += a1[i] * DT;
    for (i = 0; i < 2; i++)
      v2[i] += a2[i] * DT;

    // update positions
    for (i = 0; i < 2; i++)
      r1[i] += v1[i] * DT;
    for (i = 0; i < 2; i++)
      r2[i] += v2[i] * DT;

    // print positions of the two objects at current time
    printf("Time: %.2f, Object 1: (%.2f, %.2f), Object 2: (%.2f, %.2f)\n",
           t, r1[0], r1[1], r2[0], r2[1]);
  }

  return 0;
}