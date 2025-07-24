//FormAI DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_VERTICES 100

// Node to store adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Represents the graph using adjacency list
typedef struct Graph {
    int num_vertices;
    Node* adj_list[MAX_VERTICES];
} Graph;

// Function to create a new node
Node* create_node(int vertex) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

// Function to add an edge to the graph
void add_edge(Graph* graph, int src, int dest) {
    Node* new_node = create_node(dest);
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;
}

// Function to print the graph
void print_graph(Graph* graph) {
    for(int i = 0; i < graph->num_vertices; i++) {
        Node* curr = graph->adj_list[i];
        printf("Adjacency list of vertex %d:\n", i);
        while(curr) {
            printf("%d -> ", curr->vertex);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

// Function to traverse the graph recursively
void dfs(Graph* graph, int curr_vertex, int* visited) {
    visited[curr_vertex] = 1;
    printf("%d ", curr_vertex);
    Node* curr = graph->adj_list[curr_vertex];
    while(curr) {
        int dest_vertex = curr->vertex;
        if(!visited[dest_vertex])
            dfs(graph, dest_vertex, visited);
        curr = curr->next;
    }
}

// Function executed by the worker thread
void* worker(void* args) {
    int vertex = *((int*) args);
    int visited[MAX_VERTICES] = {0};

    printf("Traversal starting from vertex %d: ", vertex);
    dfs((Graph*) args, vertex, visited);
    printf("\n");

    return NULL;
}

int main() {
    Graph graph;
    graph.num_vertices = 5;

    // Add edges to the graph
    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 2, 0);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 3);

    // Print the graph
    print_graph(&graph);

    // Create worker threads for all vertices
    pthread_t threads[graph.num_vertices];
    int vertices[graph.num_vertices];

    for(int i = 0; i < graph.num_vertices; i++)
        vertices[i] = i;

    for(int i = 0; i < graph.num_vertices; i++)
        pthread_create(&threads[i], NULL, worker, (void*) &graph);

    // Wait for all worker threads to finish
    for(int i = 0; i < graph.num_vertices; i++)
        pthread_join(threads[i], NULL);

    return 0;
}