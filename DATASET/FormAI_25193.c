//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: introspective
#include <stdio.h>

#define MAX_NODES 100  // maximum number of nodes allowed
#define MAX_GUESS 10    // maximum number of iterations for guess

// Structure to hold the properties of a resistor.
typedef struct resistance {
    int node1, node2;
    double value;
} res_t;

// Structure to hold the properties of a voltage source.
typedef struct voltageSource {
    int node1, node2;
    double value;
} vs_t;

// Structure to hold the properties of a current source.
typedef struct currentSource {
    int node1, node2;
    double value;
} cs_t;

// The circuit nodes.
int nodes[MAX_NODES + 1];  // set of all nodes in the circuit
int numNodes;  // number of nodes in the circuit

// The circuit components.
res_t resistors[MAX_NODES];  // set of all resistors in the circuit
int numResistors;  // number of resistors in the circuit
vs_t voltageSources[MAX_NODES];  // set of all voltage sources in the circuit
int numVoltageSources;  // number of voltage sources in the circuit
cs_t currentSources[MAX_NODES];  // set of all current sources in the circuit
int numCurrentSources;  // number of current sources in the circuit

// The circuit equations.
double A[MAX_NODES + 1][MAX_NODES + 2];  // the augmented matrix for calculating the nodal voltages

// Calculates the nodal voltages for the circuit.
void calculateNodalVoltages() {
    int i, j, k, iter;
    double guess[MAX_NODES + 1];

    // Set the initial guess for the nodal voltages.
    for (i = 1; i <= numNodes; i++) {
        guess[i] = 0;
    }

    // Iteratively solve the equation A*x = b to find the nodal voltages x.
    for (iter = 0; iter < MAX_GUESS; iter++) {
        // Calculate the elements of the augmented matrix A.
        for (i = 1; i <= numNodes; i++) {
            A[i][numNodes + 1] = 0;

            // Calculate the sum of the currents leaving each node.
            for (j = 0; j < numResistors; j++) {
                if (resistors[j].node1 == i) {
                    A[i][resistors[j].node1] += 1.0 / resistors[j].value;
                    A[i][resistors[j].node2] -= 1.0 / resistors[j].value;
                } else if (resistors[j].node2 == i) {
                    A[i][resistors[j].node2] += 1.0 / resistors[j].value;
                    A[i][resistors[j].node1] -= 1.0 / resistors[j].value;
                }
            }

            // Calculate the contributions of the voltage sources.
            for (j = 0; j < numVoltageSources; j++) {
                if (voltageSources[j].node1 == i) {
                    A[i][numNodes + 1] -= voltageSources[j].value;
                } else if (voltageSources[j].node2 == i) {
                    A[i][numNodes + 1] += voltageSources[j].value;
                }
            }

            // Calculate the contributions of the current sources.
            for (j = 0; j < numCurrentSources; j++) {
                if (currentSources[j].node1 == i) {
                    A[i][numNodes + 1] += currentSources[j].value;
                } else if (currentSources[j].node2 == i) {
                    A[i][numNodes + 1] -= currentSources[j].value;
                }
            }
        }

        // Solve the equation A*x = b to find the nodal voltages.
        for (i = 1; i <= numNodes; i++) {
            double sum = A[i][numNodes + 1];
            for (j = 1; j <= numNodes; j++) {
                if (i != j) {
                    sum -= A[i][j] * guess[j];
                }
            }
            guess[i] = sum / A[i][i];
        }

        // Check if the guess has converged.
        double error = 0;
        for (i = 1; i <= numNodes; i++) {
            error += (guess[i] - A[i][numNodes + 1]) * (guess[i] - A[i][numNodes + 1]);
        }
        if (error < 1e-10) {
            break;
        }
    }

    // Print the nodal voltages.
    printf("Nodal Voltages : \n");
    for (i = 1; i <= numNodes; i++) {
        printf("Node %d voltage : %lf\n", i, guess[i]);
    }
}

// The main function to simulate the circuit.
int main() {
    int i;

    // Initialize the circuit nodes.
    for (i = 0; i <= MAX_NODES; i++) {
        nodes[i] = 0;
    }

    // Initialize the circuit components.
    numResistors = 0;
    numVoltageSources = 0;
    numCurrentSources = 0;

    // Add the resistors to the circuit.
    printf("Enter the number of resistors : ");
    scanf("%d", &numResistors);
    for (i = 0; i < numResistors; i++) {
        printf("Enter resistor %d values (node1, node2, value) : ", i+1);
        scanf("%d%d%lf", &resistors[i].node1, &resistors[i].node2, &resistors[i].value);

        // Update the set of nodes.
        nodes[resistors[i].node1] = 1;
        nodes[resistors[i].node2] = 1;
    }

    // Add the voltage sources to the circuit.
    printf("Enter the number of voltage sources : ");
    scanf("%d", &numVoltageSources);
    for (i = 0; i < numVoltageSources; i++) {
        printf("Enter voltage source %d values (node1, node2, value) : ", i+1);
        scanf("%d%d%lf", &voltageSources[i].node1, &voltageSources[i].node2, &voltageSources[i].value);

        // Update the set of nodes.
        nodes[voltageSources[i].node1] = 1;
        nodes[voltageSources[i].node2] = 1;
    }

    // Add the current sources to the circuit.
    printf("Enter the number of current sources : ");
    scanf("%d", &numCurrentSources);
    for (i = 0; i < numCurrentSources; i++) {
        printf("Enter current source %d values (node1, node2, value) : ", i+1);
        scanf("%d%d%lf", &currentSources[i].node1, &currentSources[i].node2, &currentSources[i].value);

        // Update the set of nodes.
        nodes[currentSources[i].node1] = 1;
        nodes[currentSources[i].node2] = 1;
    }

    // Count the number of nodes in the circuit.
    numNodes = 0;
    for (i = 1; i <= MAX_NODES; i++) {
        if (nodes[i] == 1) {
            numNodes++;
        }
    }

    // Calculate the nodal voltages for the circuit.
    calculateNodalVoltages();

    return 0;
}