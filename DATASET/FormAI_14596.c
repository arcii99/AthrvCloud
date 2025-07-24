//FormAI DATASET v1.0 Category: Graph representation ; Style: Alan Touring
#include <stdio.h>

// Function to display the graph
void displayGraph(char graph[][5], int nodes) 
{
    printf("\n\t\tGRAPH REPRESENTATION\n");
    printf("-------------------------------------------\n");
    for (int i=0; i<nodes; i++) 
    {
        printf("Node %c -> ", ('A'+i));
        for (int j=0; j<nodes; j++) 
        {
            printf("%c ", graph[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------------------\n");
}

int main() 
{
    char graph[5][5] = {{'0','1','1','0','0'}, {'1','0','0','1','0'}, {'1','0','0','1','1'}, {'0','1','1','0','1'}, {'0','0','1','1','0'}};
    displayGraph(graph, 5); // Displays the graph

    return 0;
}