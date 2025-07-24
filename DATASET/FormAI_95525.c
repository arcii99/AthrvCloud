//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: inquisitive
// Have you ever wanted to simulate a classical circuit? Look no further!
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the Circuit struct for storing the circuit diagram and gate values
typedef struct Circuit {
    char diagram[100][100];
    bool gates[100][100];
} Circuit;

// Function for printing the circuit diagram and boolean values of gates
void printCircuit(Circuit c) {
    printf("\n---CIRCUIT DIAGRAM---\n");
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(c.diagram[i][j] == '\0') break;
            printf("%c", c.diagram[i][j]);
        }
        printf("\n");
    }
    printf("---GATE VALUES---\n");
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            printf("%d ", c.gates[i][j]);
        }
        printf("\n");
    }
}

// Function for initializing the circuit with the given size and diagram
Circuit createCircuit(int size, char diagram[][100]) {
    Circuit c;
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < 100; j++) {
            c.diagram[i][j] = diagram[i][j];
            c.gates[i][j] = false;
        }
    }
    return c;
}

// Function for updating the boolean values of the gates based on the input wires
void updateGates(Circuit *c, int size, int input[]) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < 100; j++) {
            if(c->diagram[i][j] == 'O' || c->diagram[i][j] == 'X') {
                int wire1 = atoi(&c->diagram[i-2][j]) - 1;
                int wire2 = atoi(&c->diagram[i+2][j]) - 1;
                if(c->diagram[i][j] == 'O') {
                    c->gates[i][j] = input[wire1] || input[wire2];
                }
                else {
                    c->gates[i][j] = input[wire1] && input[wire2];
                }
            }
        }
    }
}

// Example usage of functions to simulate a circuit
int main() {
    char diagram[10][100] = {
        "+-O--+",
        "|    |",
        "|  X-+",
        "|    |",
        "+----+"
    };
    Circuit c = createCircuit(5, diagram);
    printCircuit(c);

    int input[3] = {1, 0, 1};
    updateGates(&c, 5, input);
    printCircuit(c);

    return 0;
}