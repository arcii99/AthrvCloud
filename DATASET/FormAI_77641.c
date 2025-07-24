//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_NODES 10
#define MAX_COLORS 4

int graph[MAX_NODES][MAX_NODES];
int nodeColor[MAX_NODES];

void printGraph(int n) {
    printf("\nGraph:\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void printColors(int n) {
    printf("\nColors:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", nodeColor[i]);
    }
    printf("\n");
}

int isValidColor(int n, int node, int color) {
    for(int i=0; i<n; i++) {
        if(graph[node][i] && nodeColor[i]==color) {
            return 0;
        }
    }
    return 1;
}

int colorGraph(int n, int node) {
    if(node == n) { //base case
        return 1;
    }
    for(int color=1; color<=MAX_COLORS; color++) {
        if(isValidColor(n, node, color)) {
            nodeColor[node] = color;
            if(colorGraph(n, node+1)) { //recursion
                return 1;
            }
            nodeColor[node] = 0; //backtrack
        }
    }
    return 0;
}

int main() {
    srand(time(NULL)); //initialize random seed
    int n = rand() % MAX_NODES + 1; //random number of nodes between 1 and MAX_NODES
    printf("Number of nodes: %d\n", n);
    //initialize graph, fill with random 0's and 1's
    printf("Initializing graph...\n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = rand() % 2;
                graph[j][i] = graph[i][j];
            }
        }
    }
    printGraph(n);
    printf("Coloring graph...\n");
    if(colorGraph(n, 0)) { //start with node 0
        printf("Graph can be colored with %d colors.\n", MAX_COLORS);
        printColors(n);
    } else {
        printf("Graph cannot be colored with %d colors.\n", MAX_COLORS);
    }
    return 0;
}