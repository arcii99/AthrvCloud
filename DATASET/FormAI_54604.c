//FormAI DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdio.h> // Standard input/output library
#include <stdlib.h> // Standard library

// Structure for a node in the graph
typedef struct node {
    int vertex;
    struct node* next;
} Node;

// Structure for the Graph
typedef struct graph {
    int num_vertices;
    Node** adj_list; // Array of adjacency lists
} Graph;

// Function to create a new node with a given vertex number
Node* create_node(int vertex) {
    Node* new_node = malloc(sizeof(Node));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

// Function to create a graph with n vertices
Graph* create_graph(int num_vertices) {
    Graph* new_graph = malloc(sizeof(Graph));
    new_graph->num_vertices = num_vertices;

    // Allocate memory for array of adjacency lists
    new_graph->adj_list = malloc(sizeof(Node*) * num_vertices);

    // Initialize each adjacency list as empty by making it NULL
    for (int i = 0; i < num_vertices; i++) {
        new_graph->adj_list[i] = NULL;
    }

    return new_graph;
}

// Function to add an edge between two vertices
void add_edge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest. A new node is added to the adjacency list of src.
    Node* new_node = create_node(dest);
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;

    // Add an edge from dest to src as well (since the graph is undirected).
    new_node = create_node(src);
    new_node->next = graph->adj_list[dest];
    graph->adj_list[dest] = new_node;
}

// Function to print the adjacency list representation of the graph
void print_graph(Graph* graph) {
    printf("Graph:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        printf("%d: ", i);
        Node* temp = graph->adj_list[i];
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Graph* graph = create_graph(5); // Create a graph with 5 vertices

    // Add edges between vertices
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);

    // Print the graph
    print_graph(graph);

    return 0; // Return 0 indicating successful execution
}