//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Donald Knuth style Classical Circuit Simulator */

#define MAX_GATES 100
#define MAX_WIRES 50

/* define gate types */
#define GATE_TYPE_NOT 0
#define GATE_TYPE_AND 1
#define GATE_TYPE_OR 2
#define GATE_TYPE_XOR 3

/* define wire state */
#define WIRE_STATE_LOW 0
#define WIRE_STATE_HIGH 1
#define WIRE_STATE_X 2

/* define wire */
typedef struct {
    char name;
    int state;
} Wire;

/* define gate */
typedef struct {
    char name;
    int type;
    int num_inputs;
    Wire* inputs[MAX_WIRES];
    Wire* output;
} Gate;

/* define circuit */
typedef struct {
    int num_gates;
    Gate gates[MAX_GATES];
} Circuit;

int cmp_wires(const void* a, const void* b) {
    Wire* wire_a = (Wire*) a;
    Wire* wire_b = (Wire*) b;
    return wire_a->name - wire_b->name;
}

void add_wire(Circuit* circuit, char name) {
    int i;
    for (i = 0; i < circuit->num_gates; i++) {
        int j;
        for (j = 0; j < circuit->gates[i].num_inputs; j++) {
            if (circuit->gates[i].inputs[j]->name == name) {
                return;
            }
        }
        if (circuit->gates[i].output->name == name) {
            return;
        }
    }
    Wire* wire = (Wire*) malloc(sizeof(Wire));
    wire->name = name;
    wire->state = WIRE_STATE_X;
    circuit->gates[circuit->num_gates].num_inputs = 0;
    circuit->gates[circuit->num_gates].output = wire;
    circuit->num_gates++;
}

Wire* get_wire(Circuit* circuit, char name) {
    int i;
    for (i = 0; i < circuit->num_gates; i++) {
        int j;
        for (j = 0; j < circuit->gates[i].num_inputs; j++) {
            if (circuit->gates[i].inputs[j]->name == name) {
                return circuit->gates[i].inputs[j];
            }
        }
        if (circuit->gates[i].output->name == name) {
            return circuit->gates[i].output;
        }
    }
    return NULL;
}

void add_gate(Circuit* circuit, char name, int type, char* inputs, char output) {
    Gate* gate = (Gate*) malloc(sizeof(Gate));
    gate->name = name;
    gate->type = type;
    gate->num_inputs = 0;
    Wire* output_wire = get_wire(circuit, output);
    if (output_wire == NULL) {
        output_wire = (Wire*) malloc(sizeof(Wire));
        output_wire->name = output;
        output_wire->state = WIRE_STATE_X;
        circuit->gates[circuit->num_gates].num_inputs = 0;
        circuit->gates[circuit->num_gates].output = output_wire;
        circuit->num_gates++;
    }
    gate->output = output_wire;
    int i;
    for (i = 0; inputs[i] != '\0'; i++) {
        Wire* input_wire = get_wire(circuit, inputs[i]);
        if (input_wire == NULL) {
            input_wire = (Wire*) malloc(sizeof(Wire));
            input_wire->name = inputs[i];
            input_wire->state = WIRE_STATE_X;
            circuit->gates[circuit->num_gates].num_inputs = 0;
            circuit->gates[circuit->num_gates].output = input_wire;
            circuit->num_gates++;
        }
        gate->inputs[gate->num_inputs++] = input_wire;
    }
    circuit->gates[circuit->num_gates++] = *gate;
}

void add_not_gate(Circuit* circuit, char name, char input, char output) {
    char inputs[] = {input, '\0'};
    add_gate(circuit, name, GATE_TYPE_NOT, inputs, output);
}

void add_and_gate(Circuit* circuit, char name, char input_a, char input_b, char output) {
    char inputs[] = {input_a, input_b, '\0'};
    add_gate(circuit, name, GATE_TYPE_AND, inputs, output);
}

void add_or_gate(Circuit* circuit, char name, char input_a, char input_b, char output) {
    char inputs[] = {input_a, input_b, '\0'};
    add_gate(circuit, name, GATE_TYPE_OR, inputs, output);
}

