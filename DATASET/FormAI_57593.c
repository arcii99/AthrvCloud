//FormAI DATASET v1.0 Category: Graph representation ; Style: complete
#include <stdio.h>

#define MAX_VERTICES 10

// adjacency list node struct
struct adj_list_node {
    int dest;
    struct adj_list_node* next;
};

// adjacency list struct
struct adj_list {
    struct adj_list_node* head;
};

// graph struct
struct graph {
    int num_vertices;
    struct adj_list* adj_list_arr;
};

// create adjacency list node
struct adj_list_node* create_adj_list_node(int dest) {
    struct adj_list_node* new_node = (struct adj_list_node*)malloc(sizeof(struct adj_list_node));
    new_node->dest = dest;
    new_node->next = NULL;
    return new_node;
}

// create graph
struct graph* create_graph(int num_vertices) {
    struct graph* new_graph = (struct graph*)malloc(sizeof(struct graph));
    new_graph->num_vertices = num_vertices;
    
    new_graph->adj_list_arr = (struct adj_list*)malloc(num_vertices * sizeof(struct adj_list));
    
    int i;
    for(i = 0; i < num_vertices; i++) {
        new_graph->adj_list_arr[i].head = NULL;
    }
    
    return new_graph;
}

// add edge to graph
void add_edge(struct graph* graph, int src, int dest) {
    struct adj_list_node* new_node = create_adj_list_node(dest);
    new_node->next = graph->adj_list_arr[src].head;
    graph->adj_list_arr[src].head = new_node;
    
    new_node = create_adj_list_node(src);
    new_node->next = graph->adj_list_arr[dest].head;
    graph->adj_list_arr[dest].head = new_node;
}

// print graph
void print_graph(struct graph* graph) {
    int i;
    for(i = 0; i < graph->num_vertices; i++) {
        struct adj_list_node* curr = graph->adj_list_arr[i].head;
        printf("%d: ", i);
        while(curr != NULL) {
            printf("%d ", curr->dest);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    struct graph* graph = create_graph(MAX_VERTICES);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    print_graph(graph);
    return 0;
}