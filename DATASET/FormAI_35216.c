//FormAI DATASET v1.0 Category: Graph representation ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the hilarious world of C Graphs!\n\n");
    int nodes, edges;
    printf("Enter the number of nodes and edges in the graph:\n");
    scanf("%d %d", &nodes, &edges);
    printf("\nNow, let's create the graph of your dreams!\n");

    int** graph = (int**)malloc(nodes * sizeof(int*));
    for(int i=0; i<nodes; i++){
        graph[i] = (int*)malloc(nodes * sizeof(int));
        for(int j=0; j<nodes; j++){
            graph[i][j] = 0;
        }
    }

    int node1, node2;
    printf("Enter the connected nodes:\n");
    for(int i=1; i<=edges; i++){
        printf("Enter the nodes for edge%d:\n", i);
        scanf("%d %d", &node1, &node2);
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;
    }

    printf("\nYour beautiful graph is ready!! Here's a quick representation:\n\n");
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    printf("\nAnd that's it folks, your graph is all set to rock and roll!!\n");

    for(int i=0; i<nodes; i++){
        free(graph[i]);
    }
    free(graph);
    return 0;
}