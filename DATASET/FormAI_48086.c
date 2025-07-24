//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: active
#include <stdio.h>
#include <math.h>

// circuit parameters
#define R1 100
#define R2 220
#define C1 1e-6
#define C2 2.2e-6
#define VIN 5

// simulation parameters
#define T_START 0
#define T_STOP 0.005
#define DELTA_T 0.00001

int main()
{
  // time and voltage variables
  double t, v1, v2, v_out;

  // initialize capacitor voltages to zero
  v1 = v2 = 0;

  // loop over time
  for (t = T_START; t <= T_STOP; t += DELTA_T)
  {
    // calculate input voltage
    double vin = VIN * sin(2 * M_PI * 100 * t);

    // calculate capacitor voltages
    v1 += (DELTA_T / (R1 * C1)) * (vin - v1);
    v2 += (DELTA_T / (R2 * C2)) * (v1 - v2);

    // calculate output voltage
    v_out = v2;

    // print output voltage to console
    printf("%.5f,%.5f\n", t, v_out);
  }

  return 0;
}