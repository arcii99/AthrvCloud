//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define the circuit parameters */
#define R1 500.0
#define R2 1000.0
#define C1 10e-9

/* Define the simulation parameters */
#define dt 1e-9
#define t_max 0.001

/* Declare functions to calculate voltage and current */
double calc_voltage(double current);
double calc_current(double voltage);

int main()
{
    /* Initialize variables */
    double voltage = 0; 
    double current = 0;
    double t = 0;

    /* Open output file for plotting result */
    FILE *output_file = fopen("output.dat", "w");

    /* Simulation loop */
    while (t <= t_max)
    {
        /* Calculate new voltage and current values */
        voltage = calc_voltage(current);
        current = calc_current(voltage);

        /* Print results to output file */
        fprintf(output_file, "%g %g\n", t, voltage);

        /* Increment time */
        t += dt;
    }

    /* Close output file */
    fclose(output_file);

    return 0;
}

/* Calculate voltage across capacitor using current */
double calc_voltage(double current)
{
    return (R1 * current) + (R2 * current * exp(-dt/(R2*C1)));
}

/* Calculate current flowing through capacitor using voltage */
double calc_current(double voltage)
{
    return (voltage - (R1*voltage)/(R1+R2)) / R2;
}