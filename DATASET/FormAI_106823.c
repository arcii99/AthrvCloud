//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NODE 100    // Maximum number of nodes in the network

int adjMatrix[MAX_NODE][MAX_NODE];   // Adjacency matrix
int reached[MAX_NODE];              // An array to keep track of visited nodes
int numOfNodes;                    // The number of nodes in the network

void DFS(int node) 
{
    printf("%d ", node);
    reached[node] = 1;

    int i = 0;
    for(i = 0; i < numOfNodes; i++) {
        if(adjMatrix[node][i] == 1 && reached[i] == 0) {
            DFS(i);
        }
    }
}

int main() 
{
    numOfNodes = 0;
    memset(reached, 0, sizeof(reached));   
    memset(adjMatrix, 0, sizeof(adjMatrix));

    printf("Enter the number of nodes in the network: ");
    scanf("%d", &numOfNodes);

    printf("\nEnter the adjacency matrix of the network (each row separated by a new line): \n");
    int i = 0, j = 0;
    for(i = 0; i < numOfNodes; i++) {
        for(j = 0; j < numOfNodes; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("\nThe DFS traversal of the network: ");
    DFS(0);

    printf("\n\n");
    return 0;
}