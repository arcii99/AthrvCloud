//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX 10

int graph[MAX_VERTEX][MAX_VERTEX], colors[MAX_VERTEX];
int n;

int isValidColor(int v, int c) {
    for(int i=0; i<n; i++) {
        if(graph[v][i] && colors[i] == c) {
            return 0;
        }
    }
    return 1;
}

int graphColor(int v) {
    if(v == n) {
        return 1;
    }

    for(int i=1; i<=n; i++) {
        if(isValidColor(v, i)) {
            colors[v] = i;
            if(graphColor(v+1)) {
                return 1;
            }
            colors[v] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix of the graph:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    if(graphColor(0)) {
        printf("The vertices can be colored with the following colors:\n");
        for(int i=0; i<n; i++) {
            printf("Vertex %d : Color %d\n", i+1, colors[i]);
        }
    } else {
        printf("The graph can't be colored using %d colors\n", n);
    }

    return 0;
}