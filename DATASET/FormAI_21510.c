//FormAI DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Struct to represent a node in the graph
struct Node {
    int value;
    int num_neighbors;
    struct Node** neighbors;
};

// Function to create a new node in the graph
struct Node* create_node(int value, int num_neighbors) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->num_neighbors = num_neighbors;
    new_node->neighbors = malloc(sizeof(struct Node*) * num_neighbors);
    return new_node;
}

// Function to add a neighbor to a node in the graph
void add_neighbor(struct Node* node, struct Node* neighbor) {
    node->neighbors[node->num_neighbors] = neighbor;
    node->num_neighbors++;
}

// Function to print the graph
void print_graph(struct Node* start_node) {
    // Keep track of visited nodes to avoid infinite loop
    int* visited = calloc(100, sizeof(int));  
    printf("Graph:\n");
    printf("------\n");
    printf("%d ", start_node->value);
    visited[start_node->value] = 1;
    for (int i = 0; i < start_node->num_neighbors; i++) {
        printf("-> %d ", start_node->neighbors[i]->value);
    }
    printf("\n");
    for (int i = 0; i < start_node->num_neighbors; i++) {
        traverse(start_node->neighbors[i], visited);
    }
    printf("\n");
}

// Function to traverse the graph depth first
void traverse(struct Node* start_node, int* visited) {
    if (visited[start_node->value] == 1) {
        return;
    }
    visited[start_node->value] = 1;
    printf("%d ", start_node->value);
    for (int i = 0; i < start_node->num_neighbors; i++) {
        traverse(start_node->neighbors[i], visited);
    }
}

int main() {
    // Create the nodes
    struct Node* node_1 = create_node(1, 3);
    struct Node* node_2 = create_node(2, 2);
    struct Node* node_3 = create_node(3, 1);
    struct Node* node_4 = create_node(4, 1);

    // Add neighbors
    add_neighbor(node_1, node_2);
    add_neighbor(node_1, node_3);
    add_neighbor(node_1, node_4);
    add_neighbor(node_2, node_4);
    add_neighbor(node_2, node_1);
    add_neighbor(node_3, node_2);
    add_neighbor(node_4, node_3);

    // Traverse and print the graph
    traverse(node_1, calloc(100, sizeof(int)));
    printf("\n");
    print_graph(node_1);

    return 0;
}