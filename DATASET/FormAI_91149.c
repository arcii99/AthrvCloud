//FormAI DATASET v1.0 Category: Graph representation ; Style: Claude Shannon
//Claude Shannon style C Graph representation example program

#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX 10

// Graph structure
struct Graph{
    int vertex_count;
    int edge_count;
    int adj_matrix[MAX_VERTEX][MAX_VERTEX]; //Adjacency matrix to represent the graph
};

// Function to initialize the graph
void init_graph(struct Graph* graph){
    graph->vertex_count = 0;
    graph->edge_count = 0;
    for(int i=0; i<MAX_VERTEX; i++){
        for(int j=0; j<MAX_VERTEX; j++){
            graph->adj_matrix[i][j] = 0;
        }
    }
}

// Function to add vertex in the graph
void add_vertex(struct Graph* graph){
    if(graph->vertex_count < MAX_VERTEX){
        graph->vertex_count++;
        printf("Vertex added to the graph.\n");
    }
    else{
        printf("Cannot add more vertices to the graph.\n");
    }
}

// Function to add edge in the graph
void add_edge(struct Graph* graph, int src, int dest){
    if(src>=0 && src<graph->vertex_count && dest>=0 && dest<graph->vertex_count){
        graph->edge_count++;
        graph->adj_matrix[src][dest] = 1;
        graph->adj_matrix[dest][src] = 1; //Since its an undirected graph
        printf("Edge added to the graph.\n");
    }
    else{
        printf("Invalid source or destination vertex.\n");
    }
}

// Function to display the graph
void display_graph(struct Graph* graph){
    printf("Adjacency matrix of the graph:\n");
    for(int i=0; i<graph->vertex_count; i++){
        for(int j=0; j<graph->vertex_count; j++){
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main(){
    struct Graph graph;
    init_graph(&graph);
    add_vertex(&graph);
    add_vertex(&graph);
    add_vertex(&graph);
    add_vertex(&graph);
    add_vertex(&graph);
    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 2);
    add_edge(&graph, 1, 3);
    add_edge(&graph, 1, 4);
    add_edge(&graph, 2, 4);
    display_graph(&graph);
    return 0;
}