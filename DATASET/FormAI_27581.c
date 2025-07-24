//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: cheerful
#include<stdio.h>

//Function to check if the given colour can be assigned to the vertex
int can_assign_colour(int vertex, int colour[], int graph[][vertex], int colours)
{
    for(int i=0;i<vertex;i++)
    {
        if(graph[vertex][i] && colour[i] == colours)
            return 0;
    }
    return 1;
}

//Function to assign colours to the vertices
int color_graph(int vertex, int graph[][vertex], int m, int colour[], int v)
{
    if(v == vertex)
        return 1;
    
    for(int i=1;i<=m;i++)
    {
        if(can_assign_colour(v, colour, graph, i))
        {
            colour[v] = i;
            
            if(color_graph(vertex, graph, m, colour, v+1))
                return 1;
            
            colour[v]=0;
        }
    }
    return 0;
}

int main()
{
    int vertex, edge;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertex);
    printf("Enter the number of edges: ");
    scanf("%d",&edge);

    int graph[vertex][vertex], colour[vertex];

    //Initialize all the colours to 0
    for(int i=0;i<vertex;i++)
        colour[i]=0;

    //Initialize the graph matrix to 0
    for(int i=0;i<vertex;i++)
    {
        for(int j=i+1;j<vertex;j++)
        {
            graph[i][j] = 0;
            graph[j][i] = 0;
        }
    }

    //Input edges for the graph
    for(int i=0;i<edge;i++)
    {
        int u,v;
        printf("Enter the edges (u v): ");
        scanf("%d %d",&u,&v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    //Assign colours to the vertices
    printf("Enter the number of colours: ");
    int m;
    scanf("%d",&m);
    if(color_graph(vertex, graph, m, colour, 0))
    {
        printf("The graph can be coloured using %d colours.\n",m);
        for(int i=0;i<vertex;i++)
            printf("Colour of vertex %d is %d\n",i,colour[i]);
    }
    else
        printf("The graph cannot be coloured using %d colours.\n",m);
    
    return 0;
}