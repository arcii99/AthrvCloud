//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define constants
#define MAX_NODES 1000
#define MAX_VALUES 100000
#define MAX_LINE_LENGTH 50

// Define variables
int num_nodes, num_resistors, num_capacitors, num_inductors, num_sources, num_values;
int nodes[MAX_NODES], resistor_nodes[2][MAX_NODES], capacitor_nodes[2][MAX_NODES], inductor_nodes[2][MAX_NODES], source_nodes[2][MAX_NODES];
int resistor_values[MAX_NODES], capacitor_values[MAX_NODES], inductor_values[MAX_NODES], source_values[MAX_NODES];
double G[MAX_NODES][MAX_NODES], B[MAX_NODES][MAX_NODES], C[MAX_NODES][MAX_NODES], y[MAX_NODES], x[MAX_NODES];
char line[MAX_LINE_LENGTH];
FILE *input_file, *output_file;

// Define functions
void parse_line(char* input_line);
void initialize_matrices();
void apply_dc_source(int node1, int node2, double value);
void apply_resistor(int node1, int node2, int value);
void apply_capacitor(int node1, int node2, int value);
void apply_inductor(int node1, int node2, int value);
void solve_matrices();
void print_results();

// main function
int main(int argc, char const *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: ./sim input_file output_file\n");
        return 1;
    }

    // Open input file
    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file
    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Parse input file line by line
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        parse_line(line);
    }

    // Initialize matrices
    initialize_matrices();

    // Solve matrices
    solve_matrices();

    // Print results to output file
    print_results();

    // Close files
    fclose(input_file);
    fclose(output_file);

    return 0;
}

// Parse line function
void parse_line(char* input_line) {
    // Get first character of line
    char first_char = input_line[0];

    // Parse based on first character
    switch(first_char) {
        case 'D':
            // DC source
            sscanf(input_line, "DC %d %d %d", &source_nodes[0][num_sources], &source_nodes[1][num_sources], &source_values[num_sources]);
            num_sources++;
            break;
        case 'R':
            // Resistor
            sscanf(input_line, "R %d %d %d", &resistor_nodes[0][num_resistors], &resistor_nodes[1][num_resistors], &resistor_values[num_resistors]);
            num_resistors++;
            break;
        case 'C':
            // Capacitor
            sscanf(input_line, "C %d %d %d", &capacitor_nodes[0][num_capacitors], &capacitor_nodes[1][num_capacitors], &capacitor_values[num_capacitors]);
            num_capacitors++;
            break;
        case 'L':
            // Inductor
            sscanf(input_line, "L %d %d %d", &inductor_nodes[0][num_inductors], &inductor_nodes[1][num_inductors], &inductor_values[num_inductors]);
            num_inductors++;
            break;
    }
}

// Initialize matrices function
void initialize_matrices() {
    // Set all values to zero
    memset(G, 0, sizeof(G));
    memset(B, 0, sizeof(B));
    memset(C, 0, sizeof(C));
    memset(y, 0, sizeof(y));
    memset(x, 0, sizeof(x));

    // Set diagonal elements of C and G matrices to 1
    for (int i = 0; i < num_nodes; i++) {
        C[i][i] = 1;
        G[i][i] = 1;
    }

    // Traverse through resistors
    for (int i = 0; i < num_resistors; i++) {
        int node1 = resistor_nodes[0][i];
        int node2 = resistor_nodes[1][i];
        int value = resistor_values[i];

        apply_resistor(node1, node2, value);
    }

    // Traverse through capacitors
    for (int i = 0; i < num_capacitors; i++) {
        int node1 = capacitor_nodes[0][i];
        int node2 = capacitor_nodes[1][i];
        int value = capacitor_values[i];

        apply_capacitor(node1, node2, value);
    }

    // Traverse through inductors
    for (int i = 0; i < num_inductors; i++) {
        int node1 = inductor_nodes[0][i];
        int node2 = inductor_nodes[1][i];
        int value = inductor_values[i];

        apply_inductor(node1, node2, value);
    }

    // Traverse through DC sources
    for (int i = 0; i < num_sources; i++) {
        int node1 = source_nodes[0][i];
        int node2 = source_nodes[1][i];
        double value = source_values[i];

        apply_dc_source(node1, node2, value);
    }
}

// Apply DC source function
void apply_dc_source(int node1, int node2, double value) {
    int index1 = node1-1;
    int index2 = node2-1;

    // Set row entry for node 1
    G[index1][num_nodes] = 1;
    G[num_nodes][index1] = 1;

    // Set row entry for node 2
    G[index2][num_nodes] = -1;
    G[num_nodes][index2] = -1;

    // Set value for y matrix
    y[num_nodes] = value;
}