void add_xor_gate(Circuit* circuit, char name, char input_a, char input_b, char output) {
    char inputs[] = {input_a, input_b, '\0'};
    add_gate(circuit, name, GATE_TYPE_XOR, inputs, output);
}

int simulate_gate(Gate* gate) {
    int i;
    int num_high_inputs = 0;
    for (i = 0; i < gate->num_inputs; i++) {
        if (gate->inputs[i]->state == WIRE_STATE_HIGH) {
            num_high_inputs++;
        } else if (gate->inputs[i]->state == WIRE_STATE_X) {
            return WIRE_STATE_X;
        }
    }
    if (gate->type == GATE_TYPE_NOT) {
        return (num_high_inputs == 0) ? WIRE_STATE_HIGH : WIRE_STATE_LOW;
    } else if (gate->type == GATE_TYPE_AND) {
        return (num_high_inputs == gate->num_inputs) ? WIRE_STATE_HIGH : WIRE_STATE_LOW;
    } else if (gate->type == GATE_TYPE_OR) {
        return (num_high_inputs > 0) ? WIRE_STATE_HIGH : WIRE_STATE_LOW;
    } else if (gate->type == GATE_TYPE_XOR) {
        return (num_high_inputs % 2 == 1) ? WIRE_STATE_HIGH : WIRE_STATE_LOW;
    }
    return WIRE_STATE_X;
}

void simulate(Circuit* circuit, int num_iterations) {
    int i, j, k;
    for (i = 0; i < num_iterations; i++) {
        /* sort wires by name */
        qsort(circuit->gates, circuit->num_gates, sizeof(Gate), cmp_wires);
        /* simulate each gate */
        for (j = 0; j < circuit->num_gates; j++) {
            circuit->gates[j].output->state = simulate_gate(&circuit->gates[j]);
        }
    }
}

void print_wire(Wire* wire) {
    printf("%c: ", wire->name);
    if (wire->state == WIRE_STATE_HIGH) {
        printf("1\n");
    } else if (wire->state == WIRE_STATE_LOW) {
        printf("0\n");
    } else {
        printf("X\n");
    }
}

void print_circuit(Circuit* circuit) {
    int i, j;
    for (i = 0; i < circuit->num_gates; i++) {
        Gate* gate = &circuit->gates[i];
        printf("%c = ", gate->output->name);
        if (gate->type == GATE_TYPE_NOT) {
            printf("NOT %c\n", gate->inputs[0]->name);
        } else if (gate->type == GATE_TYPE_AND) {
            for (j = 0; j < gate->num_inputs; j++) {
                printf("%c", gate->inputs[j]->name);
                if (j < gate->num_inputs - 1) {
                    printf(" AND ");
                }
            }
            printf("\n");
        } else if (gate->type == GATE_TYPE_OR) {
            for (j = 0; j < gate->num_inputs; j++) {
                printf("%c", gate->inputs[j]->name);
                if (j < gate->num_inputs - 1) {
                    printf(" OR ");
                }
            }
            printf("\n");
        } else if (gate->type == GATE_TYPE_XOR) {
            for (j = 0; j < gate->num_inputs; j++) {
                printf("%c", gate->inputs[j]->name);
                if (j < gate->num_inputs - 1) {
                    printf(" XOR ");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    Circuit circuit;
    circuit.num_gates = 0;
    /* add wires */
    add_wire(&circuit, 'A');
    add_wire(&circuit, 'B');
    add_wire(&circuit, 'C');
    add_wire(&circuit, 'D');
    add_wire(&circuit, 'Y');
    /* add gates */
    add_not_gate(&circuit, '1', 'A', 'B');
    add_and_gate(&circuit, '2', 'A', 'B', 'C');
    add_or_gate(&circuit, '3', 'C', 'D', 'Y');
    /* simulate circuit */
    simulate(&circuit, 10);
    /* print results */
    print_circuit(&circuit);
    int i;
    for (i = 0; i < circuit.num_gates; i++) {
        print_wire(circuit.gates[i].output);
    }
    return 0;
}