//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define circuit parameters
#define R1 1000 // Resistor 1 value in ohms
#define R2 1500 // Resistor 2 value in ohms
#define C1 0.000001 // Capacitor 1 value in farads
#define VIN 5.0 // Input voltage in volts

// Define simulation parameters
#define T_STEP 0.0001 // time step for simulation in seconds
#define T_MAX 0.01 // maximum simulation time in seconds

int main() {
    
    double time = 0.0; // simulation time
    double vr1 = 0.0; // voltage across resistor 1
    double vr2 = 0.0; // voltage across resistor 2
    double vc1 = 0.0; // voltage across capacitor 1
    double ic1 = 0.0; // current through capacitor 1
    double vout = 0.0; // output voltage
    
    printf("Starting simulation...\n");
    
    // Run simulation
    while (time <= T_MAX) {
        
        // Calculate voltage across capacitor 1
        vc1 = (ic1 * T_STEP / C1) + vc1;
        
        // Calculate current through capacitor 1
        ic1 = ((VIN - vc1) / R1) * T_STEP + ic1;
        
        // Calculate voltage across resistor 1
        vr1 = ic1 * R1;
        
        // Calculate voltage across resistor 2
        vr2 = ((VIN - vc1) / R2) * R2;
        
        // Calculate output voltage
        vout = vr1 + vr2;
        
        // Print simulation results
        printf("Time: %.5f, Output Voltage: %.5f\n", time, vout);
        
        // Increment simulation time
        time = time + T_STEP;
    }
    
    printf("Simulation complete!\n");
    
    return 0;
}