// Apply resistor function
void apply_resistor(int node1, int node2, int value) {
    int index1 = node1-1;
    int index2 = node2-1;

    // Set row entry for node 1
    G[index1][index1] += 1.0/value;
    G[index1][index2] -= 1.0/value;

    // Set row entry for node 2
    G[index2][index2] += 1.0/value;
    G[index2][index1] -= 1.0/value;
}

// Apply capacitor function
void apply_capacitor(int node1, int node2, int value) {
    int index1 = node1-1;
    int index2 = node2-1;

    // Set row entry for node 1
    C[index1][index1] += 1.0/value;
    C[index1][index2] -= 1.0/value;

    // Set row entry for node 2
    C[index2][index2] += 1.0/value;
    C[index2][index1] -= 1.0/value;
}

// Apply inductor function
void apply_inductor(int node1, int node2, int value) {
    int index1 = node1-1;
    int index2 = node2-1;

    // Set row entry for node 1
    B[index1][index1] += 1.0/value;
    B[index1][index2] -= 1.0/value;

    // Set row entry for node 2
    B[index2][index2] += 1.0/value;
    B[index2][index1] -= 1.0/value;
}

// Solve matrices function
void solve_matrices() {
    // Find inverse of C and B matrices
    double invC[MAX_NODES][MAX_NODES], invB[MAX_NODES][MAX_NODES];
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            invC[i][j] = C[j][i]; // transpose
            invB[i][j] = B[j][i]; // transpose
        }
    }
    double detC = invC[0][0]*invC[1][1] - invC[0][1]*invC[1][0];
    double detB = invB[0][0]*invB[1][1] - invB[0][1]*invB[1][0];
    double inv_detC = 1.0/detC;
    double inv_detB = 1.0/detB;
    double invCB[MAX_NODES][MAX_NODES];
    invCB[0][0] = inv_detC*invB[1][1];
    invCB[0][1] = -inv_detC*invB[0][1];
    invCB[1][0] = -inv_detC*invB[1][0];
    invCB[1][1] = inv_detC*invB[0][0];

    // Find product of matrices GC^-1B^-1G^T
    double product1[MAX_NODES][MAX_NODES], product2[MAX_NODES][MAX_NODES], product3[MAX_NODES][MAX_NODES];
    memset(product1, 0, sizeof(product1));
    memset(product2, 0, sizeof(product2));
    memset(product3, 0, sizeof(product3));
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            for (int k = 0; k < num_nodes; k++) {
                product1[i][j] += G[i][k]*invCB[k][j];
            }
        }
    }
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            for (int k = 0; k < num_nodes; k++) {
                product2[i][j] += invB[i][k]*product1[k][j];
            }
        }
    }
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            for (int k = 0; k < num_nodes; k++) {
                product3[i][j] += product2[i][k]*G[j][k];
            }
        }
    }

    // Find inverse of product of matrices
    double det = product3[0][0]*product3[1][1] - product3[0][1]*product3[1][0];
    double inv_det = 1.0/det;
    double invProduct[MAX_NODES][MAX_NODES];
    invProduct[0][0] = inv_det*product3[1][1];
    invProduct[0][1] = -inv_det*product3[0][1];
    invProduct[1][0] = -inv_det*product3[1][0];
    invProduct[1][1] = inv_det*product3[0][0];

    // Find product of CG^-1B^-1
    double product4[MAX_NODES][MAX_NODES], product5[MAX_NODES][MAX_NODES];
    memset(product4, 0, sizeof(product4));
    memset(product5, 0, sizeof(product5));
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            for (int k = 0; k < num_nodes; k++) {
                product4[i][j] += C[i][k]*invCB[k][j];
            }
        }
    }
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            for (int k = 0; k < num_nodes; k++) {
                product5[i][j] += product4[i][k]*G[j][k];
            }
        }
    }

    // Find product of inverse product with y vector
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            x[i] += invProduct[i][j]*y[j];
        }
    }
}

// Print results function
void print_results() {
    // Print voltages to output file
    fprintf(output_file, "Voltages:\n");
    for (int i = 0; i < num_nodes-1; i++) {
        fprintf(output_file, "V%d = %lf\n", i+1, x[i]);
    }

    // Print currents to output file
    fprintf(output_file, "Currents:\n");
    for (int i = 0; i < num_resistors; i++) {
        int node1 = resistor_nodes[0][i];
        int node2 = resistor_nodes[1][i];
        double current = (x[node1-1] - x[node2-1])/resistor_values[i];
        fprintf(output_file, "I%d = %lf\n", i+1, current);
    }
}