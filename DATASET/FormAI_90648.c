//FormAI DATASET v1.0 Category: Graph representation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define V 10 //number of vertices

//function prototypes
void initializeGraph(int graph[V][V]);
void displayGraph(int graph[V][V]);
void generateRandomGraph(int graph[V][V]);

int main() {
    srand(time(0)); //for generating different random numbers every time
    
    int graph[V][V];
    initializeGraph(graph); //initialize graph with 0 values
    displayGraph(graph); //display the graph before generating random edges
    printf("\nGenerating random edges between vertices...\n");
    generateRandomGraph(graph); //generate random edges between vertices
    displayGraph(graph); //display the graph after generating random edges
    
    return 0;
}

//initialize graph with 0 values
void initializeGraph(int graph[V][V]) {
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            graph[i][j] = 0;
        }
    }
}

//display the graph
void displayGraph(int graph[V][V]) {
    printf("\nGraph representation using C:\n\n");
    for(int i=0;i<V;i++) {
        for(int j=0;j<V;j++) {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}

//generate random edges between vertices
void generateRandomGraph(int graph[V][V]) {
    for(int i=0;i<V;i++) {
        for(int j=i+1;j<V;j++) {
            if(rand()%2 == 1) {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }
}