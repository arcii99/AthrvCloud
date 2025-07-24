//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

/*
 * This is a simple program that simulates
 * a medieval kingdom. You are the king and you
 * need to find the shortest path from your castle
 * to a nearby village.
 *
 * The villages are represented by numbers and
 * the distances between them are represented by a
 * matrix.
 *
 * This program uses the Dijkstra's algorithm for
 * finding the shortest path.
 */

#define MAX 6 // Number of villages
#define INF 9999 // Infinity value

int graph[MAX][MAX];

void initialize() {
    // Filling the distance matrix
    int i, j;
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }

    // Manually setting the distances between the villages
    graph[0][1] = 5;
    graph[1][0] = 5;
    graph[0][4] = 3;
    graph[4][0] = 3;
    graph[1][2] = 10;
    graph[2][1] = 10;
    graph[1][3] = 8;
    graph[3][1] = 8;
    graph[1][4] = 2;
    graph[4][1] = 2;
    graph[2][3] = 6;
    graph[3][2] = 6;
    graph[3][5] = 2;
    graph[5][3] = 2;
    graph[4][5] = 5;
    graph[5][4] = 5;
}

void dijkstra(int src, int dest) {
    // Initializing variables
    int distance[MAX], visited[MAX], path[MAX], count, minDistance, nextVortex, i, j;

    // Setting the initial values
    for (i = 0; i < MAX; i++) {
        distance[i] = graph[src][i];
        visited[i] = 0;
        path[i] = src;
    }

    distance[src] = 0;
    visited[src] = 1;
    count = 1;

    while (count < MAX - 1) {
        minDistance = INF;

        // Finding the village with the shortest distance
        for (i = 0; i < MAX; i++) {
            if (distance[i] < minDistance && !visited[i]) {
                minDistance = distance[i];
                nextVortex = i;
            }
        }

        // Marking the selected village as visited
        visited[nextVortex] = 1;

        // Updating the distances
        for (i = 0; i < MAX; i++) {
            if (!visited[i]) {
                if (minDistance + graph[nextVortex][i] < distance[i]) {
                    distance[i] = minDistance + graph[nextVortex][i];
                    path[i] = nextVortex;
                }
            }
        }

        count++;
    }

    // Printing the shortest path
    printf("The shortest path from Castle to Village %d: %d\n", dest, distance[dest]);

    printf("Path: %d", dest);
    j = dest;
    do {
        j = path[j];
        printf("<-%d", j);
    } while (j != src);
}

int main() {
    initialize();

    printf("Welcome to Medieval Kingdom\n");

    int sourceVillage = 0;
    int destinationVillage = 2;

    printf("\nFrom Castle to Village %d\n", destinationVillage);

    dijkstra(sourceVillage, destinationVillage);

    return 0;
}