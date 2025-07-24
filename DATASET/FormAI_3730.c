//FormAI DATASET v1.0 Category: Graph representation ; Style: imaginative
/* Welcome to the magical world of Graphs! */
#include<stdio.h>
#include<stdlib.h>

/* We'll create a Graph with nodes and edges to help a wizard travel through different lands with ease */
int main() {
    int num_nodes;
    printf("Enter the number of nodes in the Graph: ");
    scanf("%d", &num_nodes);

    /* Initializing Graph as a 2D array */
    int graph[num_nodes][num_nodes];

    /* Let's start by setting all the edge values to 0 */
    for(int i=0; i<num_nodes; i++) {
        for(int j=0; j<num_nodes; j++) {
            graph[i][j] = 0;
        }
    }

    /* Now the fun part begins - we'll add magical portals to connect the different lands */
    printf("Enter the number of portals to add: ");
    int num_portals;
    scanf("%d", &num_portals);

    /* Time to add portals! */
    for(int i=0; i<num_portals; i++) {
        int start, end, distance;
        printf("Enter the start node, end node and the distance of the portal %d: ", i+1);
        scanf("%d %d %d", &start, &end, &distance);
        
        /* Checking if the start and end nodes are valid */
        if(start<1 || end<1 || start>num_nodes || end>num_nodes) {
            printf("Invalid input. Please try again.\n");
            i--;
            continue;
        }

        /* Adding the portal to our Graph */
        graph[start-1][end-1] = distance;
        graph[end-1][start-1] = distance;
    }

    /* Our Graph is ready! Let's print it out for the wizard to see */
    printf("Here's your Graph:\n");
    for(int i=0; i<num_nodes; i++) {
        for(int j=0; j<num_nodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("All set. Let the wizard's journey begin!\n");

    return 0;
}