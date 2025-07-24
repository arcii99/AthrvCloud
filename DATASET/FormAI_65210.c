//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define matrix size
#define N 5

// Define a 2D Matrix to represent the graph
int graph[N][N] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 1},
    {0, 1, 0, 1, 0}
};

// A function to check if a vertex is already in the path
int notInPath(int currentPath[], int vertex, int size) {
    for(int i = 0; i < size; i++) {
        if(currentPath[i] == vertex) {
            return 0;
        }
    }
    return 1;
}

// A recursive function to find a path from source to destination
int findPathRecursive(int src, int dest, int currentPath[], int size) {
    // If the source is same as destination, we have found a path
    if(src == dest) {
        printf("Path found:");
        for(int i = 0; i < size; i++) {
            printf(" %d", currentPath[i]);
        }
        printf(" %d\n", dest);
        return 1;
    }

    // Mark the current vertex as visited
    currentPath[size] = src;
    size++;

    // Check all the adjacent vertices
    for(int i = 0; i < N; i++) {
        if(graph[src][i] == 1 && notInPath(currentPath, i, size)) {
            if(findPathRecursive(i, dest, currentPath, size)) {
                return 1;
            }
        }
    }

    return 0;
}

// A helper function to call the recursive function
void findPath(int src, int dest) {
    // Create a path array to store the current path
    int currentPath[N] = {0};

    // Call recursive function to find the path
    if(!findPathRecursive(src, dest, currentPath, 0)) {
        printf("Path not found!\n");
    }
}

// Driver function to test the code
int main() {
    int source = 0, destination = 4;

    printf("Finding path from %d to %d\n", source, destination);
    findPath(source, destination);

    return 0;
}