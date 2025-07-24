//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_NODES 100
#define MAX_ELEMENTS 200
#define MAX_NAME_LEN 50

// Define variables
int res_count = 0;
int voltage_count = 0;
int node_count = 0;
int elem_count = 0;
float time = 0;
float timestep = 0.1;

// Store resistor details
typedef struct {
    char name[MAX_NAME_LEN];
    int node1, node2;
    float value, current;
} Resistor;

Resistor res_array[MAX_ELEMENTS];

// Store voltage source details
typedef struct {
    char name[MAX_NAME_LEN];
    int node1, node2;
    float value, current;
} Voltage;

Voltage voltage_array[MAX_ELEMENTS];

// Define node structure
typedef struct node_struct {
    int id;
    int num_incidents;
    int incidents[MAX_ELEMENTS];
} Node;

Node node_array[MAX_NODES];

// Get node index
int get_node_index(int id) {
    int i;
    for (i = 0; i < node_count; i++) {
        if (node_array[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Add resistor to array
void add_resistor(char name[], int node1, int node2, float value) {
    strcpy(res_array[res_count].name, name);
    res_array[res_count].node1 = node1;
    res_array[res_count].node2 = node2;
    res_array[res_count].value = value;
    res_count++;
}

// Add voltage source to array
void add_voltage(char name[], int node1, int node2, float value) {
    strcpy(voltage_array[voltage_count].name, name);
    voltage_array[voltage_count].node1 = node1;
    voltage_array[voltage_count].node2 = node2;
    voltage_array[voltage_count].value = value;
    voltage_count++;
}

// Add incident element
void add_incident(int node_idx, int elem_idx) {
    node_array[node_idx].incidents[node_array[node_idx].num_incidents] = elem_idx;
    node_array[node_idx].num_incidents++;
}

// Construct node array and calculate number of nodes
void create_node_array() {
    int i, j, node_idx;

    for (i = 0; i < MAX_NODES; i++) {
        node_array[i].id = -1;
        node_array[i].num_incidents = 0;
        for (j = 0; j < MAX_ELEMENTS; j++) {
            node_array[i].incidents[j] = -1;
        }
    }

    for (i = 0; i < res_count; i++) {
        // Add nodes to node_array
        node_idx = get_node_index(res_array[i].node1);
        if (node_idx == -1) {
            node_array[node_count].id = res_array[i].node1;
            add_incident(node_count, i);
            node_count++;
        } else {
            add_incident(node_idx, i);
        }

        node_idx = get_node_index(res_array[i].node2);
        if (node_idx == -1) {
            node_array[node_count].id = res_array[i].node2;
            add_incident(node_count, i);
            node_count++;
        } else {
            add_incident(node_idx, i);
        }
    }

    for (i = 0; i < voltage_count; i++) {
        // Add nodes to node_array
        node_idx = get_node_index(voltage_array[i].node1);
        if (node_idx == -1) {
            node_array[node_count].id = voltage_array[i].node1;
            add_incident(node_count, i);
            node_count++;
        } else {
            add_incident(node_idx, i);
        }

        node_idx = get_node_index(voltage_array[i].node2);
        if (node_idx == -1) {
            node_array[node_count].id = voltage_array[i].node2;
            add_incident(node_count, i);
            node_count++;
        } else {
            add_incident(node_idx, i);
        }
    }
}

// Display circuit information
void display_circuit() {
    int i, j;

    printf("Resistors:\n");
    for (i = 0; i < res_count; i++) {
        printf("%s: Nodes(%d, %d) Value: %f\n", res_array[i].name, res_array[i].node1, res_array[i].node2, res_array[i].value);
    }

    printf("Voltage Sources:\n");
    for (i = 0; i < voltage_count; i++) {
        printf("%s: Nodes(%d, %d) Value: %f\n", voltage_array[i].name, voltage_array[i].node1, voltage_array[i].node2, voltage_array[i].value);
    }

    printf("Nodes:\n");
    for (i = 0; i < node_count; i++) {
        printf("Node %d Incidents: ", node_array[i].id);
        for (j = 0; j < node_array[i].num_incidents; j++) {
            printf("%d ", node_array[i].incidents[j]);
        }
        printf("\n");
    }
}

int main() {
    add_resistor("R1", 1, 2, 1000);
    add_resistor("R2", 2, 3, 2000);
    add_resistor("R3", 3, 1, 3000);
    add_voltage("V1", 1, 3, 5);
    create_node_array();
    display_circuit();
    return 0;
}