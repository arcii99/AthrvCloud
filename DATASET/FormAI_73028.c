//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 100     // Maximum number of nodes
#define MAX_ELEMENT 200  // Maximum number of elements

// Element details storing structure
typedef struct element_tag {
    char type;
    int node1, node2;
    double value;
} element_t;

int num_nodes;  // Number of nodes in the circuit
int num_elements;  // Number of elements in the circuits
element_t elements[MAX_ELEMENT];  // Array to store all the elements

// Function to initialize circuit variables
void initialize() {
    num_nodes = 0;
    num_elements = 0;
}

// Function to add an element to the circuit
void add_element(char type, int node1, int node2, double value) {
    elements[num_elements].type = type;
    elements[num_elements].node1 = node1;
    elements[num_elements].node2 = node2;
    elements[num_elements].value = value;
    num_elements++;
}

// Function to display all elements in the circuit
void display_circuit() {
    printf("Number of nodes: %d\n", num_nodes);
    printf("Number of elements: %d\n", num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("Element %d: Type: %c, Node1: %d, Node2: %d, Value: %lf\n",
               i + 1, elements[i].type, elements[i].node1, elements[i].node2, elements[i].value);
    }
}

// Main function to run the circuit simulator
int main() {
    printf("Welcome to the Classical Circuit Simulator! \n\n");
    printf("Let's create a circuit!\n");

    initialize();

    // Add elements to the circuit using function
    add_element('R', 1, 2, 10.0);
    add_element('C', 2, 3, 0.1);
    add_element('L', 3, 1, 0.01);

    display_circuit();

    printf("\nThanks for using the Classical Circuit Simulator!\n");
    return 0;
}