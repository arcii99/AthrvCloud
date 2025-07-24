//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NODES 100
#define INF INT_MAX

int graph[MAX_NODES][MAX_NODES]; // adjacency matrix representation of graph

void initialize_graph() {
    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        for (j = 0; j < MAX_NODES; j++) {
            graph[i][j] = INF;
        }
    }
}

void add_edge(int node1, int node2, int weight) {
    graph[node1][node2] = weight;
    graph[node2][node1] = weight;
}

// Dijkstra's algorithm to find shortest path from a source node to all other nodes in the graph
void dijkstra(int start_node, int shortest_paths[], int visited[]) {
    int i, j, min_dist, next_node;
    for (i = 0; i < MAX_NODES; i++) {
        shortest_paths[i] = INF;
        visited[i] = 0;
    }
    shortest_paths[start_node] = 0;
    visited[start_node] = 1;
    next_node = start_node;
    
    for (i = 0; i < MAX_NODES; i++) {
        min_dist = INF;
        for (j = 0; j < MAX_NODES; j++) {
            if (!visited[j] && shortest_paths[j] < min_dist) {
                min_dist = shortest_paths[j];
                next_node = j;
            }
        }
        visited[next_node] = 1;
        for (j = 0; j < MAX_NODES; j++) {
            if (!visited[j] &&  (min_dist + graph[next_node][j] < shortest_paths[j])) {
                shortest_paths[j] = min_dist + graph[next_node][j];
            }
        }
    }
}

int main() {
    initialize_graph();
    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 2, 8);
    add_edge(1, 7, 11);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(2, 5, 4);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);
    
    int start_node = 0;
    
    int shortest_paths[MAX_NODES];
    int visited[MAX_NODES];
    
    dijkstra(start_node, shortest_paths, visited);
    
    printf("Shortest paths from node %d to all other nodes:\n", start_node);
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        printf("Node %d: %d\n", i, shortest_paths[i]);
    }
    
    return 0;
}