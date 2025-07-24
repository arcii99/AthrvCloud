//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_VERTICES 10
#define MAX_COLORS 4

int colors[MAX_VERTICES];

int is_valid(int vertices[][MAX_VERTICES], int vertex, int color) {
    for (int i=0; i<MAX_VERTICES; i++) {
        if (vertices[vertex][i] && color == colors[i])
            return 0;
    }
    return 1;
}

int graph_coloring(int vertices[][MAX_VERTICES], int vertex) {
    if (vertex == MAX_VERTICES)
        return 1;
  
    for (int color=1; color<=MAX_COLORS; color++) {
        if (is_valid(vertices, vertex, color)) {
            colors[vertex] = color;
 
            if (graph_coloring(vertices, vertex+1))
                return 1;
        }
        colors[vertex] = 0;
    }
 
    return 0;
}

int main() {
    int vertices[MAX_VERTICES][MAX_VERTICES];

    // generate a random graph
    srand(time(0));
    for (int i=0; i<MAX_VERTICES; i++) {
        for (int j=0; j<i; j++) {
            vertices[i][j] = vertices[j][i] = rand() % 2; // 0 or 1
        }
    }

    // print the graph
    printf("The random graph is:\n\n");
    for (int i=0; i<MAX_VERTICES; i++) {
        for (int j=0; j<MAX_VERTICES; j++) {
            printf("%d ", vertices[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // color the graph
    if (graph_coloring(vertices, 0)) {
        printf("Graph can be colored using the following colors: \n\n");
        for (int i=0; i<MAX_VERTICES; i++) {
            printf("Vertex %d: Color %d\n", i+1, colors[i]);
        }
    } else {
        printf("Graph cannot be colored using %d or less colors!\n", MAX_COLORS);
    }

    return 0;
}