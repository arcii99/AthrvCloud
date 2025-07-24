//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 10
#define MAX_COMPONENTS 20

int node_list[MAX_COMPONENTS][2]; // each entry: start_node - end_node
int node_val[MAX_NODES];
int num_components;
int num_nodes;

void simulate(int step_size, float time);
void update_node_values(int step_size);
void print_nodes();

int main() {
    // initialize component values
    num_components = 3;
    node_list[0][0] = 0;
    node_list[0][1] = 1;
    node_list[1][0] = 1;
    node_list[1][1] = 2;
    node_list[2][0] = 2;
    node_list[2][1] = 0;
    
    // initialize node values
    num_nodes = 3;
    node_val[0] = 0;
    node_val[1] = 5;
    node_val[2] = 10;
    
    printf("Initial circuit state:\n");
    print_nodes();
    
    simulate(1, 10.0);
    printf("\nCircuit state after simulating for 10 seconds with step size of 1:\n");
    print_nodes();
    
    return 0;
}

void simulate(int step_size, float time) {
    int num_steps = time / step_size;
    
    for(int i = 0; i < num_steps; i++) {
        update_node_values(step_size);
    }
}

void update_node_values(int step_size) {
    int delta_vals[MAX_NODES];
    
    // calculate delta_value for each node
    for(int i = 0; i < num_nodes; i++) {
        delta_vals[i] = 0;
    }
    
    for(int i = 0; i < num_components; i++) {
        int start_node = node_list[i][0];
        int end_node = node_list[i][1];
        
        delta_vals[start_node] -= (node_val[start_node] - node_val[end_node]);
        delta_vals[end_node] += (node_val[start_node] - node_val[end_node]);
    }
    
    for(int i = 0; i < num_nodes; i++) {
        node_val[i] += step_size * delta_vals[i];
    }
}

void print_nodes() {
    for(int i = 0; i < num_nodes; i++) {
        printf("Node %d: %d\n", i, node_val[i]);
    }
}