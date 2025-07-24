//FormAI DATASET v1.0 Category: Graph representation ; Style: retro
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

/* The number of nodes in the graph*/  
#define NODES 10 

/* The number of edges in the graph*/  
#define EDGES 15

/* The array to store the edges of graph */  
int edges[EDGES][2];

/* Function to generate a random graph */  
void generate_graph() {
    int i, j, k;
    srand(time(0));  
    k = 0;
    for (i = 0; i < NODES; i++) {
        for (j = i + 1; j < NODES; j++) {
            if (rand() % 2 == 0) {
                edges[k][0] = i;
                edges[k][1] = j;
                k++;
            }
        }
    }
}

/* Function to generate the graph representation */  
void graph_representation() {
    int i, j;
    for (i = 0; i < NODES; i++) {
        printf("\nNode %d: ", i);
        for (j = 0; j < EDGES; j++) {
            if (edges[j][0] == i)
                printf("%d ", edges[j][1]);
            else if (edges[j][1] == i)
                printf("%d ", edges[j][0]);
        }
    }
}

/* The main function */  
int main() {  
    generate_graph();
    graph_representation();
    return 0;
}