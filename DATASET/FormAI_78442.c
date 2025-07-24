//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: paranoid
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10
#define MAX_COMPONENTS 20

int num_nodes = 0;
char node_names[MAX_NODES][3];

struct node {
    char name[3];
    float voltage;
};

struct component {
    char type;
    int node1;
    int node2;
    float value;
};

struct node nodes[MAX_NODES];
struct component components[MAX_COMPONENTS];

void initialize_nodes() {
    printf("Initializing nodes...\n");
    for (int i = 0; i < MAX_NODES; i++) {
        for (int j = 0; j < 3; j++) {
            nodes[i].name[j] = '\0';
        }
        nodes[i].voltage = 0.0;
    }
}

bool node_exists(char* node_name) {
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(node_names[i], node_name) == 0) {
            return true;
        }
    }
    return false;
}

void add_node(char* node_name) {
    if (node_exists(node_name)) {
        printf("Node already exists!\n");
        return;
    }
    if (num_nodes >= MAX_NODES) {
        printf("Cannot add more nodes! Maximum number of nodes reached.\n");
        return;
    }
    strcpy(node_names[num_nodes], node_name);
    strcpy(nodes[num_nodes].name, node_name);
    num_nodes++;
}

void print_nodes() {
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%s: %.2fV\n", nodes[i].name, nodes[i].voltage);
    }
}

void initialize_components() {
    printf("Initializing components...\n");
    for (int i = 0; i < MAX_COMPONENTS; i++) {
        components[i].type = '\0';
        components[i].node1 = -1;
        components[i].node2 = -1;
        components[i].value = 0.0;
    }
}

bool can_add_component() {
    int num_nodes_used = 0;
    for (int i = 0; i < MAX_COMPONENTS; i++) {
        if (components[i].type != '\0') {
            num_nodes_used++;
        }
    }
    return (num_nodes - num_nodes_used) >= 2;
}

void add_component(char comp_type, char* node1_name, char* node2_name, float comp_value) {
    if (!can_add_component()) {
        printf("Cannot add more components! Not enough nodes available.\n");
        return;
    }
    int node1_index = -1, node2_index = -1;
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, node1_name) == 0) {
            node1_index = i;
        }
        if (strcmp(nodes[i].name, node2_name) == 0) {
            node2_index = i;
        }
    }
    if (node1_index == -1 || node2_index == -1) {
        printf("One or more nodes does not exist!\n");
        return;
    }
    for (int i = 0; i < MAX_COMPONENTS; i++) {
        if (components[i].type == '\0') {
            components[i].type = comp_type;
            components[i].node1 = node1_index;
            components[i].node2 = node2_index;
            components[i].value = comp_value;
            nodes[node1_index].voltage += comp_value;
            nodes[node2_index].voltage -= comp_value;
            return;
        }
    }
    printf("Could not add component!\n");
}

void print_components() {
    printf("Components:\n");
    for (int i = 0; i < MAX_COMPONENTS; i++) {
        if (components[i].type != '\0') {
            printf("%c: %s - %s, Value: %.2f\n", components[i].type, nodes[components[i].node1].name, nodes[components[i].node2].name, components[i].value);
        }
    }
}

int main() {
    initialize_nodes();
    add_node("n1");
    add_node("n2");
    add_node("n3");
    add_node("n4");
    print_nodes();

    initialize_components();
    add_component('R', "n1", "n2", 100.0);
    add_component('R', "n2", "n3", 50.0);
    add_component('V', "n3", "n4", 5.0); // Add a voltage source
    print_nodes();
    print_components();

    return 0;
}