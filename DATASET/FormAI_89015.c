//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

#define MAX_SIZE 10

// Struct for each component
typedef struct CircuitComponent {
    char type;
    int value;
    int nodes[2];
    double complex admittance;
} CircuitComponent;

// Function to find the admittance for each component
double complex calculateAdmittance(CircuitComponent component) {
    double complex admittance;
    double resistance, capacitance, inductance;

    switch (component.type) {
        case 'R':
            resistance = component.value;
            admittance = 1.0 / resistance;
            break;
        case 'C':
            capacitance = component.value;
            admittance = I * 2 * M_PI * capacitance;
            break;
        case 'L':
            inductance = component.value;
            admittance = 1.0 / (I * 2 * M_PI * inductance);
            break;
        default:
            admittance = 0 + 0 * I;
            break;
    }

    return admittance;
}

int main() {
    CircuitComponent circuit[MAX_SIZE];
    int numComponents, numNodes;

    printf("Enter the number of components in the circuit: ");
    scanf("%d", &numComponents);

    printf("Enter the number of nodes in the circuit: ");
    scanf("%d", &numNodes);

    // Initialize the admittance matrix with zeros
    double complex admittanceMatrix[MAX_SIZE][MAX_SIZE] = {0.0};

    // Add components to the circuit
    for (int i = 0; i < numComponents; i++) {
        printf("Enter the type of component (R for resistor, C for capacitor, L for inductor): ");
        scanf(" %c", &circuit[i].type);

        printf("Enter the value of the component in ohms, farads, or henrys: ");
        scanf("%d", &circuit[i].value);

        printf("Enter the nodes that the component connects to: ");
        scanf("%d %d", &circuit[i].nodes[0], &circuit[i].nodes[1]);

        // Calculate the admittance for each component and add it to admittance matrix
        double complex admittance = calculateAdmittance(circuit[i]);
        admittanceMatrix[circuit[i].nodes[0] - 1][circuit[i].nodes[0] - 1] += admittance;
        admittanceMatrix[circuit[i].nodes[1] - 1][circuit[i].nodes[1] - 1] += admittance;
        admittanceMatrix[circuit[i].nodes[0] - 1][circuit[i].nodes[1] - 1] -= admittance;
        admittanceMatrix[circuit[i].nodes[1] - 1][circuit[i].nodes[0] - 1] -= admittance;
    }

    // Print the admittance matrix
    printf("\nAdmittance Matrix:\n");
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            printf("%f + %f*I\t", creal(admittanceMatrix[i][j]), cimag(admittanceMatrix[i][j]));
        }
        printf("\n");
    }

    return 0;
}