//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[20];
    int num_next_nodes;
    int num_prev_nodes;
    struct Node** next_nodes;
    struct Node** prev_nodes;
    int visited;
} Node;

typedef struct Graph {
    int num_nodes;
    Node** nodes;
} Graph;

// Function to create a new node
Node* createNode(char* name) {
    Node* new_node = malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->num_next_nodes = 0;
    new_node->num_prev_nodes = 0;
    new_node->next_nodes = NULL;
    new_node->prev_nodes = NULL;
    new_node->visited = 0;
    return new_node;
}

// Function to create a new graph
Graph* createGraph(int num_nodes) {
    Graph* new_graph = malloc(sizeof(Graph));
    new_graph->num_nodes = num_nodes;
    new_graph->nodes = malloc(num_nodes * sizeof(Node*));
    for (int i = 0; i < num_nodes; i++) {
        new_graph->nodes[i] = NULL;
    }
    return new_graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, char* source, char* dest) {
    Node* source_node = NULL;
    Node* dest_node = NULL;
    for (int i = 0; i < graph->num_nodes; i++) {
        if (strcmp(graph->nodes[i]->name, source) == 0) {
            source_node = graph->nodes[i];
        }
        if (strcmp(graph->nodes[i]->name, dest) == 0) {
            dest_node = graph->nodes[i];
        }
    }
    if (source_node == NULL) {
        source_node = createNode(source);
        graph->nodes[graph->num_nodes++] = source_node;
    }
    if (dest_node == NULL) {
        dest_node = createNode(dest);
        graph->nodes[graph->num_nodes++] = dest_node;
    }
    source_node->next_nodes = realloc(source_node->next_nodes, (source_node->num_next_nodes + 1) * sizeof(Node*));
    source_node->next_nodes[source_node->num_next_nodes++] = dest_node;
    dest_node->prev_nodes = realloc(dest_node->prev_nodes, (dest_node->num_prev_nodes + 1) * sizeof(Node*));
    dest_node->prev_nodes[dest_node->num_prev_nodes++] = source_node;
}

// Function to map and display the network topology
void mapTopology(Graph* graph) {
    printf("Network Topology Map:\n");
    for (int i = 0; i < graph->num_nodes; i++) {
        if (graph->nodes[i]->visited == 0) {
            Node* current_node = graph->nodes[i];
            printf("%s -> ", current_node->name);
            current_node->visited = 1;
            while (current_node->num_next_nodes > 0) {
                current_node = current_node->next_nodes[0];
                printf("%s -> ", current_node->name);
                current_node->visited = 1;
            }
            printf("NULL\n");
        }
    }
}

// Main function
int main() {
    // Initialize the graph
    Graph* graph = createGraph(0);

    // Add some edges to the graph
    addEdge(graph, "Router 1", "Switch 1");
    addEdge(graph, "Switch 1", "PC 1");
    addEdge(graph, "Switch 1", "PC 2");
    addEdge(graph, "Switch 1", "Printer 1");
    addEdge(graph, "Router 1", "Switch 2");
    addEdge(graph, "Switch 2", "PC 3");
    addEdge(graph, "Switch 2", "PC 4");
    addEdge(graph, "Switch 2", "Printer 2");

    // Map and display the network topology
    mapTopology(graph);

    // Free memory
    for (int i = 0; i < graph->num_nodes; i++) {
        free(graph->nodes[i]->next_nodes);
        free(graph->nodes[i]->prev_nodes);
        free(graph->nodes[i]);
    }
    free(graph->nodes);
    free(graph);

    return 0;
}