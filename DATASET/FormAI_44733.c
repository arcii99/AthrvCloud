//FormAI DATASET v1.0 Category: Graph representation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
    int vertex;
    struct _node* next;
}node;

typedef struct _graph {
    int V;
    node** adj_list;
}graph;

node* create_node(int vertex) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->vertex = vertex;
    new_node->next = NULL;
    return new_node;
}

graph* create_graph(int V) {
    graph* new_graph = (graph*) malloc(sizeof(graph));
    new_graph->V = V;
    new_graph->adj_list = (node**) malloc(sizeof(node*) * V);

    for(int i = 0; i < V; i++) {
        new_graph->adj_list[i] = NULL;
    }
    return new_graph;
}

void add_edge(graph* g, int s, int d) {
    node* new_node = create_node(d);
    new_node->next = g->adj_list[s];
    g->adj_list[s] = new_node;

    new_node = create_node(s);
    new_node->next = g->adj_list[d];
    g->adj_list[d] = new_node;
}

void print_graph(graph* g) {
    for(int i = 0; i < g->V; i++) {
        node* curr = g->adj_list[i];
        printf("Adjacency list for vertex %d: head", i);
        while(curr != NULL) {
            printf(" -> %d", curr->vertex);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    graph* g = create_graph(5);

    add_edge(g, 0, 1); 
    add_edge(g, 0, 4); 
    add_edge(g, 1, 2); 
    add_edge(g, 1, 3); 
    add_edge(g, 1, 4); 
    add_edge(g, 2, 3); 
    add_edge(g, 3, 4); 
  
    print_graph(g);

    return 0;
}