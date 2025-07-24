//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define R 1000.0
#define C 1.0e-9
#define dt 1e-6

int main() {
    // Initialization
    double V_in = 5.0;  // Input voltage
    double V_out = 0.0;  // Output voltage
    double t = 0.0;  // Time
    double V_src = 0.0;  // Voltage at the input
    double V_cap_prev = 0.0;  // Voltage across capacitor at previous timestep
    double V_cap = 0.0;  // Voltage across capacitor

    // Simulation loop
    while (t < 0.01) {
        // Compute input voltage
        V_src = (t < 0.005) ? V_in : 0.0;

        // Compute voltage across capacitor
        V_cap = (C/dt)*(V_out - V_cap_prev) + V_cap_prev;

        // Compute output voltage
        V_out = R*C*(V_src/dt + V_cap);

        // Update previous voltage across capacitor
        V_cap_prev = V_cap;

        // Print results
        printf("t = %f s, V_in = %f V, V_out = %f V\n", t, V_src, V_out);

        // Increment time
        t += dt;
    }

    return 0;
}