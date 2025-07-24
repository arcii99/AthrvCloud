//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODES 100

struct node {
    char *name;
    double value;
    int type;
};

struct element {
    int n1;
    int n2;
    double value;
    char *name;
    int type;
};

struct node nodes[MAX_NODES];
struct element elements[MAX_NODES];

int num_nodes = 0;
int num_elements = 0;

void add_node(char *name, double value, int type) {
    nodes[num_nodes].name = name;
    nodes[num_nodes].value = value;
    nodes[num_nodes].type = type;
    num_nodes++;
}

void add_element(int n1, int n2, double value, char *name, int type) {
    elements[num_elements].n1 = n1;
    elements[num_elements].n2 = n2;
    elements[num_elements].value = value;
    elements[num_elements].name = name;
    elements[num_elements].type = type;
    num_elements++;
}

void print_circuit() {
    printf("Circuit:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d - Name: %s, Value: %lf, Type: %d\n", i, nodes[i].name, nodes[i].value, nodes[i].type);
    }
    for (int i = 0; i < num_elements; i++) {
        printf("Element %d - Name: %s, Node 1: %d, Node 2: %d, Value: %lf, Type: %d\n", i, elements[i].name, elements[i].n1, elements[i].n2, elements[i].value, elements[i].type);
    }
}

int main() {
    add_node("GND", 0, 0);
    add_node("V1", 5, 1);
    add_element(0, 1, 0.001, "R1", 0);
    add_element(0, 1, 0.0001, "C1", 1);
    print_circuit();

    return 0;
}