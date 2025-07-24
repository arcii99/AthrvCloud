//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TIME_STEP 0.001       // Time step of 1 ms
#define SIM_TIME 1.0          // Simulation time of 1s
#define R1 4700               // Resistor 1 value
#define R2 3300               // Resistor 2 value
#define C 10e-6               // Capacitor value

double voltage(double t);     // Function to calculate the voltage

int main()
{
    double time = 0.0;        // Current time
    double v_in, v_out, i_c;

    v_out = 0.0;              // Initialize output voltage to 0

    // Loop through time steps
    for (int i = 0; i < (int)(SIM_TIME / TIME_STEP); i++)
    {
        v_in = voltage(time);                         // Get input voltage at current time
        i_c = C * (v_out / R2);                        // Calculate current through capacitor
        v_out += TIME_STEP * i_c / C - v_out / (R1 * C);    // Update output voltage

        printf("Time = %f s, Input Voltage = %f V, Output Voltage = %f V\n", time, v_in, v_out);    // Print results

        time += TIME_STEP;                            // Increment time
    }

    return 0;
}

double voltage(double t)
{
    // Square wave with frequency of 100 Hz and amplitude of 5V
    return 5.0 * (int)(10.0 * sin(2.0 * M_PI * 100.0 * t)) / 10.0;
}