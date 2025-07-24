//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_GATE 1024
#define MAX_WIRE 1024

typedef struct {
    int gate_type;
    int input1;
    int input2;
    int output;
} gate_t;

typedef struct {
    int state;
    int gate1;
    int gate2;
} wire_t;

gate_t gates[MAX_GATE];
wire_t wires[MAX_WIRE];

int num_gates = 0;
int num_wires = 0;
int inputs = 0;
int outputs = 0;

void execute_gate(int g) {
    /* Execute the gate */
    switch(gates[g].gate_type) {
        case 0: /* AND */
            wires[gates[g].output].state = (wires[gates[g].input1].state && wires[gates[g].input2].state);
            break;
        case 1: /* OR */
            wires[gates[g].output].state = (wires[gates[g].input1].state || wires[gates[g].input2].state);
            break;
        case 2: /* NOT */
            wires[gates[g].output].state = !wires[gates[g].input1].state;
            break;
        case 3: /* XOR */
            wires[gates[g].output].state = (wires[gates[g].input1].state ^ wires[gates[g].input2].state);
            break;
    }
}

int main() {
    int i;

    /* Set up some basic circuit */
    gates[0].gate_type = 0; /* AND */
    gates[0].input1 = 0;
    gates[0].input2 = 1;
    gates[0].output = 3;

    gates[1].gate_type = 1; /* OR */
    gates[1].input1 = 2;
    gates[1].input2 = 3;
    gates[1].output = 4;

    gates[2].gate_type = 2; /* NOT */
    gates[2].input1 = 4;
    gates[2].output = 5;

    /* Connect the wires */
    wires[0].state = 0;
    wires[0].gate1 = -1;
    wires[0].gate2 = -1;

    wires[1].state = 1;
    wires[1].gate1 = -1;
    wires[1].gate2 = -1;

    wires[2].state = 0;
    wires[2].gate1 = -1;
    wires[2].gate2 = -1;

    wires[3].gate1 = 0;
    wires[3].gate2 = -1;

    wires[4].gate1 = 1;
    wires[4].gate2 = -1;

    wires[5].gate1 = 2;
    wires[5].gate2 = -1;

    num_gates = 3;
    num_wires = 6;
    inputs = 2;
    outputs = 1;

    /* Run the simulation */
    for (i = 0; i < num_gates; i++) {
        execute_gate(i);
    }

    /* Print the results */
    printf("Input 1: %d\n", wires[0].state);
    printf("Input 2: %d\n", wires[1].state);
    printf("Output: %d\n", wires[5].state);

    return 0;
}