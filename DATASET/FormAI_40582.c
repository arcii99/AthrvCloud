//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#define max_n 10

//function to check if it is safe to color the vertex
int isSafe(int vertex, int color, int graph[max_n][max_n], int colors[]) {
    for(int i = 0; i < vertex; i++) {
        if(graph[vertex][i] && colors[i] == color) return 0;
    }
    return 1;
}

//function to recursively color the graph
int graphColor(int vertex, int graph[max_n][max_n], int m, int colors[]) {
    if(vertex == max_n) return 1;

    for(int color = 1; color <= m; color++) {
        if(isSafe(vertex, color, graph, colors)) {
            colors[vertex] = color;

            if(graphColor(vertex + 1, graph, m, colors) == 1) return 1;

            colors[vertex] = 0;
        }
    }
    return 0;
}

int main() {
    //matrix representation of the graph
    int graph[max_n][max_n] = 
     {{0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
      {1, 0, 1, 0, 1, 0, 0, 0, 0, 0},
      {1, 1, 0, 1, 1, 1, 0, 0, 0, 0},
      {1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
      {0, 1, 1, 1, 0, 1, 1, 0, 0, 0},
      {0, 0, 1, 1, 1, 0, 1, 1, 0, 0},
      {0, 0, 0, 0, 1, 1, 0, 1, 1, 0},
      {0, 0, 0, 0, 0, 1, 1, 0, 1, 1},
      {0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 0}};
    //set the number of colors to be used
    int m = 3;
    //array to store the colors of the vertices
    int colors[max_n] = {0};

    if(graphColor(0, graph, m, colors) == 0) {
        printf("Graph cannot be colored with %d colors.", m);
    }
    else {
        printf("The colors of the vertices are:\n");
        for(int i = 0; i < max_n; i++) {
            printf("Vertex %d: color %d\n", i+1, colors[i]);
        }
    }
    return 0;
}