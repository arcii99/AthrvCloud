//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: authentic
#include<stdio.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 10

// Define the maximum number of colors available
#define MAX_COLORS 4

// Define a struct to represent the graph
typedef struct{
    int num_vertices;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
}Graph;

// Method declarations
void initialize_graph(Graph*);
void add_edge(Graph*, int, int);
void print_graph(Graph*);
void color_graph(Graph*, int*);

int main(){
    Graph g;
    initialize_graph(&g);
    add_edge(&g, 0, 1);
    add_edge(&g, 0, 2);
    add_edge(&g, 1, 2);
    add_edge(&g, 1, 3);
    add_edge(&g, 2, 3);
    printf("The original graph is: \n");
    print_graph(&g);
    int color_mapping[MAX_VERTICES] = {-1};
    color_graph(&g, color_mapping);
    printf("The graph after coloring is: \n");
    print_graph(&g);
    printf("The color mapping is: \n");
    for(int i = 0; i < g.num_vertices; i++){
        printf("Vertex %d is color %d\n", i, color_mapping[i]);
    }
    return 0;
}

// Method to initialize the graph
void initialize_graph(Graph* g){
    g->num_vertices = 0;
    for(int i = 0; i < MAX_VERTICES; i++){
        for(int j = 0; j < MAX_VERTICES; j++){
            g->adjacency_matrix[i][j] = 0;
        }
    }
}

// Method to add an edge to the graph
void add_edge(Graph* g, int u, int v){
    if(u >= 0 && u < MAX_VERTICES && v >= 0 && v < MAX_VERTICES){
        g->adjacency_matrix[u][v] = 1;
        g->adjacency_matrix[v][u] = 1;
        if(u > g->num_vertices){
            g->num_vertices = u + 1;
        }
        if(v > g->num_vertices){
            g->num_vertices = v + 1;
        }
    }
}

// Method to print the graph
void print_graph(Graph* g){
    for(int i = 0; i < g->num_vertices; i++){
        printf("Vertex %d: ", i);
        for(int j = 0; j < g->num_vertices; j++){
            if(g->adjacency_matrix[i][j] == 1){
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

// Method to color the graph
void color_graph(Graph* g, int* colors){
    for(int i = 0; i < g->num_vertices; i++){
        // Determine which colors are legal for this vertex 
        int legal_colors[MAX_COLORS] = {1};
        for(int j = 0; j < g->num_vertices; j++){
            if(g->adjacency_matrix[i][j] == 1 && colors[j] != -1){
                legal_colors[colors[j]] = 0;
            }
        }
        // Choose the first available legal color
        int color_chosen = -1;
        for(int j = 0; j < MAX_COLORS; j++){
            if(legal_colors[j] == 1){
                color_chosen = j;
                break;
            }
        }
        colors[i] = color_chosen;
    }
}