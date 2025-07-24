//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>


// Defining all the variables that we will use in our simulation
double voltage_source_v;
double resistor_r;
double capacitor_c;
double time_step_t;
double end_time;
double current_i;
double current_time;

// Function that calculates the current in the circuit at a given time
double calculate_current() {
    double current = voltage_source_v / resistor_r * (1 - exp(-current_time/(resistor_r * capacitor_c)));
    return current;
}

// Function that simulates the circuit for a given time period and time step
void simulate_circuit() {
    printf("Time\tCurrent\n");

    while (current_time <= end_time) {
        current_i = calculate_current();
        printf("%f\t%f\n", current_time, current_i);
        current_time += time_step_t;
    }
}

// Main function that starts the simulation
int main() {

    // Initializing all the variables
    voltage_source_v = 10;
    resistor_r = 100;
    capacitor_c = 0.0001;
    time_step_t = 0.001;
    end_time = 0.1;
    current_i = 0;
    current_time = 0;

    // Running the simulation
    simulate_circuit();

    return 0;
}