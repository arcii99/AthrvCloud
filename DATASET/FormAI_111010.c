//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// An apocalyptic style classical circuit simulator.

#define MAX_CIRCUIT_SIZE 1000

int circuit_size;
int connection[MAX_CIRCUIT_SIZE][MAX_CIRCUIT_SIZE];
double resistance[MAX_CIRCUIT_SIZE];
double voltage[MAX_CIRCUIT_SIZE];
double current[MAX_CIRCUIT_SIZE];

void simulate() {
    // First find the voltage of every node in the circuit using Kirchhoff's voltage law.
    for(int i=0; i<circuit_size; i++) {
        double sum = 0.0;
        for(int j=0; j<circuit_size; j++) {
            if(connection[i][j] == 1) {
                sum += current[i] * resistance[i];
            } else if(connection[j][i] == 1) {
                sum -= current[j] * resistance[j];
            }
        }
        voltage[i] = sum;
    }
    
    // Now find the current through each resistor using Ohm's law. 
    for(int i=0; i<circuit_size; i++) {
        current[i] = voltage[i] / resistance[i];
    }
    
    // Print the results.
    printf("Circuit simulation results:\n");
    for(int i=0; i<circuit_size; i++) {
        printf("Node %d: Voltage=%f, Current=%f\n", i, voltage[i], current[i]);
    }
}

int main() {
    // Build the circuit.
    circuit_size = 3;
    resistance[0] = 1.0;
    resistance[1] = 2.0;
    resistance[2] = 3.0;
    connection[0][1] = 1;
    connection[1][2] = 1;
    connection[2][0] = 1;
    voltage[0] = 5.0;
    
    printf("Starting circuit simulation...\n");
    simulate();
    printf("Simulation complete.\n");
    
    return 0;
}