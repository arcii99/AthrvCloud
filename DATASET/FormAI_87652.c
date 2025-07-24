//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Define global constants */
#define VCC 5.0    /* Supply voltage in volts */
#define R1 1000.0  /* Resistance in ohms */
#define R2 1000.0  /* Resistance in ohms */
#define C1 1e-6    /* Capacitance in farads */
#define C2 1e-6    /* Capacitance in farads */
#define PI 3.14159 /* Value of pi */

/* Define function prototype for AC analysis */
void ac_analysis(double f);

/* Define main function */
int main()
{
    double f; /* Frequency in hertz */

    /* Get user input for frequency */
    printf("Enter frequency in hertz: ");
    scanf("%lf", &f);

    /* Check if frequency is within range */
    if (f <= 0 || f > 1e8)
    {
        printf("Invalid frequency. Enter a frequency between 1 and 100 million hertz.\n");
        return 1;
    }

    /* Print simulation parameters */
    printf("Simulation Parameters:\n");
    printf("Supply Voltage: %0.2lf volts\n", VCC);
    printf("R1: %0.0lf ohms | R2: %0.0lf ohms\n", R1, R2);
    printf("C1: %0.2e farads | C2: %0.2e farads\n", C1, C2);
    printf("Frequency: %0.2lf hertz\n\n", f);

    /* Perform AC analysis */
    ac_analysis(f);

    return 0;
}

/* Define function for AC analysis */
void ac_analysis(double f)
{
    double Vin, Vout; /* Input and output voltages */
    double gain;      /* Gain of the amplifier */
    double phase;     /* Phase shift of the amplifier */
    double impedance; /* Total impedance of the circuit */
    double omega;     /* Angular frequency */

    /* Calculate omega */
    omega = 2 * PI * f;

    /* Calculate total impedance */
    impedance = sqrt(pow(R1 + R2, 2) + pow(omega * (R1 * R2 * C1 * C2), 2));

    /* Calculate gain */
    gain = -R2 / R1 * (1 / impedance);

    /* Calculate phase shift */
    phase = -1 * atan(omega * R1 * R2 * C1 * C2 / (R1 + R2));

    /* Calculate input and output voltages */
    Vin = VCC / sqrt(2);
    Vout = gain * Vin;

    /* Print AC analysis results */
    printf("AC Analysis Results:\n");
    printf("Input Voltage: %0.2lf volts RMS\n", Vin);
    printf("Output Voltage: %0.2lf volts RMS\n", Vout);
    printf("Gain: %0.2lf dB | Phase Shift: %0.2lf degrees\n", 20 * log10(gain), phase * 180 / PI);
    printf("Total Impedance: %0.2lf ohms\n", impedance);
}