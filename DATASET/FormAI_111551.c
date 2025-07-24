//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

int main() {
    // welcome message
    printf("Welcome to the Classical Circuit Simulator!\n");

    // prompt user for input file
    char filename[100];
    printf("Please enter the name of the input file: ");
    scanf("%s", filename);

    // open input file and read data
    FILE* fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    int num_nodes, num_resistors;
    fscanf(fptr, "%d %d", &num_nodes, &num_resistors);
    int nodes[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        fscanf(fptr, "%d", &nodes[i]);
    }
    int resistors[num_resistors][3];
    for (int i = 0; i < num_resistors; i++) {
        fscanf(fptr, "%d %d %d", &resistors[i][0], &resistors[i][1], &resistors[i][2]);
    }
    fclose(fptr);

    // print circuit information
    printf("Circuit information:\n");
    printf("Number of nodes: %d\n", num_nodes);
    printf("Node voltages: ");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", nodes[i]);
    }
    printf("\n");
    printf("Number of resistors: %d\n", num_resistors);
    printf("Resistor information:\n");
    for (int i = 0; i < num_resistors; i++) {
        printf(" Resistor %d: %d ohms between nodes %d and %d\n", i+1, resistors[i][2], resistors[i][0], resistors[i][1]);
    }

    // solve for node voltages using Kirchhoff's laws
    float A[num_nodes][num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            A[i][j] = 0;
        }
    }
    float b[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        b[i] = 0;
    }
    for (int i = 0; i < num_resistors; i++) {
        int n1 = resistors[i][0]-1;
        int n2 = resistors[i][1]-1;
        float R = resistors[i][2];
        A[n1][n1] += 1/R;
        A[n1][n2] -= 1/R;
        A[n2][n2] += 1/R;
        A[n2][n1] -= 1/R;
    }
    for (int i = 1; i < num_nodes-1; i++) {
        b[i] = 0;
    }
    b[0] = nodes[0];
    b[num_nodes-1] = nodes[num_nodes-1];
    float x[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        x[i] = 0;
    }
    int iter = 0;
    while (iter < 1000) {
        for (int i = 0; i < num_nodes; i++) {
            float sum = 0;
            for (int j = 0; j < num_nodes; j++) {
                sum += A[i][j]*x[j];
            }
            x[i] = (b[i]-sum)/A[i][i];
        }
        iter++;
    }

    // print node voltages
    printf("Node voltages:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf(" Node %d: %f volts\n", i+1, x[i]);
    }

    return 0;
}