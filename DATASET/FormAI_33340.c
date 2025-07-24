//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: energetic
// Let's start by creating a circuit
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_GATE_INPUTS 5
#define MAX_NODE_NAME_LENGTH 20
#define MAX_LINE_LENGTH 80

typedef struct {
    char gate_type[10];
    char name[MAX_NODE_NAME_LENGTH];
    int num_inputs;
    char input_names[MAX_GATE_INPUTS][MAX_NODE_NAME_LENGTH];
    char output_names[MAX_NODE_NAME_LENGTH];
    double delay;
} gate;

typedef struct {
    char name[MAX_NODE_NAME_LENGTH];
    double value;
    int is_input;
} node;

gate circuit[100];
int num_gates = 0;

node inputs[10];
int num_inputs = 0;

node outputs[10];
int num_outputs = 0;

double simulation_time = 0;

void add_input(char* name, double value) {
    strncpy(inputs[num_inputs].name, name, MAX_NODE_NAME_LENGTH);
    inputs[num_inputs].value = value;
    inputs[num_inputs].is_input = 1;
    num_inputs++;
}

void add_output(char* name) {
    strncpy(outputs[num_outputs].name, name, MAX_NODE_NAME_LENGTH);
    num_outputs++;
}

void add_gate(char* gate_type, char* name, char input_names[MAX_GATE_INPUTS][MAX_NODE_NAME_LENGTH], int num_inputs, char* output_name, double delay) {
    strncpy(circuit[num_gates].gate_type, gate_type, 10);
    strncpy(circuit[num_gates].name, name, MAX_NODE_NAME_LENGTH);
    circuit[num_gates].num_inputs = num_inputs;
    for (int i = 0; i < num_inputs; i++) {
        strncpy(circuit[num_gates].input_names[i], input_names[i], MAX_NODE_NAME_LENGTH);
    }
    strncpy(circuit[num_gates].output_names, output_name, MAX_NODE_NAME_LENGTH);
    circuit[num_gates].delay = delay;
    num_gates++;
}

double get_node_value(char* name) {
    for (int i = 0; i < num_inputs; i++) {
        if (strcmp(inputs[i].name, name) == 0) {
            return inputs[i].value;
        }
    }
    for (int i = 0; i < num_gates; i++) {
        for (int j = 0; j < circuit[i].num_inputs; j++) {
            if (strcmp(circuit[i].input_names[j], name) == 0) {
                return get_node_value(circuit[i].output_names);
            }
        }
    }
    return 0;
}

void run_simulation() {
    int num_ticks = (int)ceil(simulation_time);
    for (int i = 0; i < num_ticks; i++) {
        for (int j = 0; j < num_gates; j++) {
            double inputs[MAX_GATE_INPUTS];
            for (int k = 0; k < circuit[j].num_inputs; k++) {
                inputs[k] = get_node_value(circuit[j].input_names[k]);
            }
            if (strcmp(circuit[j].gate_type, "and") == 0) {
                int output = 1;
                for (int k = 0; k < circuit[j].num_inputs; k++) {
                    if (inputs[k] == 0) {
                        output = 0;
                        break;
                    }
                }
                if (output) {
                    printf("%s: 1\n", circuit[j].output_names);
                } else {
                    printf("%s: 0\n", circuit[j].output_names);
                }
            } else if (strcmp(circuit[j].gate_type, "or") == 0) {
                int output = 0;
                for (int k = 0; k < circuit[j].num_inputs; k++) {
                    if (inputs[k] == 1) {
                        output = 1;
                        break;
                    }
                }
                if (output) {
                    printf("%s: 1\n", circuit[j].output_names);
                } else {
                    printf("%s: 0\n", circuit[j].output_names);
                }
            } else if (strcmp(circuit[j].gate_type, "not") == 0) {
                if (inputs[0] == 0) {
                    printf("%s: 1\n", circuit[j].output_names);
                } else {
                    printf("%s: 0\n", circuit[j].output_names);
                }
            }
        }
        printf("\n");
    }
}

int main() {
    // Create a circuit that consists of two inputs and one output
    add_input("A", 0);
    add_input("B", 0);
    add_output("Y");

    // Add a gate that outputs the NOT of input A
    char input_names1[MAX_GATE_INPUTS][MAX_NODE_NAME_LENGTH];
    strncpy(input_names1[0], "A", MAX_NODE_NAME_LENGTH);
    add_gate("not", "g1", input_names1, 1, "x1", 1);

    // Add a gate that outputs A AND B
    char input_names2[MAX_GATE_INPUTS][MAX_NODE_NAME_LENGTH];
    strncpy(input_names2[0], "A", MAX_NODE_NAME_LENGTH);
    strncpy(input_names2[1], "B", MAX_NODE_NAME_LENGTH);
    add_gate("and", "g2", input_names2, 2, "x2", 2);

    // Add a gate that outputs the OR of the previous two gates
    char input_names3[MAX_GATE_INPUTS][MAX_NODE_NAME_LENGTH];
    strncpy(input_names3[0], "x1", MAX_NODE_NAME_LENGTH);
    strncpy(input_names3[1], "x2", MAX_NODE_NAME_LENGTH);
    add_gate("or", "g3", input_names3, 2, "Y", 3);

    // Print the circuit
    printf("Circuit:\n");
    for (int i = 0; i < num_gates; i++) {
        printf("%s: %s(", circuit[i].name, circuit[i].gate_type);
        for (int j = 0; j < circuit[i].num_inputs; j++) {
            printf("%s ", circuit[i].input_names[j]);
        }
        printf(") -> %s\n", circuit[i].output_names);
    }
    printf("\n");

    // Run the simulation for 5 seconds
    simulation_time = 5;
    printf("Simulation for %f seconds:\n", simulation_time);
    run_simulation();

    return 0;
}