//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include<stdio.h>

// function to check if a color is safe for the given vertex
int isSafe(int k, int vertices, int graph[vertices][vertices], int color[], int currentVertex){
    for(int i=0;i<vertices;i++){
        if(graph[currentVertex][i] && k==color[i]){
            return 0;
        }
    }
    return 1;
}

// function to assign colors recursively
int colorAssign(int vertices, int graph[vertices][vertices], int m, int color[], int currentVertex){
    if(currentVertex==vertices){
        return 1;
    }

    for(int k=1;k<=m;k++){
        if(isSafe(k, vertices, graph, color, currentVertex)){
            color[currentVertex]=k;

            // recursive call to colorAssign to color remaining vertices
            if(colorAssign(vertices, graph, m, color, currentVertex+1)){
                return 1;
            }

            // backtracking step
            color[currentVertex]=0;
        }
    }
    return 0;
}

// function to print color assigned to each vertex
void printColor(int vertices, int color[]){
    printf("\nColors assigned to the vertices are:\n");
    for(int i=0;i<vertices;i++){
        printf("%d ",color[i]);
    }
}

int main(){
    int vertices=5; // number of vertices in the graph
    int graph[5][5]={ {0, 1, 1, 0, 0},
                      {1, 0, 1, 1, 0},
                      {1, 1, 0, 1, 1},
                      {0, 1, 1, 0, 1},
                      {0, 0, 1, 1, 0} }; // adjacency matrix for the given graph
    int m=3; // maximum number of colors that can be used
    int color[vertices]; // array to store the color assigned to each vertex

    // initialize the color array with 0
    for(int i=0;i<vertices;i++){
        color[i]=0;
    }

    // call to colorAssign function to assign colors recursively
    printf("The Graph Coloring Problem for the given graph is:\n");
    if(colorAssign(vertices, graph, m, color, 0)==0){
        printf("No solution exists for the given parameters.");
    }
    else{
        printColor(vertices, color);
    }

    return 0;
}