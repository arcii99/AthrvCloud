//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define R1 800
#define R2 1200
#define C1 0.22e-6

// Function to calculate voltage at a given time t
double voltage(double t) {
  double w = 1 / (R1 * C1);
  double z = sqrt(1 / (w * w) - t * t);
  return R2 / R1 * z;
}

int main() {
  // Define variables
  double t = 0;
  double dt = 0.001;
  double time_limit = 1 / (2 * M_PI * R1 * C1);

  // Loop through time steps
  while (t < time_limit) {
    // Calculate voltage and print to console
    double v = voltage(t);
    printf("Time: %f s Voltage: %f V\n", t, v);
    // Increase time by time step
    t += dt;
  }

  return 0;
}