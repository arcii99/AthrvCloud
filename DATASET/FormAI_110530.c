//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: minimalist
#include<stdio.h>
#include<math.h>

#define CYCLES         1000
#define N              3      // Number of resistors

// Function to calculate voltage across each resistor in the circuit
void simulate(double volt[N], double res[N], double time[N], double output[])
{
    for(int i=0; i<CYCLES; i++)
    {
        double total_voltage = 0.0;
        for(int j=0; j<N; j++)
            total_voltage += volt[j] * sin(2*M_PI*time[j]*i);

        for(int j=0; j<N; j++)
            output[i] += (total_voltage * res[j] * sin(2*M_PI*time[j]*i));
    }
}

int main()
{
    // Initialise the circuit values
    double volt[N] = { 1.0, 2.0, 3.0 };
    double res[N] = { 50.0, 100.0, 150.0 };
    double time[N] = { 0.5, 1.0, 1.5 };
    double output[CYCLES] = { 0.0 };

    // Simulate the circuit
    simulate(volt, res, time, output);

    // Print the output
    for(int i=0; i<CYCLES; i++)
        printf("Output %d: %f\n", i, output[i]);

    return 0;
}