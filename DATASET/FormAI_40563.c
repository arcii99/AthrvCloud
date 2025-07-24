//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: unmistakable
#include<stdio.h>

// Function to check if the current vertex can be assigned a particular color
int can_color(int vertex, int color, int graph[][vertex], int *coloring, int colors_assigned) {
    for(int i=0; i<vertex; i++) {
        if(graph[vertex][i] && coloring[i] == color) {
            return 0;
        }
    }
    return 1;
}

// Recursive function to assign colors to the graph vertices
int color_graph(int vertex, int graph[][vertex], int *coloring, int colors_assigned, int max_colors) {
    if(vertex == 0) {
        return 1;
    }
    for(int color=1; color<=max_colors; color++) {
        if(can_color(vertex-1, color, graph, coloring, colors_assigned)) {
            coloring[vertex-1] = color;
            if(color_graph(vertex-1, graph, coloring, colors_assigned, max_colors)) {
                return 1;
            }
            coloring[vertex-1] = 0;
        }
    }
    return 0;
}
  
// Main function to solve graph coloring problem
void solve_graph_coloring(int vertex, int graph[][vertex], int max_colors) {
    int coloring[vertex], colors_assigned = 1;
    for(int i=0; i<vertex; i++) {
        coloring[i] = 0;
    }

    // Color the vertices of the graph
    color_graph(vertex, graph, coloring, colors_assigned, max_colors);

    // Print the assigned colors for each vertex
    printf("Assigned colors for each vertex:\n");
    for(int i=0; i<vertex; i++) {
        printf("Vertex %d: Color %d\n", i+1, coloring[i]);
    }
}

// Main program
int main() {
    int vertex, max_colors;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertex);
    int graph[vertex][vertex];
    printf("Enter the adjacency matrix:\n");
    for(int i=0; i<vertex; i++) {
        for(int j=0; j<vertex; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the maximum number of colors: ");
    scanf("%d", &max_colors);
    solve_graph_coloring(vertex, graph, max_colors);
    return 0;
}