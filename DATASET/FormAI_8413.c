//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_VERTICES 10 // Maximum number of vertices
#define MAX_COLORS 3 // Maximum number of colors

// Structure to represent an edge in the graph
typedef struct edge{
    int vertex;
    struct edge * next;
} Edge;

// Structure to represent a vertex in the graph
typedef struct vertex{
    int name;
    int color;
    Edge * edge_list;
} Vertex;

// Function to add an edge to the graph
void add_edge(Vertex * vertices, int v1, int v2){
    Edge * new_edge = (Edge *) malloc(sizeof(Edge));
    new_edge->next = vertices[v1-1].edge_list;
    new_edge->vertex = v2-1;
    vertices[v1-1].edge_list = new_edge;

    new_edge = (Edge *) malloc(sizeof(Edge));
    new_edge->next = vertices[v2-1].edge_list;
    new_edge->vertex = v1-1;
    vertices[v2-1].edge_list = new_edge;
}

// Find the minimum color that can be assigned to the given vertex
int get_min_color(Vertex * vertices, int v){
    int used_colors[MAX_COLORS] = {0};
    Edge * cur_edge = vertices[v].edge_list;
    while(cur_edge){

        // If the connected vertex has a color, mark that color as used
        if(vertices[cur_edge->vertex].color != -1){
            used_colors[vertices[cur_edge->vertex].color] = 1;
        }
        cur_edge = cur_edge->next;
    }

    // Find the minimum color that can be used
    int i;
    for(i=0; i<MAX_COLORS; i++){
        if(!used_colors[i]){
            return i;
        }
    }
    return -1;
}

// Assign colors to the vertices of the graph
void color_graph(Vertex * vertices, int v_count){
    int i;
    for(i=0; i<v_count; i++){
        vertices[i].color = get_min_color(vertices, i);
    }
}

// Print the colors of the vertices
void print_colors(Vertex * vertices, int v_count){

    int i;
    printf("Vertex\tColor\n");
    for(i=0; i<v_count; i++){
        printf("%d\t", i+1);
        switch(vertices[i].color){
            case 0: printf("Red\n"); break;
            case 1: printf("Blue\n"); break;
            case 2: printf("Green\n"); break;
            default: printf("No Color\n");
        }
    }
}

int main(){

    Vertex vertices[MAX_VERTICES];
    int v_count = 5; // Number of vertices in the graph

    // Initialize the vertices
    int i;
    for(i=0; i<v_count; i++){
        vertices[i].name = i+1;
        vertices[i].color = -1;
        vertices[i].edge_list = NULL;
    }

    // Add edges between the vertices
    add_edge(vertices, 1, 2);
    add_edge(vertices, 1, 3);
    add_edge(vertices, 2, 3);
    add_edge(vertices, 2, 4);
    add_edge(vertices, 3, 4);
    add_edge(vertices, 4, 5);

    // Color the graph
    color_graph(vertices, v_count);

    // Print the colors of the vertices
    print_colors(vertices, v_count);

    return 0;
}