//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100 // maximum number of circuit nodes
#define MAX_ELEMENTS 200 // maximum number of circuit elements

typedef struct element {
    char type; // 'R', 'C', or 'L' for resistance, capacitance, or inductance, respectively
    double value; // the value of the element
    int node1; // first circuit node the element is connected to
    int node2; // second circuit node the element is connected to
} Element;

int num_nodes = 0; // number of circuit nodes
int num_elements = 0; // number of circuit elements
int node_list[MAX_NODES]; // list of circuit nodes
Element element_list[MAX_ELEMENTS]; // list of circuit elements

void add_node(int node) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (node_list[i] == node) {
            return; // node already exists in the list
        }
    }
    node_list[num_nodes++] = node; // add node to the list
}

void add_element(Element element) {
    element_list[num_elements++] = element; // add element to the list
    add_node(element.node1);
    add_node(element.node2);
}

int get_node_index(int node) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (node_list[i] == node) {
            return i; // return index of node in the node list
        }
    }
    return -1; // node not found
}

void print_nodes() {
    int i;
    printf("Nodes: ");
    for (i = 0; i < num_nodes; i++) {
        printf("%d ", node_list[i]);
    }
    printf("\n");
}

void print_elements() {
    int i;
    printf("Elements: \n");
    for (i = 0; i < num_elements; i++) {
        printf("%c %lf %d %d\n", element_list[i].type, element_list[i].value, element_list[i].node1, element_list[i].node2);
    }
}

int main() {
    // define circuit elements
    Element resistor;
    resistor.type = 'R';
    resistor.value = 1000.0;
    resistor.node1 = 1;
    resistor.node2 = 2;
    
    Element capacitor;
    capacitor.type = 'C';
    capacitor.value = 1.0e-6;
    capacitor.node1 = 2;
    capacitor.node2 = 0;
    
    Element inductor;
    inductor.type = 'L';
    inductor.value = 0.1;
    inductor.node1 = 2;
    inductor.node2 = 3;
    
    // add elements to the circuit
    add_element(resistor);
    add_element(capacitor);
    add_element(inductor);
    
    // print nodes and elements
    print_nodes();
    print_elements();
    
    return 0;
}