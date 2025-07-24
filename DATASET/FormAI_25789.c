//FormAI DATASET v1.0 Category: Graph representation ; Style: systematic
#include <stdio.h>

#define MAX_ROADS 10
#define MAX_CITIES MAX_ROADS + 1

// Function to initialize the adjacency matrix
void initializeAdjMatrix(int adjMatrix[][MAX_CITIES])
{
    for (int i = 0; i < MAX_CITIES; i++)
    {
        for (int j = 0; j < MAX_CITIES; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

// Function to add a road between two cities
void addRoad(int city1, int city2, int dist, int adjMatrix[][MAX_CITIES])
{
    adjMatrix[city1][city2] = dist;
    adjMatrix[city2][city1] = dist;
}

// Function to print the adjacency matrix
void printAdjMatrix(int adjMatrix[][MAX_CITIES], int numCities)
{
    printf("Adjacency Matrix:\n");

    for (int i = 0; i < numCities; i++)
    {
        for (int j = 0; j < numCities; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }

        printf("\n");
    }
}

int main()
{
    int numCities = 6;
    int adjMatrix[MAX_CITIES][MAX_CITIES];

    // Initialize the adjacency matrix
    initializeAdjMatrix(adjMatrix);

    // Add roads between cities
    addRoad(1, 2, 50, adjMatrix);
    addRoad(1, 3, 75, adjMatrix);
    addRoad(2, 3, 100, adjMatrix);
    addRoad(2, 4, 125, adjMatrix);
    addRoad(3, 4, 150, adjMatrix);
    addRoad(3, 5, 175, adjMatrix);
    addRoad(4, 5, 200, adjMatrix);
    addRoad(4, 6, 225, adjMatrix);
    addRoad(5, 6, 250, adjMatrix);

    // Print the adjacency matrix
    printAdjMatrix(adjMatrix, numCities);

    return 0;
}