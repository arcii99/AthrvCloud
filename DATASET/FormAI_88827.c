//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int shortestPath(int graph[ROW][COL], int start, int end);

int main()
{
    int graph[ROW][COL] = {{0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
                           {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
                           {1, 1, 0, 1, 1, 0, 0, 0, 0, 0},
                           {0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
                           {0, 0, 0, 0, 1, 0, 1, 1, 0, 0},
                           {0, 0, 0, 0, 1, 1, 0, 1, 1, 0},
                           {0, 0, 0, 0, 0, 1, 1, 0, 1, 1},
                           {0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 0}};

    int start = 0;
    int end = 9;

    int path_length = shortestPath(graph, start, end);

    printf("The shortest path from vertex %d to vertex %d is %d\n", start, end, path_length);

    return 0;
}

int shortestPath(int graph[ROW][COL], int start, int end)
{
    int distance[ROW];
    int visited[ROW];

    for (int i = 0; i < ROW; i++) {
        distance[i] = -1;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;

    int current_node = start;

    while(current_node != end) {
        for (int i = 0; i < COL; i++) {
            if (graph[current_node][i] == 1 && visited[i] == 0) {
                if (distance[i] == -1 || distance[i] > distance[current_node] + 1) {
                    distance[i] = distance[current_node] + 1;
                }
            }
        }

        int min_distance = -1;
        int next_node = -1;

        for (int i = 0; i < ROW; i++) {
            if (visited[i] == 0 && distance[i] != -1) {
                if (min_distance == -1 || distance[i] < min_distance) {
                    min_distance = distance[i];
                    next_node = i;
                }
            }
        }

        if (next_node == -1) {
            return -1;
        }

        current_node = next_node;
        visited[current_node] = 1;
    }

    return distance[end];
}