//FormAI DATASET v1.0 Category: Graph representation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;                   // data of each node
    struct node *next;          // pointer to next node
};

struct Graph{
    int vertices;               // number of vertices in the graph
    struct node **adjacency_list;   // adjacency list for graph
};

// function prototypes
struct node* create_node(int value);
struct Graph* create_graph(int vertices);
void add_edge(struct Graph *graph, int source, int destination);
void print_graph(struct Graph *graph);

int main() {
    int vertices = 5;           // number of vertices in graph
    struct Graph *graph = create_graph(vertices);    // creating graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    print_graph(graph);         // printing graph
    return 0;
}

struct node* create_node(int value) {
    struct node *new_node = malloc(sizeof(struct node));   // allocating memory for new node
    new_node->data = value;                                 // setting data of new node to provided value
    new_node->next = NULL;                                  // setting next pointer to NULL
    return new_node;                                        // returning pointer to new node
}

struct Graph* create_graph(int vertices) {
    struct Graph *graph = malloc(sizeof(struct Graph));    // allocating memory for graph
    graph->vertices = vertices;                             // specifying number of vertices in graph
    graph->adjacency_list = malloc(vertices * sizeof(struct node*));    // allocating memory for adjacency list
    
    int i;
    for (i = 0; i < vertices; i++)
        graph->adjacency_list[i] = NULL;                   // setting every pointer in adjacency list to NULL
    
    return graph;                                           // returning pointer to graph
}

void add_edge(struct Graph *graph, int source, int destination) {
    struct node *new_node = create_node(destination);
    new_node->next = graph->adjacency_list[source];
    graph->adjacency_list[source] = new_node;               // adding new node to the beginning of source node's adjacency list
}

void print_graph(struct Graph *graph) {
    printf("Graph:\n");
    int i;
    for (i = 0; i < graph->vertices; i++) {
        struct node *current_node = graph->adjacency_list[i];
        printf("Vertex %d: ", i);
        while (current_node != NULL) {
            printf("%d -> ", current_node->data);
            current_node = current_node->next;
        }
        printf("NULL\n");
    }
}