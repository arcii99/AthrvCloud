//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: decentralized
/*
 * This is a decentralized implementation of a classical circuit simulator, which allows 
 * users to create and simulate digital circuits on the fly.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUTS 50
#define MAX_OUTPUTS 50
#define MAX_CIRCUIT_SIZE 500

/* Data structures */

// Gate types
enum gate_types { G_INPUT, G_OUTPUT, G_AND, G_OR, G_XOR, G_NOT };

// Circuit gate struct
typedef struct _gate {
    unsigned int id;                    // Unique ID of the gate
    enum gate_types type;               // Gate type
    int arity;                          // Number of inputs to the gate
    int inputs[MAX_INPUTS];             // Input IDs
    int outputs[MAX_OUTPUTS];           // Output IDs
    int state;                          // Current output state
    int (*eval_fn)(struct _gate *);     // Gate evaluation function pointer
} gate;

// Circuit struct
typedef struct _circuit {
    unsigned int size;                  // Number of gates in the circuit
    gate gates[MAX_CIRCUIT_SIZE];       // Circuit gates
} circuit;

/* Gate evaluation functions */

// AND gate evaluation function
int eval_and(gate *g) {
    int i;
    int result = 1;
    for (i = 0; i < g->arity; i++) {
        result = result && g->inputs[i];
    }
    return result;
}

// OR gate evaluation function
int eval_or(gate *g) {
    int i;
    int result = 0;
    for (i = 0; i < g->arity; i++) {
        result = result || g->inputs[i];
    }
    return result;
}

// XOR gate evaluation function
int eval_xor(gate *g) {
    int i;
    int result = 0;
    for (i = 0; i < g->arity; i++) {
        result = result ^ g->inputs[i];
    }
    return result;
}

// NOT gate evaluation function
int eval_not(gate *g) {
    return !g->inputs[0];
}

/* Circuit management functions */

// Initialize an empty circuit
void init_circuit(circuit *c) {
    c->size = 0;
}

// Add an input gate to the circuit
int add_input_gate(circuit *c) {
    int id = c->size;
    c->gates[id].id = id;
    c->gates[id].type = G_INPUT;
    c->gates[id].arity = 0;
    c->gates[id].state = 0;
    c->gates[id].eval_fn = NULL;
    c->size++;
    return id;
}

// Add an output gate to the circuit
int add_output_gate(circuit *c, int input_gate_id) {
    int id = c->size;
    c->gates[id].id = id;
    c->gates[id].type = G_OUTPUT;
    c->gates[id].arity = 1;
    c->gates[id].inputs[0] = input_gate_id;
    c->gates[id].state = 0;
    c->gates[id].eval_fn = NULL;
    c->gates[input_gate_id].outputs[c->gates[input_gate_id].arity++] = id;
    c->size++;
    return id;
}

// Add a two-input gate to the circuit
int add_two_input_gate(circuit *c, enum gate_types type, int input1, int input2) {
    int id = c->size;
    c->gates[id].id = id;
    c->gates[id].type = type;
    c->gates[id].arity = 2;
    c->gates[id].inputs[0] = input1;
    c->gates[id].inputs[1] = input2;
    c->gates[id].state = 0;
    switch (type) {
        case G_AND:
            c->gates[id].eval_fn = eval_and;
            break;
        case G_OR:
            c->gates[id].eval_fn = eval_or;
            break;
        case G_XOR:
            c->gates[id].eval_fn = eval_xor;
            break;
        default:
            c->gates[id].eval_fn = NULL;
            break;
    }
    c->gates[input1].outputs[c->gates[input1].arity++] = id;
    c->gates[input2].outputs[c->gates[input2].arity++] = id;
    c->size++;
    return id;
}

// Add a NOT gate to the circuit
int add_not_gate(circuit *c, int input) {
    int id = c->size;
    c->gates[id].id = id;
    c->gates[id].type = G_NOT;
    c->gates[id].arity = 1;
    c->gates[id].inputs[0] = input;
    c->gates[id].state = 0;
    c->gates[id].eval_fn = eval_not;
    c->gates[input].outputs[c->gates[input].arity++] = id;
    c->size++;
    return id;
}

// Evaluate the circuit
void eval_circuit(circuit *c) {
    int i, j;
    // First, clear the output gate states
    for (i = 0; i < c->size; i++) {
        if (c->gates[i].type == G_OUTPUT) {
            c->gates[i].state = 0;
        }
    }
    // Then, recursively evaluate all gates
    for (i = 0; i < c->size; i++) {
        if (c->gates[i].type != G_INPUT) {
            for (j = 0; j < c->gates[i].arity; j++) {
                eval_circuit_gate(c, &c->gates[c->gates[i].inputs[j]]);
            }
            if (c->gates[i].eval_fn) {
                c->gates[i].state = c->gates[i].eval_fn(&c->gates[i]);
            }
        }
    }
}

// Internal gate evaluation function
void eval_circuit_gate(circuit *c, gate *g) {
    int i;
    for (i = 0; i < g->arity; i++) {
        if (c->gates[g->inputs[i]].type != G_INPUT) {
            eval_circuit_gate(c, &c->gates[g->inputs[i]]);
        }
    }
    if (g->eval_fn) {
        g->state = g->eval_fn(g);
    }
}

/* User interface functions */

// Print a gate
void print_gate(gate *g) {
    int i;
    printf("Gate %d: ", g->id);
    switch (g->type) {
        case G_INPUT:
            printf("INPUT");
            break;
        case G_OUTPUT:
            printf("OUTPUT");
            break;
        case G_AND:
            printf("AND");
            break;
        case G_OR:
            printf("OR");
            break;
        case G_XOR:
            printf("XOR");
            break;
        case G_NOT:
            printf("NOT");
            break;
    }
    printf("(");
    for (i = 0; i < g->arity; i++) {
        printf("%d", g->inputs[i]);
        if (i < g->arity - 1) {
            printf(", ");
        }
    }
    printf(") => %d\n", g->state);
}

// Print the entire circuit
void print_circuit(circuit *c) {
    int i;
    printf("Circuit size: %d\n", c->size);
    for (i = 0; i < c->size; i++) {
        print_gate(&c->gates[i]);
    }
}

int main() {
    // Create a new circuit
    circuit c;
    init_circuit(&c);
    
    // Add some gates to the circuit
    int a = add_input_gate(&c);
    int b = add_input_gate(&c);
    int c2 = add_two_input_gate(&c, G_OR, a, b);
    int d = add_not_gate(&c, c2);
    int e = add_output_gate(&c, d);
    
    // Evaluate the circuit
    eval_circuit(&c);
    
    // Print the circuit
    print_circuit(&c);
    
    return 0;
}