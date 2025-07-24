//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//define constants
#define MAX_RESISTORS 10
#define MAX_NODES 20

//define resistor struct
typedef struct {
    int nodeI;
    int nodeJ;
    double resistance;
} resistor_t;

//function declarations
void printCircuit(resistor_t resistors[], int nResistors, int nNodes);
void addResistor(resistor_t resistors[], int* nResistors, int nNodes);
void modifyResistor(resistor_t resistors[], int nResistors);
void deleteResistor(resistor_t resistors[], int* nResistors);
void solveCircuit(resistor_t resistors[], int nResistors, int nNodes);

int main() {
    resistor_t resistors[MAX_RESISTORS];
    int nResistors = 0;
    int nNodes = 0;
    char choice;

    //display menu and loop until user quits
    do {
        printf("MENU\n");
        printf("----\n");
        printf("1 - Print circuit\n");
        printf("2 - Add resistor\n");
        printf("3 - Modify resistor\n");
        printf("4 - Delete resistor\n");
        printf("5 - Solve circuit\n");
        printf("Q - Quit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':   //print circuit
                printCircuit(resistors, nResistors, nNodes);
                break;

            case '2':   //add resistor
                addResistor(resistors, &nResistors, nNodes);
                break;

            case '3':   //modify resistor
                modifyResistor(resistors, nResistors);
                break;

            case '4':   //delete resistor
                deleteResistor(resistors, &nResistors);
                break;

            case '5':   //solve circuit
                solveCircuit(resistors, nResistors, nNodes);
                break;

            case 'Q':   //quit
            case 'q':
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while(choice != 'Q' && choice != 'q');

    return 0;
}

//function to print circuit
void printCircuit(resistor_t resistors[], int nResistors, int nNodes) {
    int i;
    int j;

    printf("\nCIRCUIT\n");
    printf("-------\n");

    //print list of resistors
    printf("Resistors:\n");
    for(i = 0; i < nResistors; i++) {
        printf("%d. R%d: nodes %d and %d, resistance %.2lf ohms\n",
               i+1, i+1, resistors[i].nodeI, resistors[i].nodeJ, resistors[i].resistance);
    }

    //print list of nodes
    printf("Nodes:\n");
    for(i = 1; i <= nNodes; i++) {
        printf("%d. Node %d\n", i, i);
    }

    //print adjacency matrix
    printf("Adjacency matrix:\n");
    printf("    ");
    for(i = 1; i <= nNodes; i++) {
        printf("%-4d", i);
    }
    printf("\n");
    for(i = 1; i <= nNodes; i++) {
        printf("%-4d", i);
        for(j = 1; j <= nNodes; j++) {
            if(i == j) {
                printf("----");
            } else {
                int hasEdge = 0;
                int k;
                for(k = 0; k < nResistors; k++) {
                    if((resistors[k].nodeI == i && resistors[k].nodeJ == j) ||
                       (resistors[k].nodeI == j && resistors[k].nodeJ == i)) {
                        printf("R%-3d", k+1);
                        hasEdge = 1;
                        break;
                    }
                }
                if(!hasEdge) {
                    printf("    ");
                }
            }
        }
        printf("\n");
    }
}

//function to add resistor
void addResistor(resistor_t resistors[], int* nResistors, int nNodes) {
    int nodeI;
    int nodeJ;
    double resistance;

    //prompt user for resistor parameters
    printf("\nADD RESISTOR\n");
    printf("-------------\n");

    //prompt for node I
    printf("Enter node I (1 to %d): ", nNodes);
    scanf("%d", &nodeI);
    if(nodeI < 1 || nodeI > nNodes) {
        printf("Invalid node number. Please try again.\n");
        return;
    }

    //prompt for node J
    printf("Enter node J (1 to %d): ", nNodes);
    scanf("%d", &nodeJ);
    if(nodeJ < 1 || nodeJ > nNodes || nodeJ == nodeI) {
        printf("Invalid node number. Please try again.\n");
        return;
    }

    //prompt for resistance value
    printf("Enter resistance (ohms): ");
    scanf("%lf", &resistance);
    if(resistance <= 0) {
        printf("Invalid resistance value. Please try again.\n");
        return;
    }

    //add resistor to resistor array
    resistors[*nResistors].nodeI = nodeI;
    resistors[*nResistors].nodeJ = nodeJ;
    resistors[*nResistors].resistance = resistance;
    *nResistors = *nResistors + 1;

    printf("Resistor added.\n");
}

//function to modify resistor
void modifyResistor(resistor_t resistors[], int nResistors) {
    int index;
    double resistance;

    //prompt user for resistor index and new resistance value
    printf("\nMODIFY RESISTOR\n");
    printf("----------------\n");

    printf("Enter resistor index (1 to %d): ", nResistors);
    scanf("%d", &index);
    if(index < 1 || index > nResistors) {
        printf("Invalid resistor index. Please try again.\n");
        return;
    }

    printf("Enter new resistance value (ohms): ");
    scanf("%lf", &resistance);
    if(resistance <= 0) {
        printf("Invalid resistance value. Please try again.\n");
        return;
    }

    //modify resistor in resistor array
    resistors[index-1].resistance = resistance;

    printf("Resistor modified.\n");
}

//function to delete resistor
void deleteResistor(resistor_t resistors[], int* nResistors) {
    int index;
    int i;

    //prompt user for resistor index to delete
    printf("\nDELETE RESISTOR\n");
    printf("----------------\n");

    printf("Enter resistor index (1 to %d): ", *nResistors);
    scanf("%d", &index);
    if(index < 1 || index > *nResistors) {
        printf("Invalid resistor index. Please try again.\n");
        return;
    }

    //shift remaining resistors down in resistor array
    for(i = index; i < *nResistors; i++) {
        resistors[i-1].nodeI = resistors[i].nodeI;
        resistors[i-1].nodeJ = resistors[i].nodeJ;
        resistors[i-1].resistance = resistors[i].resistance;
    }
    *nResistors = *nResistors - 1;

    printf("Resistor deleted.\n");
}

//function to solve circuit
void solveCircuit(resistor_t resistors[], int nResistors, int nNodes) {
    int i;
    int j;

    //create adjacency matrix
    double adjacency[MAX_NODES][MAX_NODES];
    for(i = 1; i <= nNodes; i++) {
        for(j = 1; j <= nNodes; j++) {
            if(i == j) {
                adjacency[i][j] = 0.0;
            } else {
                int k;
                for(k = 0; k < nResistors; k++) {
                    if((resistors[k].nodeI == i && resistors[k].nodeJ == j) ||
                       (resistors[k].nodeI == j && resistors[k].nodeJ == i)) {
                        adjacency[i][j] = -1.0 / resistors[k].resistance;
                        break;
                    } else {
                        adjacency[i][j] = 0.0;
                    }
                }
            }
        }
    }

    //create diagonal matrix
    double diagonal[MAX_NODES][MAX_NODES];
    for(i = 1; i <= nNodes; i++) {
        double sum = 0.0;
        for(j = 1; j <= nNodes; j++) {
            if(i != j) {
                sum += fabs(adjacency[i][j]);
            }
        }
        diagonal[i][i] = sum;
    }

    //create laplacian matrix
    double laplacian[MAX_NODES][MAX_NODES];
    for(i = 1; i <= nNodes; i++) {
        for(j = 1; j <= nNodes; j++) {
            laplacian[i][j] = diagonal[i][j] - adjacency[i][j];
        }
    }

    //allocate space for matrix inverses to be stored
    double** diagonalInverse = (double**) malloc(nNodes * sizeof(double*));
    double** laplacianInverse = (double**) malloc(nNodes * sizeof(double*));
    for(i = 1; i <= nNodes; i++) {
        diagonalInverse[i] = (double*) malloc(nNodes * sizeof(double));
        laplacianInverse[i] = (double*) malloc(nNodes * sizeof(double));
    }

    //calculate diagonal inverse (diagonal matrix with reciprocal values on diagonal)
    for(i = 1; i <= nNodes; i++) {
        for(j = 1; j <= nNodes; j++) {
            if(i == j) {
                if(diagonal[i][j] != 0.0) {
                    diagonalInverse[i][j] = 1.0 / diagonal[i][j];
                } else {
                    diagonalInverse[i][j] = INFINITY;
                }
            } else {
                diagonalInverse[i][j] = 0.0;
            }
        }
    }

    //calculate Laplacian inverse
    for(i = 1; i <= nNodes; i++) {
        for(j = 1; j <= nNodes; j++) {
            laplacianInverse[i][j] = 0.0;
            int k;
            for(k = 1; k <= nNodes; k++) {
                laplacianInverse[i][j] += diagonalInverse[i][k] * laplacian[k][j];
            }
        }
    }

    //calculate nodal admittance matrix (Y)
    double admittance[MAX_NODES][MAX_NODES];
    for(i = 1; i <= nNodes; i++) {
        for(j = 1; j <= nNodes; j++) {
            admittance[i][j] = -laplacianInverse[i][j];
        }
    }

    //calculate node voltages (V)
    double* voltage = (double*) malloc(nNodes * sizeof(double));
    double* current = (double*) malloc(nResistors * sizeof(double));
    for(i = 1; i <= nNodes; i++) {
        voltage[i] = 0.0;
    }
    for(i = 0; i < nResistors; i++) {
        current[i] = 0.0;
        int node1 = resistors[i].nodeI;
        int node2 = resistors[i].nodeJ;
        current[i] = (voltage[node1] - voltage[node2]) / resistors[i].resistance;
    }

    //print results
    printf("\nRESULTS\n");
    printf("-------\n");
    printf("Nodal admittance matrix:\n");
    for(i = 1; i <= nNodes; i++) {
        for(j = 1; j <= nNodes; j++) {
            printf("%.4lf + %.4lfj\t", creal(admittance[i][j]), cimag(admittance[i][j]));
        }
        printf("\n");
    }
    printf("Node voltages:\n");
    for(i = 1; i <= nNodes; i++) {
        printf("Node %d: %.4lf + %.4lfj volts\n", i, creal(voltage[i]), cimag(voltage[i]));
    }
    printf("Currents through resistors:\n");
    for(i = 0; i < nResistors; i++) {
        printf("R%d: %.4lf + %.4lfj amps\n", i+1, creal(current[i]), cimag(current[i]));
    }

    //free dynamically allocated memory
    for(i = 1; i <= nNodes; i++) {
        free(diagonalInverse[i]);
        free(laplacianInverse[i]);
    }
    free(diagonalInverse);
    free(laplacianInverse);
    free(voltage);
    free(current);
}