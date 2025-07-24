//FormAI DATASET v1.0 Category: Graph representation ; Style: Claude Shannon
//This program generates a C Graph representation using the Claude Shannon Style

#include <stdio.h>

#define MAX_VERTICES 20

//Structure to define vertices
typedef struct{
    int x;
    int y;
} Vertex;

//Function to add edges
void addEdge(char graph[][MAX_VERTICES], int start, int end){
    graph[start][end] = '1';
    graph[end][start] = '1';
}

int main(){

    Vertex vertices[MAX_VERTICES];
    char graph[MAX_VERTICES][MAX_VERTICES] = {0};
    
    //Initializing vertices
    vertices[0].x = 0;
    vertices[0].y = 0;

    vertices[1].x = 2;
    vertices[1].y = 4;

    vertices[2].x = 4;
    vertices[2].y = 0;

    vertices[3].x = 6;
    vertices[3].y = 4;

    vertices[4].x = 8;
    vertices[4].y = 0;

    //Adding edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    //Printing the graph
    printf("\t     [0]\n");
    printf("\t     /  \\ \n");
    printf("\t    /    \\ \n");
    printf("\t [1]      [2]\n");
    printf("\t  | \\     | \n");
    printf("\t  |  \\    | \n");
    printf("\t  |   \\   | \n");
    printf("\t [3]---[4]\n");

    return 0;
}