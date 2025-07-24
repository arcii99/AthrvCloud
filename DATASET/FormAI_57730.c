//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Welcome to Happy Circuit Simulator!\n");
    printf("Let's create a circuit to generate some happy vibes!\n");

    // Declare variables and inputs for the circuit
    float input_voltage, resistor_value, capacitor_value, time_step;
    float current_voltage = 0.0, current_time = 0.0, previous_voltage = 0.0;
    int num_iterations;

    // Ask for user inputs
    printf("What is the input voltage? (Volts): ");
    scanf("%f", &input_voltage);

    printf("What is the resistor value? (Ohms): ");
    scanf("%f", &resistor_value);

    printf("What is the capacitor value? (Farads): ");
    scanf("%f", &capacitor_value);

    printf("What is the time step value? (Seconds): ");
    scanf("%f", &time_step);

    printf("How many iterations would you like to run?: ");
    scanf("%d", &num_iterations);

    // Compute output voltage for each iteration
    for(int i=0; i<num_iterations; i++) {
        current_voltage = input_voltage + (previous_voltage - input_voltage) * exp(-time_step/(resistor_value*capacitor_value));
        current_time += time_step;

        // Print current iteration results
        printf("Iteration %d: Time = %0.4f s, Voltage = %0.4f V\n", i+1, current_time, current_voltage);

        previous_voltage = current_voltage;
    }

    // Happy output message
    printf("\nGreat job, you made a happy circuit! Let's spread the joy!\n");

    return 0;
}