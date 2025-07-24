//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: genious
// This is a Classical Circuit Simulator program
// It simulates the functionality of a circuit containing
// resistors, capacitors and inductors.
#include<stdio.h>

// Define constants for component types
#define RESISTOR 0
#define CAPACITOR 1
#define INDUCTOR 2

// Define the circuit component structure
 typedef struct {
     int type; // Component Type (RESISTOR, CAPACITOR, or INDUCTOR)
     double value; // Component Value (in Ohms, Farads, or Henrys)
     double voltage; // Component Voltage
     double current; // Component Current
 } CircuitComponent;

// Function to calculate the current in a circuit component
 double getCurrent(CircuitComponent component, double voltage){
     if(component.type == RESISTOR){
         return voltage/component.value;
     } else if(component.type == CAPACITOR){
         return component.value*(voltage - component.voltage);
     } else if(component.type == INDUCTOR){
         return (voltage - component.voltage)/(component.value);
     }
     return 0; // Invalid component type
 }

int main() {
    CircuitComponent components[5]; // An array of 5 components
    double voltageSource = 12.0; // Voltage Source Value

    // Fill the component array
    components[0].type = RESISTOR;
    components[0].value = 100.0;

    components[1].type = INDUCTOR;
    components[1].value = 0.5;

    components[2].type = CAPACITOR;
    components[2].value = 0.0001;

    components[3].type = RESISTOR;
    components[3].value = 500.0;

    components[4].type = CAPACITOR;
    components[4].value = 0.0002;

    // Initialize voltages of all components to zero
    for(int i=0; i<5; i++){
        components[i].voltage = 0.0;
    }

    // Perform 50 time steps
    for(int i=0; i<50; i++){
        // Calculate the current in each component
        for(int j=0; j<5; j++){
            components[j].current = getCurrent(components[j], voltageSource);
        }

        // Update voltages of all capacitors and inductors
        for(int j=0; j<5; j++){
            if(components[j].type == CAPACITOR){
                components[j].voltage += components[j].current * components[j].value;
            } else if(components[j].type == INDUCTOR){
                components[j].voltage += components[j].current * components[j].value;
            }
        }

        // Output the current and voltages of all components
        printf("Time Step %d:\n", i+1);
        for(int j=0; j<5; j++){
            printf("Component %d - Current: %f A, Voltage: %f V\n", j+1, components[j].current, components[j].voltage);
        }
        printf("\n");
    }
    return 0; // Exit Program
}