//FormAI DATASET v1.0 Category: Graph representation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Maximum number of vertices that can be used in the graph
#define MAX_VERTICES 100

// Structure to store information for each vertex
struct Vertex {
    int id;
    int edges[MAX_VERTICES]; // list of edges connected to the vertex
    int edge_count; // number of edges
    bool visited; // flag to track if vertex has been visited
};

// Create a graph using an adjacency list representation
struct Graph {
    struct Vertex vertices[MAX_VERTICES]; // array of vertices
    int vertex_count; // number of vertices
};

// Function to add a vertex to the graph
void add_vertex(struct Graph* graph, int id) {
    if (graph->vertex_count == MAX_VERTICES) {
        printf("Graph has reached maximum capacity!\n");
        return;
    }
    
    // Check if vertex with same ID already exists
    for (int i = 0; i < graph->vertex_count; i++) {
        if (graph->vertices[i].id == id) {
            printf("Vertex with ID %d already exists!\n", id);
            return;
        }
    }
    
    struct Vertex new_vertex;
    new_vertex.id = id;
    new_vertex.edge_count = 0;
    new_vertex.visited = false;
    graph->vertices[graph->vertex_count] = new_vertex;
    graph->vertex_count++;
}

// Function to add an edge between two vertices in the graph
void add_edge(struct Graph* graph, int id1, int id2) {
    // Find vertices with given IDs
    struct Vertex* vertex1 = NULL;
    struct Vertex* vertex2 = NULL;
    for (int i = 0; i < graph->vertex_count; i++) {
        if (graph->vertices[i].id == id1) {
            vertex1 = &graph->vertices[i];
        }
        else if (graph->vertices[i].id == id2) {
            vertex2 = &graph->vertices[i];
        }
    }
    // Check if vertices exist
    if (vertex1 == NULL || vertex2 == NULL) {
        printf("One or both vertices not found!\n");
        return;
    }
    // Check if edge already exists
    for (int i = 0; i < vertex1->edge_count; i++) {
        if (vertex1->edges[i] == id2) {
            printf("Edge already exists!\n");
            return;
        }
    }
    // Add edges to both vertices
    vertex1->edges[vertex1->edge_count] = id2;
    vertex1->edge_count++;
    vertex2->edges[vertex2->edge_count] = id1;
    vertex2->edge_count++;
}

// Function to print the graph
void print_graph(struct Graph graph) {
    printf("Vertices:\n");
    for (int i = 0; i < graph.vertex_count; i++) {
        printf("%d ", graph.vertices[i].id);
    }
    printf("\nEdges:\n");
    for (int i = 0; i < graph.vertex_count; i++) {
        printf("%d: ", graph.vertices[i].id);
        for (int j = 0; j < graph.vertices[i].edge_count; j++) {
            printf("%d ", graph.vertices[i].edges[j]);
        }
        printf("\n");
    }
}

// Function to traverse the graph using DFS
void DFS(struct Graph* graph, struct Vertex* vertex) {
    // Mark vertex as visited
    vertex->visited = true;
    printf("%d ", vertex->id);
    // Traverse unvisited connected vertices recursively
    for (int i = 0; i < vertex->edge_count; i++) {
        struct Vertex* connected_vertex = NULL;
        for (int j = 0; j < graph->vertex_count; j++) {
            if (graph->vertices[j].id == vertex->edges[i]) {
                connected_vertex = &graph->vertices[j];
                break;
            }
        }
        if (connected_vertex != NULL && !connected_vertex->visited) {
            DFS(graph, connected_vertex);
        }
    }
}

int main() {
    struct Graph graph;
    graph.vertex_count = 0;
    printf("Adding vertices...\n");
    add_vertex(&graph, 1);
    add_vertex(&graph, 2);
    add_vertex(&graph, 3);
    add_vertex(&graph, 4);
    add_vertex(&graph, 5);
    printf("Adding edges...\n");
    add_edge(&graph, 1, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 2, 4);
    add_edge(&graph, 3, 4);
    add_edge(&graph, 4, 5);
    printf("Printing graph...\n");
    print_graph(graph);
    printf("Traversing graph using DFS starting from vertex 1...\n");
    struct Vertex* start_vertex = NULL;
    for (int i = 0; i < graph.vertex_count; i++) {
        if (graph.vertices[i].id == 1) {
            start_vertex = &graph.vertices[i];
            break;
        }
    }
    DFS(&graph, start_vertex);
    printf("\n");
    return 0;
}