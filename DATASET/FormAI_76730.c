//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: creative
#include<stdio.h>
#include<stdlib.h>

//number of vertices in the graph
#define V 5

//function to print the solution matrix
void printSolution(int color[]);

/*function to check if the current color assignment is safe for the vertex v */
int isSafe(int v, int graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return 0;
    return 1;
}

//recursive function to solve graph coloring problem
int graphColoringUtil(int graph[V][V], int m, int color[], int v)
{
    //base case: if all vertices are assigned a color then return true
    if (v == V)
        return 1;

    //consider this vertex v and try different colors
    for (int c = 1; c <= m; c++)
    {
        //check if assignment of color c to v is possible
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            //recur for next vertex
            if (graphColoringUtil(graph, m, color, v + 1) == 1)
                return 1;

            //if assigning color c doesn't lead to a solution then remove it
            color[v] = 0;
        }
    }

    //if no color can be assigned to this vertex then return false
    return 0;
}

//function to solve graph coloring problem
void graphColoring(int graph[V][V], int m)
{
    //initialize all color values as 0. This is our initial feasible solution
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    //call recursive function graphColoringUtil() for vertex 0
    if (graphColoringUtil(graph, m, color, 0) == 0)
    {
        printf("\n Solution does not exist\n");
        return;
    }

    //print the solution
    printSolution(color);
}

//function to print solution
void printSolution(int color[])
{
    printf(" Solution Exists following are the assigned colors:\n");
    for (int i = 0; i < V; i++)
        printf(" Vertex %d ---> Color %d\n", i + 1, color[i]);
}

//driver function
int main()
{
    //creating the graph
    int graph[V][V] = { { 0, 1, 1, 1, 0 },
                        { 1, 0, 1, 0, 1 },
                        { 1, 1, 0, 1, 1 },
                        { 1, 0, 1, 0, 1 },
                        { 0, 1, 1, 1, 0 } };

    //number of colors
    int m = 3;

    //calling the graphColoring function to solve the graph coloring problem
    graphColoring(graph, m);
    return 0;
}