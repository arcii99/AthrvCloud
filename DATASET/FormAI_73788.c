//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

int edge[5][5] = { {0, 1, 0, 1, 0},    //5 nodes, connections between nodes
                   {1, 0, 1, 1, 1},   
                   {0, 1, 0, 0, 1},
                   {1, 1, 0, 0, 1},
                   {0, 1, 1, 1, 0}};     

int colour[5];

void colourNode(int node) {
    int available[5];
    int i, j;

    for (i = 0; i < 5; i++) {  //initialize all colors to be available
        available[i] = 1;
    }

    for (i = 0; i < 5; i++) {   //check all nodes connected to current node
        if (edge[node][i] && colour[i] != -1) {
            available[colour[i]] = 0;
        }
    }

    for (i = 0; i < 5; i++) {   //assign first available color
        if (available[i]) {
            colour[node] = i;
            break;
        }
    }
}

void main() {
    int i;

    for (i = 0; i < 5; i++) {    //initialize all colors to be unassigned
        colour[i] = -1;
    }

    #pragma omp parallel for schedule(static)
    for (i = 0; i < 5; i++) {   //colour all nodes in parallel
        colourNode(i);
    }

    printf("\nColours assigned to nodes are:\n");
    for (i = 0; i < 5; i++) {   //print the colors assigned to each node
        printf("Node %d ---> Color %d\n", i, colour[i]);
    }
}