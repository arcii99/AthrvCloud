//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: sophisticated
#include <stdio.h>

// Function to check if adjacent vertices
// of the vertex i are colored with the given color
int is_possible(int vertex, int graph[10][10], int color[], int num_of_colors){
    for(int j=0; j<10; j++){
        if(graph[vertex][j] && color[j]==num_of_colors)
            return 0;
    }
    return 1;
}

// Function to solve the graph coloring problem using backtracking
int graph_coloring(int vertex, int graph[10][10], int color[], int num_of_colors){
    // base case: all vertices are colored
    if(vertex==10)
        return 1;

    for(int i=1; i<=num_of_colors; i++){
        // check if color i can be assigned to the current vertex
        if(is_possible(vertex, graph, color, i)){
            color[vertex] = i;

            // recur for the next vertex
            if(graph_coloring(vertex+1, graph, color, num_of_colors))
                return 1;

            // backtrack by assigning 0 to the current vertex
            color[vertex] = 0;
        }
    }
    return 0;
}

int main(){
    // Sample graph with 10 vertices and 14 edges
    int graph[10][10] = {{0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                         {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                         {1, 1, 0, 1, 1, 0, 0, 0, 0, 0},
                         {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
                         {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
                         {0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
                         {0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
                         {0, 0, 0, 0, 0, 1, 1, 0, 1, 1},
                         {0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
                         {0, 0, 0, 0, 0, 0, 0, 1, 1, 0}};

    int num_of_colors = 4;
    int color[10] = {0};

    if(graph_coloring(0, graph, color, num_of_colors)){
        printf("The vertices can be colored with %d colors as follows: \n", num_of_colors);
        for(int i=0; i<10; i++)
            printf("Vertex %d: Color %d\n", i, color[i]);
    }
    else
        printf("The vertices cannot be colored with %d colors.\n", num_of_colors);

    return 0;
}