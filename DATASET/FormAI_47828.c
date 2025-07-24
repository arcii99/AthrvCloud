//FormAI DATASET v1.0 Category: Graph representation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct graph {
    int num_vertex;
    Node** adj_list;
} Graph;

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Graph* create_graph(int num_vertex) {
    Graph* new_graph = (Graph*)malloc(sizeof(Graph));
    new_graph->num_vertex = num_vertex;
    new_graph->adj_list = (Node**)malloc(num_vertex * sizeof(Node*));
    for(int i = 0; i < num_vertex; i++) {
        new_graph->adj_list[i] = NULL;
    }
    return new_graph;
}

void add_edge(Graph* graph, int src, int dest) {
    Node* new_node = create_node(dest);
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;
    
    new_node = create_node(src);
    new_node->next = graph->adj_list[dest];
    graph->adj_list[dest] = new_node;
}

void print_graph(Graph* graph) {
    for(int i = 0; i < graph->num_vertex; i++) {
        Node* current = graph->adj_list[i];
        printf("Vertex %d: ", i);
        while(current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    Graph* graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    print_graph(graph);
    return 0;
}