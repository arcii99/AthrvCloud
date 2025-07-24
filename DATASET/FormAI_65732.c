//FormAI DATASET v1.0 Category: Computer Biology ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5            // Number of cells
#define T 10           // Time period of simulation
#define DELTA_T 0.01   // Time step size
#define K_1 0.01       // Kinetic constant 1
#define K_2 0.02       // Kinetic constant 2
#define K_3 0.005      // Kinetic constant 3

void main()
{
  double time = 0.0;              // Current time
  double x[N], y[N], z[N];        // Cell arrays
  double dxdt[N], dydt[N], dzdt[N];// Rate of change of concentration arrays
  int i, j;                       // Loop counters
  
  // Initialize x, y, and z arrays
  for (i = 0; i < N; i++) {
    x[i] = 1.0;
    y[i] = 0.0;
    z[i] = 0.0;
  }

  // Start simulation
  for (time = 0; time <= T; time += DELTA_T) {
    
    // Calculate dx/dt, dy/dt, and dz/dt for each cell
    for (i = 0; i < N; i++) {
      dxdt[i] = -K_1 * x[i] + K_2 * y[i] * z[i];
      dydt[i] = K_1 * x[i] - K_2 * y[i] * z[i] - K_3 * y[i];
      dzdt[i] = K_3 * y[i] - K_2 * y[i] * z[i];
    }
    
    // Update concentrations for each cell
    for (i = 0; i < N; i++) {
      x[i] = x[i] + dxdt[i] * DELTA_T;
      y[i] = y[i] + dydt[i] * DELTA_T;
      z[i] = z[i] + dzdt[i] * DELTA_T;
      printf("Cell %d - X: %f Y: %f Z: %f\n", i+1, x[i], y[i], z[i]);
    }
  }
}