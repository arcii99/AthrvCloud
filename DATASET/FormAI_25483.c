//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 20
#define MAX_PATH 100

/* circuit node structure */
struct CircuitNode {
    int id;
    int connected_nodes[MAX_NODES];
    int num_connections;
};

/* circuit structure containing all nodes */
struct Circuit {
    int num_nodes;
    struct CircuitNode nodes[MAX_NODES];
};

/* function to add a new connection between two nodes */
void add_connection(struct Circuit* circuit, int node1, int node2) {
    /* check if connection already exists */
    int i;
    for (i=0; i<circuit->nodes[node1].num_connections; i++) {
        if (circuit->nodes[node1].connected_nodes[i] == node2) {
            printf("ERROR: Connection between nodes %d and %d already exists\n", node1, node2);
            return;
        }
    }
    /* add connection to node 1 */
    circuit->nodes[node1].connected_nodes[circuit->nodes[node1].num_connections] = node2;
    circuit->nodes[node1].num_connections += 1;
    /* add connection to node 2 */
    circuit->nodes[node2].connected_nodes[circuit->nodes[node2].num_connections] = node1;
    circuit->nodes[node2].num_connections += 1;
}

/* function to remove a connection between two nodes */
void remove_connection(struct Circuit* circuit, int node1, int node2) {
    /* find index of connection in node 1 */
    int i;
    int index1 = -1;
    for (i=0; i<circuit->nodes[node1].num_connections; i++) {
        if (circuit->nodes[node1].connected_nodes[i] == node2) {
            index1 = i;
            break;
        }
    }
    /* find index of connection in node 2 */
    int index2 = -1;
    for (i=0; i<circuit->nodes[node2].num_connections; i++) {
        if (circuit->nodes[node2].connected_nodes[i] == node1) {
            index2 = i;
            break;
        }
    }
    /* check if connection exists */
    if (index1 == -1 || index2 == -1) {
        printf("ERROR: Connection between nodes %d and %d does not exist\n", node1, node2);
        return;
    }
    /* remove connection from node 1 */
    int j;
    for (j=index1; j<circuit->nodes[node1].num_connections-1; j++) {
        circuit->nodes[node1].connected_nodes[j] = circuit->nodes[node1].connected_nodes[j+1];
    }
    circuit->nodes[node1].num_connections -= 1;
    /* remove connection from node 2 */
    for (j=index2; j<circuit->nodes[node2].num_connections-1; j++) {
        circuit->nodes[node2].connected_nodes[j] = circuit->nodes[node2].connected_nodes[j+1];
    }
    circuit->nodes[node2].num_connections -= 1;
}

/* function to check if two nodes are connected */
int are_connected(struct Circuit* circuit, int node1, int node2, int visited_nodes[]) {
    /* check if nodes are already connected */
    int i;
    for (i=0; i<circuit->nodes[node1].num_connections; i++) {
        if (circuit->nodes[node1].connected_nodes[i] == node2) {
            return 1;
        }
    }
    /* check if nodes are directly or indirectly connected */
    visited_nodes[node1] = 1;
    for (i=0; i<circuit->nodes[node1].num_connections; i++) {
        int connected_node = circuit->nodes[node1].connected_nodes[i];
        if (!visited_nodes[connected_node]) {
            if (are_connected(circuit, connected_node, node2, visited_nodes)) {
                return 1;
            }
        }
    }
    return 0;
}

/* main function */
int main() {
    struct Circuit circuit;
    circuit.num_nodes = 5;
    circuit.nodes[0].id = 0;
    circuit.nodes[0].num_connections = 0;
    circuit.nodes[1].id = 1;
    circuit.nodes[1].num_connections = 0;
    circuit.nodes[2].id = 2;
    circuit.nodes[2].num_connections = 0;
    circuit.nodes[3].id = 3;
    circuit.nodes[3].num_connections = 0;
    circuit.nodes[4].id = 4;
    circuit.nodes[4].num_connections = 0;

    add_connection(&circuit, 0, 1);
    add_connection(&circuit, 0, 2);
    add_connection(&circuit, 1, 2);
    add_connection(&circuit, 2, 3);
    add_connection(&circuit, 3, 4);

    int visited_nodes[MAX_NODES] = {0};
    printf("Nodes 0 and 4 are%s connected\n", are_connected(&circuit, 0, 4, visited_nodes) ? "" : " not");
    printf("Nodes 1 and 4 are%s connected\n", are_connected(&circuit, 1, 4, visited_nodes) ? "" : " not");

    remove_connection(&circuit, 0, 2);

    printf("Nodes 0 and 4 are%s connected\n", are_connected(&circuit, 0, 4, visited_nodes) ? "" : " not");
    printf("Nodes 1 and 4 are%s connected\n", are_connected(&circuit, 1, 4, visited_nodes) ? "" : " not");

    return 0;
}