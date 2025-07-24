//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 6    // maximum number of nodes in the circuit
#define MAX_ELEMENTS 8 // maximum number of circuit elements

// structure to hold circuit information
typedef struct circuit_element{
    int type; // type of circuit element: 1 resistor, 2 capacitor, 3 inductor
    int n1;   // node 1
    int n2;   // node 2
    double value; // value of element in ohms, farads, or henries
} circuit_element;

// function to solve circuit and calculate node voltages
void solve_circuit(circuit_element elements[MAX_ELEMENTS], int num_elements, double node_voltages[MAX_NODES]){
    // initialize node voltages to 0
    int i = 0;
    for(i = 0; i < MAX_NODES; i++){
        node_voltages[i] = 0.0;
    }
    
    // loop through circuit elements and calculate node voltages
    for(i = 0; i < num_elements; i++){
        circuit_element e = elements[i];
        double v = 0.0;
        switch(e.type){
            case 1: // resistor
                v = (node_voltages[e.n1] - node_voltages[e.n2]) / e.value;
                break;
            case 2: // capacitor
                v = (node_voltages[e.n1] - node_voltages[e.n2]) * e.value;
                break;
            case 3: // inductor
                v = (node_voltages[e.n1] - node_voltages[e.n2]) / (2 * M_PI * e.value);
                break;
        }
        node_voltages[e.n1] -= v;
        node_voltages[e.n2] += v;
    }
}

int main(){
    // initialize circuit elements
    circuit_element elements[MAX_ELEMENTS];
    elements[0].type = 1; // resistor
    elements[0].n1 = 0;
    elements[0].n2 = 1;
    elements[0].value = 1000.0; // 1k ohm resistor
    elements[1].type = 2; // capacitor
    elements[1].n1 = 1;
    elements[1].n2 = 2;
    elements[1].value = 1e-6; // 1uF capacitor
    elements[2].type = 3; // inductor
    elements[2].n1 = 2;
    elements[2].n2 = 3;
    elements[2].value = 1e-3; // 1mH inductor
    
    // solve circuit and print node voltages
    double node_voltages[MAX_NODES];
    solve_circuit(elements, 3, node_voltages);
    int i = 0;
    for(i = 0; i < MAX_NODES; i++){
        printf("V%d: %f\n", i, node_voltages[i]);
    }
    
    return 0;
}