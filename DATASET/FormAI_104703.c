//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of components
#define MAX_COMPONENTS 100

// Define the maximum length of component names
#define MAX_NAME_LENGTH 20

// Define the maximum number of nodes
#define MAX_NODES 50

// Define the maximum length of node names
#define MAX_NODE_LENGTH 5

// Define the maximum number of inputs and outputs
#define MAX_IO 10

// Define the maximum filename length
#define MAX_FILENAME_LENGTH 50

// Define component types
#define RESISTOR 1
#define CAPACITOR 2
#define INDUCTOR 3

// Define a struct for components
typedef struct {
    int type; // Component type
    char name[MAX_NAME_LENGTH]; // Component name
    char node1[MAX_NODE_LENGTH]; // First node name
    char node2[MAX_NODE_LENGTH]; // Second node name
    double value; // Component value
} component;

// Define a struct for nodes
typedef struct {
    char name[MAX_NODE_LENGTH]; // Node name
    int io; // Input or output flag: 0 if neither, 1 if input, 2 if output
    double voltage; // Node voltage
} node;

// Define global variables
component components[MAX_COMPONENTS];
node nodes[MAX_NODES];
int num_components = 0;
int num_nodes = 0;
char input_nodes[MAX_IO][MAX_NODE_LENGTH];
char output_nodes[MAX_IO][MAX_NODE_LENGTH];
int num_input_nodes = 0;
int num_output_nodes = 0;

// Function to parse the circuit file
void parse_circuit_file(char* filename) {
    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Cannot open file %s.\n", filename);
        exit(1);
    }
    char line[100];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "resistor")) {
            component c;
            c.type = RESISTOR;
            sscanf(line, "%s %lf %s %s", c.name, &c.value, c.node1, c.node2);
            components[num_components++] = c;
        }
        else if (strstr(line, "capacitor")) {
            component c;
            c.type = CAPACITOR;
            sscanf(line, "%s %lf %s %s", c.name, &c.value, c.node1, c.node2);
            components[num_components++] = c;
        }
        else if (strstr(line, "inductor")) {
            component c;
            c.type = INDUCTOR;
            sscanf(line, "%s %lf %s %s", c.name, &c.value, c.node1, c.node2);
            components[num_components++] = c;
        }
        else if (strstr(line, "input")) {
            char node_name[MAX_NODE_LENGTH];
            sscanf(line, "%*s %s", node_name);
            strcpy(input_nodes[num_input_nodes++], node_name);
        }
        else if (strstr(line, "output")) {
            char node_name[MAX_NODE_LENGTH];
            sscanf(line, "%*s %s", node_name);
            strcpy(output_nodes[num_output_nodes++], node_name);
        }
    }
    fclose(fp);
}

// Function to add a node to the node list
void add_node(char* node_name) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, node_name) == 0) {
            return;
        }
    }
    node n;
    strcpy(n.name, node_name);
    n.io = 0;
    n.voltage = 0.0;
    nodes[num_nodes++] = n;
}

// Function to set the input or output flag for a node
void set_io_flag(char* node_name, int flag) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, node_name) == 0) {
            nodes[i].io = flag;
            return;
        }
    }
}

// Function to perform DC analysis on the circuit
void dc_analysis() {
    int i, j, k;

    // Initialize the node voltages
    for (i = 0; i < num_nodes; i++) {
        nodes[i].voltage = 0.0;
    }

    // Set the input voltages
    for (i = 0; i < num_input_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            if (strcmp(nodes[j].name, input_nodes[i]) == 0) {
                nodes[j].voltage = 1.0;
            }
        }
    }

    // Perform the DC analysis
    for (k = 0; k < 100; k++) {
        for (i = 0; i < num_components; i++) {
            component c = components[i];
            double v1 = 0.0;
            double v2 = 0.0;
            for (j = 0; j < num_nodes; j++) {
                if (strcmp(nodes[j].name, c.node1) == 0) {
                    v1 = nodes[j].voltage;
                }
                if (strcmp(nodes[j].name, c.node2) == 0) {
                    v2 = nodes[j].voltage;
                }
            }
            double vdiff = v1 - v2;
            if (c.type == RESISTOR) {
                double current = vdiff / c.value;
                for (j = 0; j < num_nodes; j++) {
                    if (strcmp(nodes[j].name, c.node1) == 0) {
                        nodes[j].voltage -= current;
                    }
                    if (strcmp(nodes[j].name, c.node2) == 0) {
                        nodes[j].voltage += current;
                    }
                }
            }
            else if (c.type == CAPACITOR) {
                double current = c.value * (vdiff / 0.01);
                for (j = 0; j < num_nodes; j++) {
                    if (strcmp(nodes[j].name, c.node1) == 0) {
                        nodes[j].voltage -= current;
                    }
                    if (strcmp(nodes[j].name, c.node2) == 0) {
                        nodes[j].voltage += current;
                    }
                }
            }
            else if (c.type == INDUCTOR) {
                double current = c.value * (vdiff * 0.01);
                for (j = 0; j < num_nodes; j++) {
                    if (strcmp(nodes[j].name, c.node1) == 0) {
                        nodes[j].voltage -= current;
                    }
                    if (strcmp(nodes[j].name, c.node2) == 0) {
                        nodes[j].voltage += current;
                    }
                }
            }
        }
    }

    // Print the output voltages
    printf("Output voltages:\n");
    for (i = 0; i < num_output_nodes; i++) {
        for (j = 0; j < num_nodes; j++) {
            if (strcmp(nodes[j].name, output_nodes[i]) == 0) {
                printf("%s: %f V\n", nodes[j].name, nodes[j].voltage);
            }
        }
    }
}

int main() {
    char filename[MAX_FILENAME_LENGTH];

    // Prompt the user for the circuit file
    printf("Enter the circuit file name: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;

    // Parse the circuit file
    parse_circuit_file(filename);

    // Add the nodes to the node list
    for (int i = 0; i < num_components; i++) {
        add_node(components[i].node1);
        add_node(components[i].node2);
    }

    // Set the input and output flags for the nodes
    for (int i = 0; i < num_input_nodes; i++) {
        set_io_flag(input_nodes[i], 1);
    }
    for (int i = 0; i < num_output_nodes; i++) {
        set_io_flag(output_nodes[i], 2);
    }

    // Perform the DC analysis
    dc_analysis();

    return 0;
}