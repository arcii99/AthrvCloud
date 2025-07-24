//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50

struct Node {
    int id;
    char label;
    int x, y;
} nodes[MAX_NODES];

int num_nodes = 0;

int is_node_present(int id) {
    for (int i = 0; i < num_nodes; i++) {
        if (nodes[i].id == id) {
            return 1;
        }
    }
    return 0;
}

void add_node(int id, char label, int x, int y) {
    if (is_node_present(id)) {
        printf("Node with ID %d already exists!\n", id);
        return;
    }
    nodes[num_nodes].id = id;
    nodes[num_nodes].label = label;
    nodes[num_nodes].x = x;
    nodes[num_nodes].y = y;
    num_nodes++;
}

void print_nodes() {
    printf("Nodes:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d (%c) at (%d,%d)\n", nodes[i].id, nodes[i].label, nodes[i].x, nodes[i].y);
    }
}

struct Link {
    int start_node_id;
    int end_node_id;
    int weight;
} links[MAX_NODES * (MAX_NODES - 1)];

int num_links = 0;

int is_link_present(int start_node_id, int end_node_id) {
    for (int i = 0; i < num_links; i++) {
        if (links[i].start_node_id == start_node_id && links[i].end_node_id == end_node_id) {
            return 1;
        }
    }
    return 0;
}

void add_link(int start_node_id, int end_node_id, int weight) {
    if (!is_node_present(start_node_id)) {
        printf("Node with ID %d does not exist!\n", start_node_id);
        return;
    }
    if (!is_node_present(end_node_id)) {
        printf("Node with ID %d does not exist!\n", end_node_id);
        return;
    }
    if (is_link_present(start_node_id, end_node_id)) {
        printf("Link from %d to %d already exists!\n", start_node_id, end_node_id);
        return;
    }
    links[num_links].start_node_id = start_node_id;
    links[num_links].end_node_id = end_node_id;
    links[num_links].weight = weight;
    num_links++;
}

void print_links() {
    printf("Links:\n");
    for (int i = 0; i < num_links; i++) {
        printf("%d -> %d (%d)\n", links[i].start_node_id, links[i].end_node_id, links[i].weight);
    }
}

int main() {
    add_node(1, 'A', 0, 0);
    add_node(2, 'B', 100, 0);
    add_node(3, 'C', 50, 100);
    add_node(4, 'D', -50, 100);

    add_link(1, 2, 50);
    add_link(2, 3, 30);
    add_link(3, 4, 40);
    add_link(4, 1, 25);

    print_nodes();
    print_links();

    return EXIT_SUCCESS;
}