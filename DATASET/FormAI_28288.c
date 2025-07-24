//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

/* Function to perform complex multiplication */
void complex_multiply(double complex a, double complex b, double complex *result){
    double real_a = creal(a);
    double imag_a = cimag(a);
    double real_b = creal(b);
    double imag_b = cimag(b);
    double real_result = (real_a * real_b) - (imag_a * imag_b);
    double imag_result = (real_a * imag_b) + (real_b * imag_a);
    *result = real_result + (imag_result * I);
}

/* Function to perform complex addition */
void complex_add(double complex a, double complex b, double complex *result){
    double real_a = creal(a);
    double imag_a = cimag(a);
    double real_b = creal(b);
    double imag_b = cimag(b);
    *result = (real_a + real_b) + ((imag_a + imag_b) * I);
}

/* Function to perform resistor behavior */
void resistor(double complex g_matrix[], int node1, int node2, double resistance){
    int num_nodes = sqrt(sizeof(g_matrix)/sizeof(g_matrix[0]));
    g_matrix[node1*num_nodes + node1] += 1/resistance;
    g_matrix[node2*num_nodes + node2] += 1/resistance;
    g_matrix[node1*num_nodes + node2] -= 1/resistance;
    g_matrix[node2*num_nodes + node1] -= 1/resistance;
}

/* Function to perform capacitor behavior */
void capacitor(double complex g_matrix[], double complex c_matrix[], int node1, int node2, double capacitance, double timestep){
    int num_nodes = sqrt(sizeof(g_matrix)/sizeof(g_matrix[0]));
    double complex cap_matrix[num_nodes*num_nodes];
    for(int i = 0; i < num_nodes*num_nodes; i++){
        cap_matrix[i] = 0 + 0*I;
    }
    cap_matrix[node1*num_nodes + node1] += capacitance;
    cap_matrix[node2*num_nodes + node2] += capacitance;
    cap_matrix[node1*num_nodes + node2] -= capacitance;
    cap_matrix[node2*num_nodes + node1] -= capacitance;
    complex_multiply(cap_matrix[0], 1/(timestep*capacitance), &cap_matrix[0]);
    for(int i = 1; i < num_nodes*num_nodes; i++){
        complex_multiply(cap_matrix[i], 1/(timestep*capacitance), &cap_matrix[i]);
        complex_add(cap_matrix[i], c_matrix[i], &c_matrix[i]);
    }
    for(int i = 0; i < num_nodes*num_nodes; i++){
        complex_add(g_matrix[i], cap_matrix[i], &g_matrix[i]);
    }
}

/* Function to perform voltage source behavior */
void voltage_source(double complex g_matrix[], double complex b_matrix[], int node1, int node2, double voltage){
    int num_nodes = sqrt(sizeof(g_matrix)/sizeof(g_matrix[0]));
    b_matrix[num_nodes + node1] += voltage;
    b_matrix[num_nodes + node2] -= voltage;
}

int main(){
    /* Initialize variables */
    int num_nodes = 3; // Number of nodes in circuit
    double complex g_matrix[num_nodes*num_nodes]; // Conductance matrix
    double complex c_matrix[num_nodes*num_nodes]; // Capacitance matrix
    double complex b_matrix[num_nodes+1]; // Voltage/current source matrix
    double voltage = 5.0; // Voltage of voltage source
    double resistance = 1000.0; // Resistance of resistor
    double capacitance = 1.0e-6; // Capacitance of capacitor
    double timestep = 0.1e-6; // Timestep for simulation
    int node1 = 0; // Node 1 for components
    int node2 = 1; // Node 2 for components

    /* Initialize matrices */
    for(int i = 0; i < num_nodes*num_nodes; i++){
        g_matrix[i] = 0 + 0*I;
        c_matrix[i] = 0 + 0*I;
    }
    for(int i = 0; i < num_nodes+1; i++){
        b_matrix[i] = 0 + 0*I;
    }

    /* Add components to matrices */
    resistor(g_matrix, node1, node2, resistance);
    capacitor(g_matrix, c_matrix, node1, node2, capacitance, timestep);
    voltage_source(g_matrix, b_matrix, node1, node2, voltage);

    /* Print matrices for debug */
    printf("G Matrix:\n");
    for(int i = 0; i < num_nodes*num_nodes; i++){
        printf("%f + %fI ", creal(g_matrix[i]), cimag(g_matrix[i]));
        if((i+1) % num_nodes == 0) printf("\n");
    }
    printf("\nC Matrix:\n");
    for(int i = 0; i < num_nodes*num_nodes; i++){
        printf("%f + %fI ", creal(c_matrix[i]), cimag(c_matrix[i]));
        if((i+1) % num_nodes == 0) printf("\n");
    }
    printf("\nB Matrix:\n");
    for(int i = 0; i < num_nodes+1; i++){
        printf("%f + %fI ", creal(b_matrix[i]), cimag(b_matrix[i]));
        if((i+1) % (num_nodes+1) == 0) printf("\n");
    }
    printf("\n");

    /* Free memory */
    return 0;
}