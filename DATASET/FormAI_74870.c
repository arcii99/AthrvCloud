//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100 // maximum number of nodes in the circuit

int numNodes = 0; // number of nodes in the circuit
double values[MAX_NODES]; // array to store node values

// define the NodeType struct which stores information about each node
typedef struct
{
    char name[10]; // name of the node (e.g. V1, R2, etc.)
    int node1; // index of the first connected node
    int node2; // index of the second connected node
    double value; // value of the component (e.g. resistance, voltage, etc.)
} NodeType;

// initialize the circuit with default values
NodeType circuit[MAX_NODES] = {
    {"V1", 0, 1, 10}, // voltage source between nodes 1 and 0 with a value of 10V
    {"R1", 0, 2, 1000}, // resistor between nodes 0 and 2 with a value of 1000 ohms
    {"R2", 1, 2, 500}, // resistor between nodes 1 and 2 with a value of 500 ohms
    {"R3", 2, 3, 2000}, // resistor between nodes 2 and 3 with a value of 2000 ohms
    {"R4", 2, 4, 1000} // resistor between nodes 2 and 4 with a value of 1000 ohms
};

// function to simulate the circuit and calculate voltages at each node
void simulateCircuit()
{
    int i, iter;
    double current[MAX_NODES]; // array to store current values
    double convergence = 0.001; // convergence criteria for simulation
    double error = 10; // error value used for iterative approach
    double maxError;

    // run 100 iterations or until convergence criteria is met
    for (iter = 0; iter < 100 && error > convergence; iter++)
    {
        maxError = 0; // reset maxError value for each iteration

        // calculate current values for each component
        for (i = 0; i < numNodes; i++)
        {
            if (circuit[i].name[0] == 'R')
            {
                current[i] = (values[circuit[i].node1] - values[circuit[i].node2]) / circuit[i].value;
            }
            else if (circuit[i].name[0] == 'V')
            {
                current[i] = circuit[i].value;
            }
        }

        // calculate new voltage values for each node
        for (i = 0; i < numNodes; i++)
        {
            if (i == 0)
            {
                // set initial value for ground node to 0
                values[i] = 0;
            }
            else
            {
                // calculate new voltage value using Kirchoff's Current Law
                values[i] = (current[i-1] + current[i]) / circuit[i].value;

                // calculate error and check for convergence
                if (abs(values[i] - values[i-1]) > maxError)
                {
                    maxError = abs(values[i] - values[i-1]);
                }
            }
        }

        // update error value
        error = maxError;
    }
}

int main(void)
{
    int i;

    // initialize values array with default values
    for (i = 0; i < numNodes; i++)
    {
        values[i] = 0;
    }

    // set number of nodes in circuit to default value
    numNodes = 5;

    // simulate the circuit and calculate voltages at each node
    simulateCircuit();

    // print out the final voltage values at each node
    for (i = 0; i < numNodes; i++)
    {
        printf("Node %d: %.2lfV\n", i, values[i]);
    }

    return 0;
}