//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the circuit parameters
#define R1 1000
#define R2 2000
#define C1 0.000001
#define V1 5

int main()
{
    // Define the simulation parameters
    double tstep = 0.0001;
    double tmax = 0.01;
    int nsteps = (int)(tmax / tstep);

    // Initialize the circuit variables
    double vout = 0;
    double vin = 0;
    double iin = 0;
    double iout = 0;
    double t = 0;

    // Create the data file for output
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("Error: Cannot open file for writing.\n");
        exit(EXIT_FAILURE);
    }

    // Run the simulation
    for (int i = 0; i <= nsteps; ++i) {
        // Calculate the input voltage and current
        vin = V1;
        iin = vin / R1;

        // Calculate the output voltage and current
        iout = (vout - vin) / R2;
        vout += tstep * (iin - iout) / C1;

        // Update the time
        t += tstep;

        // Write the data to file
        fprintf(fp, "%.6f %.6f %.6f\n", t, vin, vout);
    }

    // Close the data file
    fclose(fp);

    return 0;
}