//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the map of the network topology
void printTopologyMap(char* topologyMap[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\t%s\n", topologyMap[i]);
    }
}

int main()
{
    char* topologyMap[8] = {"          #",
                            "         / \\     ",
                            "        1---2    ",
                            "        |   |    ",
                            "        |   |    ",
                            "        3---4    ",
                            "         \\ /     ",
                            "          #"};

    printf("Welcome to the Medieval Network Topology Mapper!\n");
    printf("Here is the network topology map:\n");
    printTopologyMap(topologyMap, 8);

    printf("Enter the number of nodes in the network: ");
    int n;
    scanf("%d", &n);

    // Create an empty adjacency matrix
    int** adjMatrix = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        adjMatrix[i] = (int*) calloc(n, sizeof(int));
    }

    // Prompt the user to fill the adjacency matrix
    printf("Please enter the connections between the nodes:\n");
    int node1, node2;
    char choice;
    do 
    {
        printf("Enter the first node: ");
        scanf("%d", &node1);
        printf("Enter the second node: ");
        scanf("%d", &node2);

        // Add the connection to the adjacency matrix
        adjMatrix[node1-1][node2-1] = 1;
        adjMatrix[node2-1][node1-1] = 1;

        printf("Do you want to add more connections? (y/n)");
        scanf(" %c", &choice);
    } while (choice == 'y');

    // Print the adjacency matrix
    printf("\nThe adjacency matrix is:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    // Free up memory
    for (int i = 0; i < n; i++)
    {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    printf("\nThank you for using the Medieval Network Topology Mapper!\n");

    return 0;
}