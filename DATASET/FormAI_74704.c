//FormAI DATASET v1.0 Category: Graph representation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct node{
    int vertex;
    struct node* next;
}Node;

typedef struct graph{
    int num_vertices;
    Node** adj_list;
}Graph;

Node* create_node(int v){
    Node* new_node = malloc(sizeof(Node));
    new_node->vertex = v;
    new_node->next = NULL;

    return new_node;
}

Graph* create_graph(int n){
    Graph* new_graph = malloc(sizeof(Graph));
    new_graph-> num_vertices = n;

    new_graph-> adj_list = malloc(n * sizeof(Node*));

    for(int i=0; i<n; i++){
        new_graph-> adj_list[i] = NULL;
    }

    return new_graph;
}

void add_edge(Graph* graph, int s, int d){
    Node* new_node = create_node(d);
    new_node-> next = graph-> adj_list[s];
    graph-> adj_list[s] = new_node;

    new_node = create_node(s);
    new_node-> next = graph-> adj_list[d];
    graph-> adj_list[d] = new_node;
}

void print_graph(Graph* graph){
    int v;
    for(v=0; v<graph-> num_vertices; v++){
        Node* temp = graph-> adj_list[v];
        printf("\n Adjacency list of vertex %d\n", v);
        while(temp){
            printf("%d -> ", temp-> vertex);
            temp = temp-> next;
        }
        printf("NULL\n");
    }
}

int main(){
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