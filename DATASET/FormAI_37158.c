//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

// Define our circuit structure
struct Circuit {
    int input1;
    int input2;
    int output;
};

// Define a function to simulate our circuit
void simulateCircuit(struct Circuit c) {
    if (c.input1 == 0 && c.input2 == 0) {
        c.output = 0;
    }
    else if (c.input1 == 0 && c.input2 == 1) {
        c.output = 0;
    }
    else if (c.input1 == 1 && c.input2 == 0) {
        c.output = 0;
    }
    else if (c.input1 == 1 && c.input2 == 1) {
        c.output = 1;
    }
    
    printf("Simulating Circuit...\n");
    printf("Input 1: %d\n", c.input1);
    printf("Input 2: %d\n", c.input2);
    printf("Output: %d\n", c.output);
}

int main() {
    struct Circuit myCircuit;
    
    // Set our inputs
    myCircuit.input1 = 0;
    myCircuit.input2 = 0;
    
    // Simulate the circuit and print the result
    simulateCircuit(myCircuit);
    
    // Update the inputs and simulate again
    myCircuit.input1 = 0;
    myCircuit.input2 = 1;
    simulateCircuit(myCircuit);
    
    // Update the inputs again and simulate a final time
    myCircuit.input1 = 1;
    myCircuit.input2 = 1;
    simulateCircuit(myCircuit);
    
    return 0;
}