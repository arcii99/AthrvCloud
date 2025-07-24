//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100        // maximum number of nodes in the circuit
#define MAX_RESISTORS 200    // maximum number of resistors in the circuit

// structure to hold information about each node in the circuit
typedef struct node {
    int node_num;            // node number
    int num_resistors;       // number of resistors connected to the node
    double voltage;          // node voltage
    int connected_resistors[MAX_RESISTORS];    // list of resistors connected to the node
} Node;

// structure to hold information about each resistor in the circuit
typedef struct resistor {
    int resistor_num;       // resistor number
    double resistance;      // resistance value
    int node1;              // first node to which the resistor is connected
    int node2;              // second node to which the resistor is connected
} Resistor;

// function to simulate the circuit and calculate voltages at all the nodes
void simulate_circuit(Node *nodes, Resistor *resistors, int num_nodes, int num_resistors)
{
    double convergence_threshold = pow(10,-6);    // convergence threshold for the simulation
    int iterations = 0;     // number of iterations taken for convergence
    int max_iterations = 100;   // maximum number of iterations allowed
    
    while (1) {   // keep iterating until convergence or max iterations reached
        double max_error = 0;   // maximum error in node voltages in the current iteration
        
        // iterate over all the nodes and calculate new voltages based on connected resistors
        for (int i = 0; i < num_nodes; i++) {
            double new_voltage = 0;
            for (int j = 0; j < nodes[i].num_resistors; j++) {
                int resistor_num = nodes[i].connected_resistors[j];
                Resistor r = resistors[resistor_num];
                if (r.node1 == i) {
                    new_voltage += nodes[r.node2].voltage / r.resistance;
                } else {
                    new_voltage += nodes[r.node1].voltage / r.resistance;
                }
            }
            new_voltage = 1 / new_voltage;   // calculate the new voltage for the node
            
            double error = fabs(nodes[i].voltage - new_voltage);   // calculate the error in voltage
            if (error > max_error) {
                max_error = error;    // update maximum error if necessary
            }
            
            nodes[i].voltage = new_voltage;   // update the node voltage
        }
        
        iterations++;   // increment the iteration counter
        
        // check if convergence has been achieved
        if (max_error < convergence_threshold) {
            printf("Circuit simulation successful in %d iterations.\n", iterations);
            break;
        }
        
        // check if maximum iterations have been reached
        if (iterations >= max_iterations) {
            printf("Maximum number of iterations reached.\n");
            break;
        }
    }
}

int main()
{
    Node nodes[MAX_NODES];
    Resistor resistors[MAX_RESISTORS];
    
    // define the circuit topology with nodes and resistors
    int num_nodes = 4;
    int num_resistors = 3;
    nodes[0].node_num = 0;
    nodes[0].num_resistors = 2;
    nodes[0].connected_resistors[0] = 0;
    nodes[0].connected_resistors[1] = 1;
    nodes[1].node_num = 1;
    nodes[1].num_resistors = 2;
    nodes[1].connected_resistors[0] = 0;
    nodes[1].connected_resistors[1] = 2;
    nodes[2].node_num = 2;
    nodes[2].num_resistors = 2;
    nodes[2].connected_resistors[0] = 2;
    nodes[2].connected_resistors[1] = 1;
    nodes[3].node_num = 3;
    nodes[3].num_resistors = 1;
    nodes[3].connected_resistors[0] = 0;
    resistors[0].resistor_num = 0;
    resistors[0].resistance = 1000;
    resistors[0].node1 = 0;
    resistors[0].node2 = 3;
    resistors[1].resistor_num = 1;
    resistors[1].resistance = 500;
    resistors[1].node1 = 1;
    resistors[1].node2 = 0;
    resistors[2].resistor_num = 2;
    resistors[2].resistance = 2000;
    resistors[2].node1 = 2;
    resistors[2].node2 = 1;
    
    // initialize the node voltages to 0
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].voltage = 0;
    }
    
    // simulate the circuit
    simulate_circuit(nodes, resistors, num_nodes, num_resistors);
    
    // print the results
    printf("Node voltages:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: %f\n", nodes[i].node_num, nodes[i].voltage);
    }
    
    return 0;   // program terminated successfully
}