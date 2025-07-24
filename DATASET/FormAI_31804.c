//FormAI DATASET v1.0 Category: Physics simulation ; Style: real-life
#include <stdio.h>
#include <math.h>

// Constants
#define G 6.67430e-11 // gravitational constant
#define S 1.9885e30 // mass of the sun
#define M 5.97e24 // mass of the earth
#define R 6.378e6 // radius of the earth
#define AU 1.496e11 // astronomical unit
#define DT 86400 // time step (1 day)

int main() {
  // Variables
  double x = AU, y = 0; // initial position of the earth
  double vx = 0, vy = 29.29e3; // initial velocity of the earth
  double fx, fy; // forces on the earth
  double r; // distance between the earth and the sun
  double ax, ay; // acceleration of the earth

  // Simulation
  for (int t = 0; t < 365; t++) {
    // calculate distance between the earth and the sun
    r = sqrt(x*x + y*y);

    // calculate force on the earth
    fx = (-G * S * M * x) / (r*r*r);
    fy = (-G * S * M * y) / (r*r*r);

    // calculate acceleration of the earth
    ax = fx / M;
    ay = fy / M;

    // calculate new position and velocity of the earth
    x += vx * DT + 0.5 * ax * DT * DT;
    y += vy * DT + 0.5 * ay * DT * DT;
    vx += ax * DT;
    vy += ay * DT;

    // print the position of the earth
    printf("Day %d: (%.0f, %.0f)\n", t+1, x, y);
  }

  return 0;
}