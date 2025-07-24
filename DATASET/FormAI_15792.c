//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: configurable
#include <stdio.h>
#include <math.h>

#define MAX_NODES 20
#define MAX_ELEMENTS 20

/* Node structure */
typedef struct {
    int num;
    double voltage;
} NODE;

/* Resistor structure */
typedef struct {
    char name[10];
    int node1;
    int node2;
    double value;
} RESISTOR;

/* Voltage source structure */
typedef struct {
    char name[10];
    int node1;
    int node2;
    double voltage;
} VOLTAGE_SOURCE;

/* Capacitor structure */
typedef struct {
    char name[10];
    int node1;
    int node2;
    double capacitance;
    double voltage;
    double current;
} CAPACITOR;

/* Global variables */
NODE nodes[MAX_NODES];                          // Node array
RESISTOR resistors[MAX_ELEMENTS];               // Resistor array
VOLTAGE_SOURCE voltage_sources[MAX_ELEMENTS];   // Voltage source array
CAPACITOR capacitors[MAX_ELEMENTS];             // Capacitor array
int num_nodes = 0;                              // Number of nodes
int num_resistors = 0;                          // Number of resistors
int num_voltage_sources = 0;                    // Number of voltage sources
int num_capacitors = 0;                         // Number of capacitors

/* Function to add a node to the node array */
void add_node(int n) {
    int i;
    for(i=0; i<num_nodes; i++) {
        if(nodes[i].num == n) {
            return;
        }
    }
    nodes[num_nodes].num = n;
    nodes[num_nodes].voltage = 0.0;
    num_nodes++;
}

/* Function to add a resistor to the resistor array */
void add_resistor(char* name, int n1, int n2, double val) {
    resistors[num_resistors].node1 = n1;
    resistors[num_resistors].node2 = n2;
    resistors[num_resistors].value = val;
    strcpy(resistors[num_resistors].name, name);
    num_resistors++;
}

/* Function to add a voltage source to the voltage source array */
void add_voltage_source(char* name, int n1, int n2, double volt) {
    voltage_sources[num_voltage_sources].node1 = n1;
    voltage_sources[num_voltage_sources].node2 = n2;
    voltage_sources[num_voltage_sources].voltage = volt;
    strcpy(voltage_sources[num_voltage_sources].name, name);
    num_voltage_sources++;
}

/* Function to add a capacitor to the capacitor array */
void add_capacitor(char* name, int n1, int n2, double cap) {
    capacitors[num_capacitors].node1 = n1;
    capacitors[num_capacitors].node2 = n2;
    capacitors[num_capacitors].capacitance = cap;
    capacitors[num_capacitors].voltage = 0.0;
    capacitors[num_capacitors].current = 0.0;
    strcpy(capacitors[num_capacitors].name, name);
    num_capacitors++;
}

/* Function to print the circuit */
void print_circuit() {
    int i;
    printf("Circuit:\n");
    printf("Nodes: ");
    for(i=0; i<num_nodes; i++) {
        printf("%d ", nodes[i].num);
    }
    printf("\nResistors: %d\n", num_resistors);
    for(i=0; i<num_resistors; i++) {
        printf("%s - Node1: %d, Node2: %d, Value: %lf\n", resistors[i].name, resistors[i].node1, resistors[i].node2, resistors[i].value);
    }
    printf("Voltage Sources: %d\n", num_voltage_sources);
    for(i=0; i<num_voltage_sources; i++) {
        printf("%s - Node1: %d, Node2: %d, Voltage: %lf\n", voltage_sources[i].name, voltage_sources[i].node1, voltage_sources[i].node2, voltage_sources[i].voltage);
    }
    printf("Capacitors: %d\n", num_capacitors);
    for(i=0; i<num_capacitors; i++) {
        printf("%s - Node1: %d, Node2: %d, Capacitance: %lf, Voltage: %lf, Current: %lf\n", capacitors[i].name, capacitors[i].node1, capacitors[i].node2, capacitors[i].capacitance, capacitors[i].voltage, capacitors[i].current);
    }
}

int main() {
    add_node(1);
    add_node(2);
    add_node(3);
    add_resistor("R1", 1, 2, 1000);
    add_voltage_source("V1", 2, 3, 5);
    add_capacitor("C1", 2, 3, 1e-6);
    print_circuit();
    return 0;
}