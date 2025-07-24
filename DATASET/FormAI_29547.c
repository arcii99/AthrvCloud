//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <math.h>

#define MAX_NODES 25   // Maximum number of nodes in the circuit

int node_map[MAX_NODES];  // Array to map node names to numbering
double circuit_matrix[MAX_NODES][MAX_NODES + 1];   // Matrix to store circuit equations

void initialize_node_map() {
    // Initialize node map to -1
    for(int i = 0; i < MAX_NODES; ++i) {
        node_map[i] = -1;
    }
}

void add_node(char node_name) {
    // Check if node already exists in the map
    if(node_map[node_name - 'A'] == -1) {
        // Assign the next available node number
        for(int i = 0; i < MAX_NODES; ++i) {
            if(node_map[i] == -1) {
                node_map[i] = node_name - 'A';
                break;
            }
        }
    }
}

void add_equation(int node1, int node2, double value) {
    // Add the equation value to the corresponding element of the matrix
    circuit_matrix[node1][node2] += value;
}

void add_source(int node1, int node2, double value) {
    // Add the source value to the corresponding elements of the matrix
    circuit_matrix[node1][MAX_NODES] += value;
    circuit_matrix[node2][MAX_NODES] -= value;
}

void print_circuit_matrix(int num_nodes) {
    printf("\nCircuit Matrix:\n\n");
    for(int i = 0; i < num_nodes; ++i) {
        for(int j = 0; j < num_nodes + 1; ++j) {
            printf("%g\t", circuit_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int gauss_jordan(int num_nodes) {
    // Gauss-Jordan elimination to solve the circuit matrix
    for(int i = 0; i < num_nodes; i++) {
        // Pivot row
        int max = i;
        for(int j = i+1; j < num_nodes; j++) {
            if(fabs(circuit_matrix[j][i]) > fabs(circuit_matrix[max][i]))
                max = j;
        }
        for(int k = i; k < num_nodes + 1; k++) {
            double tmp = circuit_matrix[i][k];
            circuit_matrix[i][k] = circuit_matrix[max][k];
            circuit_matrix[max][k] = tmp;
        }

        // Eliminate lower triangular matrix
        for(int j = i+1; j < num_nodes; j++) {
            double factor = circuit_matrix[j][i]/circuit_matrix[i][i];
            for(int k = i; k < num_nodes + 1; k++) {
                circuit_matrix[j][k] -= factor*circuit_matrix[i][k];
            }
        }
    }
    // Back substitution to find values of variables
    for(int i = num_nodes-1; i >= 0; i--) {
        for(int j = i+1; j < num_nodes; j++) {
            circuit_matrix[i][num_nodes] -= circuit_matrix[i][j]*circuit_matrix[j][num_nodes];
        }
        circuit_matrix[i][num_nodes] /= circuit_matrix[i][i];
    }
    return 0;
}

void solve_circuit(int num_nodes) {
    // Solve the circuit and print the results
    gauss_jordan(num_nodes);
    printf("Solution:\n\n");
    for(int i = 0; i < num_nodes; ++i) {
        printf("Node %c: %gV\n", node_map[i] + 'A', circuit_matrix[i][num_nodes]);
    }
}

int main() {
    initialize_node_map();
    add_node('A');
    add_node('B');
    add_node('C');
    add_node('D');
    add_node('E');

    add_equation(0, 1, 1);
    add_equation(1, 2, 2);
    add_equation(1, 3, 1);
    add_equation(2, 3, 3);
    add_equation(3, 4, 4);

    add_source(0, 4, 10);

    print_circuit_matrix(5);
    solve_circuit(5);

    return 0;
}