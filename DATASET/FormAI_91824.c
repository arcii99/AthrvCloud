//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 5

int main()
{
    int arr[N][N] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    }; // adjacency matrix representation of a graph

    int dist[N]; // stores the minimum distance from source vertex to all other vertices
    int visited[N] = {0}; // stores whether a vertex is visited or not
    int src = 0; // source vertex, set to 0

    // initialize all distances to infinity except distance to source vertex which is 0
    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // for each vertex in the graph
    for (int i = 0; i < N - 1; i++) {
        // find the vertex with minimum distance from the source vertex
        int min_dist = INT_MAX, min_index;
        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                min_index = j;
            }
        }

        // mark the vertex as visited
        visited[min_index] = 1;

        // update the distances of its adjacent vertices
        for (int k = 0; k < N; k++) {
            if (!visited[k] && arr[min_index][k] && dist[min_index] != INT_MAX && dist[min_index] + arr[min_index][k] < dist[k]) {
                dist[k] = dist[min_index] + arr[min_index][k];
            }
        }
    }

    // print the minimum distance from source vertex to all other vertices
    for (int i = 0; i < N; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}