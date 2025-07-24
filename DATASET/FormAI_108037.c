//FormAI DATASET v1.0 Category: Physics simulation ; Style: careful
#include <stdio.h>
#include <math.h>

int main()
{
  // Define variables
  double m = 0.1;  // Mass of the object in kg
  double k = 2.0;  // Spring constant in N/m
  double x = 0.1;  // Initial displacement in meters
  double v = 0.0;  // Initial velocity in m/s
  double dt = 0.01;  // Time step in seconds
  double t = 0.0;  // Time in seconds
  double a = 0.0;  // Acceleration in m/s^2
  double F_spring = 0.0;  // Spring force in N
  double F_damping = 0.0;  // Damping force in N

  // Open file for data output
  FILE *outfile;
  outfile = fopen("spring_data.txt", "w");

  // Loop over time steps
  while (t < 10.0)
  {
    // Compute spring force and damping force
    F_spring = -k * x;
    F_damping = -0.5 * v;

    // Compute acceleration
    a = (F_spring + F_damping) / m;

    // Compute new position and velocity using Euler's method
    x = x + v * dt;
    v = v + a * dt;

    // Write data to file
    fprintf(outfile, "%lf\t%lf\t%lf\n", t, x, v);

    // Update time
    t = t + dt;
  }

  // Close file
  fclose(outfile);

  return 0;
}