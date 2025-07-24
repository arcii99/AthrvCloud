//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include<stdio.h>
#include<stdlib.h>

// Define maximum number of vertices for the graph
#define MAX_VERTICES 100

// Define maximum number of colors to be used for coloring the graph
#define MAX_COLORS 10

// Create a structure for vertices of the graph
struct vertex{
    int label;
};

// Create a structure for edges of the graph
struct edge{
    int vertex1_index;
    int vertex2_index;
};

// Create a structure for the graph
struct graph{
    int num_vertices;
    struct vertex vertices[MAX_VERTICES];
    int num_edges;
    struct edge edges[MAX_VERTICES];
};

// Function to assign colors to the vertices of the graph
void color_graph(struct graph *g, int max_colors){
    
    // Create an array to store the colors assigned to the vertices
    int vertex_colors[MAX_VERTICES];
    
    int i, j;
    // Assign the first vertex the first color
    vertex_colors[0] = 1;
    
    // Assign colors to the remaining vertices of the graph
    for(i=1; i<g->num_vertices; i++){
        
        // Set the color of the current vertex to 0
        vertex_colors[i] = 0;
        
        // Create an array to store the colors already used by the neighboring vertices
        int used_colors[MAX_VERTICES];
        
        // Set all the elements of the used_colors array to 0 initially
        for(j=0; j<MAX_VERTICES; j++){
            used_colors[j] = 0;
        }
        
        // Loop through all the edges of the graph
        for(j=0; j<g->num_edges; j++){
            
            // If the current vertex is the first vertex of the edge
            if(g->edges[j].vertex1_index == i){
                
                // Get the color of the second vertex of the edge
                int color = vertex_colors[g->edges[j].vertex2_index];
                
                // Mark the color as used
                used_colors[color] = 1;
            }
            // If the current vertex is the second vertex of the edge
            else if(g->edges[j].vertex2_index == i){
                
                // Get the color of the first vertex of the edge
                int color = vertex_colors[g->edges[j].vertex1_index];
                
                // Mark the color as used
                used_colors[color] = 1;
            }
        }
        
        // Assign the first unused color to the current vertex
        for(j=1; j<=max_colors; j++){
            if(used_colors[j] == 0){
                vertex_colors[i] = j;
                break;
            }
        }
    }
    
    // Print the colors assigned to each vertex
    printf("\nColors assigned to vertices:\n");
    for(i=0; i<g->num_vertices; i++){
        printf("Vertex %d: Color %d\n", i, vertex_colors[i]);
    }
}

int main(){
    
    // Create a graph with 5 vertices and 7 edges
    struct graph g;
    g.num_vertices = 5;
    g.vertices[0].label = 0;
    g.vertices[1].label = 1;
    g.vertices[2].label = 2;
    g.vertices[3].label = 3;
    g.vertices[4].label = 4;
    g.num_edges = 7;
    g.edges[0].vertex1_index = 0;
    g.edges[0].vertex2_index = 1;
    g.edges[1].vertex1_index = 1;
    g.edges[1].vertex2_index = 2;
    g.edges[2].vertex1_index = 2;
    g.edges[2].vertex2_index = 0;
    g.edges[3].vertex1_index = 0;
    g.edges[3].vertex2_index = 3;
    g.edges[4].vertex1_index = 3;
    g.edges[4].vertex2_index = 4;
    g.edges[5].vertex1_index = 4;
    g.edges[5].vertex2_index = 2;
    g.edges[6].vertex1_index = 3;
    g.edges[6].vertex2_index = 1;
    
    // Assign colors to the vertices of the graph using 3 colors
    color_graph(&g, 3);
    
    return 0;
}