//FormAI DATASET v1.0 Category: Graph representation ; Style: Cyberpunk
#include <stdio.h>

// function to print nodes in the graph
void printNodes(int nodes[], int length) {
    printf("Nodes: ");
    for(int i=0; i<length; i++) {
        printf("%d ", nodes[i]);
    }
    printf("\n");
}

// function to print edges in the graph
void printEdges(int edges[][2], int length) {
    printf("Edges:\nFrom      To\n");
    for(int i=0; i<length; i++) {
        printf("%d         %d\n", edges[i][0], edges[i][1]);
    }
}

int main() {
    // Create the graph
    int nodes[] = {1, 2, 3, 4, 5, 6};
    int edges[][2] = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 5}, {4, 6}, {5, 6}};
    
    printf("Welcome to the Cyber Graph!\n");
    printf("===========================\n");
    
    printf("Initializing nodes...\n");
    printNodes(nodes, 6);
    printf("\n");
    
    printf("Creating connections...\n");
    printEdges(edges, 8);
    printf("\n");
    
    printf("Graph complete! Enjoy your journey through the cyber world.\n");
    printf("==========================================================\n");
    
    return 0;
}