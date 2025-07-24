//FormAI DATASET v1.0 Category: Physics simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
  double time = 0, dt = 0.01; // set initial time and time step
  double mass = 1, k = 1, x = 1, v = 0; // set the physical parameters
  double E = 0.5 * mass * v * v + 0.5 * k * x * x; // calculate initial energy

  printf("Starting simulation with initial energy E = %lf.\n", E);
  printf("Time \t Position \t Velocity \t Energy\n");

  while (time < 10) { // run simulation for 10 seconds
    double a = -k * x / mass; // calculate acceleration
    x += v * dt; // update position
    v += a * dt; // update velocity
    time += dt; // update time
    E = 0.5 * mass * v * v + 0.5 * k * x * x; // calculate energy

    printf("%.2lf \t %.2lf \t \t %.2lf \t \t %.2lf\n", time, x, v, E); // output results
    if (E > 1.2) { // check if energy exceeds a certain threshold
      printf("Energy exceeded limit, exiting simulation...\n");
      break;
    }
  }

  printf("Simulation completed at time t = %.2lf.\n", time);
  return 0;
}