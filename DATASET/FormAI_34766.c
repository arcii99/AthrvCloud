//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NODES 1000

int topology_map[MAX_NODES][MAX_NODES];
int visited[MAX_NODES], queue[MAX_NODES], distance[MAX_NODES];
int front = -1, rear = -1, num_of_nodes = 0;

void add_node(char* node_name) 
{
    num_of_nodes++;
}

int get_node_index(char* node_name) 
{
    return (num_of_nodes-1);
}

void add_edge(char* start_node, char* end_node) 
{
    int from = get_node_index(start_node);
    int to = get_node_index(end_node);
    topology_map[from][to] = topology_map[to][from] = 1;
}

void bfs_traversal(int start_node) 
{
    int current_node;
    visited[start_node] = 1;
    queue[++rear] = start_node;
    distance[start_node] = 0;
    printf("Node %d is at distance %d\n", start_node, distance[start_node]);
    while (front != rear) 
    {
        current_node = queue[++front];
        for(int i = 0; i < num_of_nodes; i++) 
        {
            if(topology_map[current_node][i] == 1 && visited[i] == 0) 
            {
                visited[i] = 1;
                queue[++rear] = i;
                distance[i] = distance[current_node] + 1;
                printf("Node %d is at distance %d\n", i, distance[i]);
            }
        }
    }
}

int main() 
{
    memset(topology_map, 0, sizeof(topology_map));
    memset(visited, 0, sizeof(visited));
    memset(queue, 0, sizeof(queue));
    memset(distance, 0, sizeof(distance));

    //Add nodes
    add_node("A");
    add_node("B");
    add_node("C");
    add_node("D");
    add_node("E");

    //Add edges
    add_edge("A", "B");
    add_edge("A", "D");
    add_edge("B", "C");
    add_edge("C", "D");
    add_edge("D", "E");

    //Perform bfs traversal
    bfs_traversal(0);

    return 0;
}