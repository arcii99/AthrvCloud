//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define ERROR_TOLERANCE 1e-6

typedef struct {
    int src, dest;
    double value;
} Edge;

typedef struct {
    int source_id, num_out_edges;
    Edge out_edges[MAX_EDGES];
    double node_voltage, node_previous_voltage, node_charge;
} Node;

Node nodes[MAX_NODES];
int num_nodes = 0, num_edges = 0;

double get_total_charge() {
    double total_charge = 0.0;
    for (int i = 0; i < num_nodes; ++i) {
        total_charge += nodes[i].node_charge;
    }
    return total_charge;
}

int node_is_connected(int id) {
    return nodes[id].num_out_edges > 0;
}

void simulate(double time_step, double end_time) {
    double current_time = 0.0;
    while (current_time < end_time) {
        double total_charge = get_total_charge();
        for (int i = 0; i < num_nodes; ++i) {
            Node* node = &nodes[i];
            if (node_is_connected(i)) {
                double node_conductance = 0.0;
                for (int j = 0; j < node->num_out_edges; ++j) {
                    int dest_id = node->out_edges[j].dest;
                    Node* dest_node = &nodes[dest_id];
                    node_conductance += node->out_edges[j].value;
                    node_conductance += (dest_node->node_previous_voltage - node->node_previous_voltage) / node->out_edges[j].value;
                }
                node_conductance = 1.0 / node_conductance;
                double node_current = (node->node_charge - total_charge / num_nodes) * node_conductance;
                node->node_voltage = node->node_previous_voltage + time_step * node_current;
                node->node_previous_voltage = node->node_voltage;
                node->node_charge -= time_step * node_current;
            }
        }
        current_time += time_step;
    }
}

void add_edge(int source_id, int dest_id, double value) {
    nodes[source_id].out_edges[nodes[source_id].num_out_edges].src = source_id;
    nodes[source_id].out_edges[nodes[source_id].num_out_edges].dest = dest_id;
    nodes[source_id].out_edges[nodes[source_id].num_out_edges].value = value;
    nodes[source_id].num_out_edges++;
}

void add_node() {
    nodes[num_nodes].source_id = num_nodes;
    nodes[num_nodes].num_out_edges = 0;
    nodes[num_nodes].node_voltage = 0.0;
    nodes[num_nodes].node_previous_voltage = 0.0;
    nodes[num_nodes].node_charge = 0.0;
    num_nodes++;
}

void print_result() {
    for (int i = 0; i < num_nodes; ++i) {
        printf("Node %d: %.2lfV\n", i, nodes[i].node_voltage);
    }
}

int main() {
    // Create the circuit
    add_node();
    add_node();
    add_edge(0, 1, 1.0);
    add_edge(1, 0, 1.0);
    add_edge(0, 0, 2.0);
    add_edge(1, 1, 4.0);

    // Simulate the circuit
    double time_step = 0.0001;
    double end_time = 0.05;
    simulate(time_step, end_time);

    // Print the result
    print_result();

    return 0;
}