//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

/**********************************************************************
 *
 *      Class Name: Circuit
 *
 *      Description: Class to create and simulate a simple electrical
 *                   circuit with one voltage source and two resistors
 *                   in series.
 *
 *********************************************************************/

typedef struct circuit {
    float vsource;
    float r1;
    float r2;
} Circuit;

/******************************
 *
 *     Function Prototypes
 *
 *****************************/

void simulate_circuit(Circuit* circuit);
void print_circuit(Circuit* circuit);

/******************************
 *
 *        Main Function
 *
 ******************************/

int main() {
    Circuit circuit;
    circuit.vsource = 9.0;
    circuit.r1 = 1000.0;
    circuit.r2 = 1500.0;
    simulate_circuit(&circuit);
    print_circuit(&circuit);
    return 0;
}

/******************************
 *
 *    Simulate Circuit Function
 *
 ******************************/

void simulate_circuit(Circuit* circuit) {
    float curr;
    float v1;
    float v2;
    curr = circuit->vsource / (circuit->r1 + circuit->r2);
    v1 = curr * circuit->r1;
    v2 = curr * circuit->r2;
    circuit->vsource = v2;
    circuit->r1 = circuit->r1 + circuit->r2;
    circuit->r2 = 0.0;
}

/******************************
 *
 *      Print Circuit Function
 *
 ******************************/

void print_circuit(Circuit* circuit) {
    printf("Voltage Source: %.2f \n", circuit->vsource);
    printf("Resistor 1: %.2f \n", circuit->r1);
    printf("Resistor 2: %.2f \n", circuit->r2);
}