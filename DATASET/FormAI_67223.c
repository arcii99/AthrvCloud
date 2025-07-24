//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Donald Knuth
/* This program simulates a simple RC circuit and outputs the voltage across the resistor at each time step.
   The user can specify the values of resistance (R), capacitance (C), and the input voltage (Vin).
   The program uses Euler's method to solve the differential equation.
*/

#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define DT 0.001 // time step
#define SIM_TIME 0.1 // simulation time
#define STEPS (int) (SIM_TIME / DT) // number of time steps

int main() {
    double R, C, Vin; // user input parameters
    double time[STEPS], Vout[STEPS]; // array to store time and voltage values
    double v_c = 0; // initial voltage across capacitor
    
    // get user input
    printf("Enter resistance value (ohms): ");
    scanf("%lf", &R);
    printf("Enter capacitance value (farads): ");
    scanf("%lf", &C);
    printf("Enter input voltage (volts): ");
    scanf("%lf", &Vin);
    
    // simulation loop
    for (int i=0; i<STEPS; i++) {
        time[i] = i * DT; // store time value
        Vout[i] = Vin - v_c; // calculate voltage across resistor
        v_c += DT / (R * C) * (Vin - v_c); // update voltage across capacitor using Euler's method
    }
    
    // output results
    printf("Time (s)\tVout (V)\n");
    for (int i=0; i<STEPS; i++) {
        printf("%.3f\t\t%.3f\n", time[i], Vout[i]);
    }
    
    return 0;
}