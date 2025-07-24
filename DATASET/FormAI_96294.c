//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: ultraprecise
#include<stdio.h>
#include<stdbool.h>

// Define a structure to represent a single node in the circuit
struct Node {
    int id;
    bool value;
};

// Define a function to simulate the circuit given an input vector
bool simulate_circuit(struct Node circuit[], int num_nodes, int input_vector[]) {
    // Set the initial values of the input nodes
    for (int i=0; i<num_nodes; i++) {
        if (circuit[i].id < 0) {
            circuit[i].value = input_vector[-circuit[i].id - 1];
        }
    }
    
    // Simulate the circuit using a while loop
    bool circuit_changed = true;
    while (circuit_changed) {
        circuit_changed = false;
        for (int i=0; i<num_nodes; i++) {
            if (circuit[i].id >= 0) {  // if this node is not an input node
                bool new_value = false;
                switch (circuit[i].id) {
                    case 0:  // AND gate
                        new_value = true;
                        for (int j=0; j<num_nodes; j++) {
                            if (circuit[j].id < 0 && -circuit[j].id-1 == i && circuit[j].value == false) {
                                new_value = false;
                                break;
                            } else if (circuit[j].id > 0 && circuit[j].value == false) {
                                new_value = false;
                                break;
                            }
                        }
                        break;
                    case 1:  // OR gate
                        new_value = false;
                        for (int j=0; j<num_nodes; j++) {
                            if (circuit[j].id < 0 && -circuit[j].id-1 == i && circuit[j].value == true) {
                                new_value = true;
                                break;
                            } else if (circuit[j].id > 0 && circuit[j].value == true) {
                                new_value = true;
                                break;
                            }
                        }
                        break;
                    case 2:  // NOT gate
                        new_value = !circuit[circuit[i].value].value;
                        break;
                }
                if (circuit[i].value != new_value) {
                    circuit[i].value = new_value;
                    circuit_changed = true;
                }
            }
        }
    }
    
    // Return the value of the output node
    int output_node_index = -1;
    for (int i=0; i<num_nodes; i++) {
        if (circuit[i].id == num_nodes) {
            output_node_index = i;
            break;
        }
    }
    return circuit[output_node_index].value;
}

int main() {
    // Define the circuit as an array of nodes
    struct Node circuit[] = {{-1, false}, {-1, false}, {-1, false}, {0, false}, {1, false}, {2, 3}};
    
    // Define the input vector
    int input_vector[] = {1, 1, 0};
    
    // Simulate the circuit and print the output
    bool output = simulate_circuit(circuit, 6, input_vector);
    printf("Output: %d\n", output);
    
    return 0;
}