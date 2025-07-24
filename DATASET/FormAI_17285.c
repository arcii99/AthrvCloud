//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAXCOLORS 4
#define MAXVERTICES 5

int graph[MAXVERTICES][MAXVERTICES] = {   // adjacency matrix representation of the graph
                        {0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 1, 0},
                        {1, 1, 1, 0, 1},
                        {0, 1, 0, 1, 0}
                      };
int colors[MAXVERTICES] = {-1};

void printSolution() {    // print the solution
    printf("Colors assigned to the vertices:\n");
    for(int i=0; i<MAXVERTICES; i++) {
        printf("Vertex %d -> ", i);
        switch(colors[i]) {
            case 0:
                printf("Red");
                break;
            case 1:
                printf("Green");
                break;
            case 2:
                printf("Blue");
                break;
            case 3:
                printf("Yellow");
                break;
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int vertex, int color) {  // check if it is safe to assign a color to a vertex
    for(int i=0; i<MAXVERTICES; i++) {
        if(graph[vertex][i] && (colors[i]==color))
            return 0;
    }
    return 1;
}

int graphColoring(int vertex) {  // function to perform graph coloring
    if(vertex == MAXVERTICES) {   // all vertices have been assigned colors
        printSolution();
        return 1;
    }

    int next_vertex = vertex+1;
    for(int color=0; color<MAXCOLORS; color++) {   // try assigning different colors to the vertex
        if(isSafe(vertex, color)) {
            colors[vertex] = color;
            if(graphColoring(next_vertex))
                return 1;
            colors[vertex] = -1;
        }
    }
    return 0;
}

int main() {
    for(int i=0; i<MAXVERTICES; i++)   // initialize colors with -1 representing unassigned color
        colors[i] = -1;

    printf("The given graph:\n\n");
    for(int i=0; i<MAXVERTICES; i++) {
        for(int j=0; j<MAXVERTICES; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
    printf("\n");

    if(graphColoring(0) == 0)  // start graph coloring from vertex 0
        printf("No solution exists.\n");

    return 0;
}