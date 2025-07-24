//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: single-threaded
#include <stdio.h>
#include <math.h>

// Define initial circuit values
double R1 = 1000.0;
double R2 = 2200.0;
double C1 = 1e-6;
double C2 = 0.1e-6;
double Vin = 1.0;
double Vout = 0.0;

// Define simulation parameters
double dt = 1e-5;
double t = 0.0;
double Tmax = 1.0;

int main()
{
    // Open output file for writing
    FILE *output_file = fopen("circuit_output.txt", "w");

    // Simulate circuit
    while (t < Tmax)
    {
        // Calculate circuit parameters
        double R12 = R1 + R2;
        double C12 = (C1 * C2) / (C1 + C2);

        // Calculate input and output voltages
        double Vin_t = Vin * sin(2 * M_PI * t);
        double Vout_t = (R12 * C12 * Vin_t - Vout * (R12 * C12 + 1)) / (R12 * C12);

        // Write output voltage to file
        fprintf(output_file, "%.5lf %.5lf\n", t, Vout_t);

        // Store output voltage for next iteration
        Vout = Vout_t;

        // Increment simulation time
        t += dt;
    }

    // Close output file
    fclose(output_file);

    return 0;
}