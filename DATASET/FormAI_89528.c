//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10 // maximum number of nodes in the graph

int graph[MAX_NODES][MAX_NODES]; // adjacency matrix representation of the graph
int color[MAX_NODES]; // an array to store the color of each node
bool used_colors[MAX_NODES]; // an array to keep track of which colors have already been used

// a function to check if it is safe to color a node with a given color
bool is_safe(int node, int c)
{
    for (int i = 0; i < MAX_NODES; i++)
    {
        if (graph[node][i] && color[i] == c) // if there is an edge between node and i, and i is already colored with c
        {
            return false; // then it is not safe to color node with c
        }
    }
    return true; // it is safe to color node with c
}

// a function to color the graph recursively
bool color_graph(int node, int num_nodes, int num_colors)
{
    if (node == num_nodes) // if all nodes have been colored
    {
        return true; // then the graph has been successfully colored
    }
    
    // try coloring the node with all possible colors
    for (int c = 0; c < num_colors; c++)
    {
        if (is_safe(node, c) && !used_colors[c]) // if it is safe to color the node with c and c has not been used yet
        {
            color[node] = c; // color the node with c
            used_colors[c] = true; // mark c as used
            if (color_graph(node+1, num_nodes, num_colors)) // recursively color the next node
            {
                return true; // if we successfully colored all nodes, return true
            }
            color[node] = -1; // uncolor the node
            used_colors[c] = false; // mark c as unused
        }
    }
    
    return false; // if we cannot color the node with any color, return false
}

int main()
{
    // initialize the graph
    for (int i = 0; i < MAX_NODES; i++)
    {
        for (int j = 0; j < MAX_NODES; j++)
        {
            graph[i][j] = 0;
        }
        color[i] = -1; // initialize all node colors to -1
    }
    
    // add edges to the graph
    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][4] = graph[4][3] = 1;
    graph[4][0] = graph[0][4] = 1;
    
    int num_nodes = 5; // number of nodes in the graph
    int num_colors = 3; // number of colors available
    
    if (color_graph(0, num_nodes, num_colors)) // if we successfully colored the graph
    {
        printf("The graph can be colored with %d colors as follows:\n", num_colors);
        for (int i = 0; i < num_nodes; i++)
        {
            printf("Node %d: Color %d\n", i, color[i]);
        }
    }
    else
    {
        printf("The graph cannot be colored with %d colors.\n", num_colors);
    }
    
    return 0;
}