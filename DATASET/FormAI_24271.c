//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_VERTICES 6
#define MAX_EDGES 10

struct edge
{
    int vertex1;
    int vertex2;
};

int is_safe(int vertex, int graph[MAX_VERTICES][MAX_VERTICES], int colors[], int color)
{
    for(int i=0; i<MAX_VERTICES; i++)
    {
        if(graph[vertex][i] && colors[i]==color)
            return 0;
    }
    return 1;
}

int graph_coloring(int graph[MAX_VERTICES][MAX_VERTICES], int colors[], int vertex)
{
    if(vertex==MAX_VERTICES)
        return 1;
    
    for(int color=1; color<=4; color++)
    {
        if(is_safe(vertex, graph, colors, color))
        {
            colors[vertex]=color;
            
            if(graph_coloring(graph, colors, vertex+1)==1)
                return 1;
            
            colors[vertex]=0;
        }
    }
    return 0;
}

void print_graph(int graph[MAX_VERTICES][MAX_VERTICES])
{
    printf("\nThe matrix representation of the graph is:\n\n");
    for(int i=0; i<MAX_VERTICES; i++)
    {
        for(int j=0; j<MAX_VERTICES; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }
}

void print_edge_list(struct edge edges[], int num_edges)
{
    printf("\nThe edge list representation of the graph is:\n\n");
    for(int i=0; i<num_edges; i++)
    {
        printf("(%d, %d)\t", edges[i].vertex1, edges[i].vertex2);
    }
    printf("\n");
}

void generate_graph(int graph[MAX_VERTICES][MAX_VERTICES], struct edge edges[], int *num_edges)
{
    srand(time(NULL));
    int num_vertices=MAX_VERTICES;
    
    //Generating random number of edges
    int max_edges=(num_vertices*(num_vertices-1))/2;
    *num_edges=rand()%max_edges + 1;
    
    //Initializing all vertices to not connected
    for(int i=0; i<num_vertices; i++)
    {
        for(int j=0; j<num_vertices; j++)
        {
            graph[i][j]=0;
        }
    }
    
    //Generating random edges
    int count=0;
    while(count<*num_edges)
    {
        int vertex1=rand()%num_vertices;
        int vertex2=rand()%num_vertices;
        
        if(vertex1==vertex2)
            continue;
            
        if(graph[vertex1][vertex2]==0 && graph[vertex2][vertex1]==0)
        {
            graph[vertex1][vertex2]=1;
            graph[vertex2][vertex1]=1;
            
            edges[count].vertex1=vertex1;
            edges[count].vertex2=vertex2;
            
            count++;
        }
    }
}

int main()
{
    int graph[MAX_VERTICES][MAX_VERTICES], colors[MAX_VERTICES]={0}, num_edges;
    struct edge edges[MAX_EDGES];
    
    generate_graph(graph, edges, &num_edges);
    
    printf("Welcome to the Graph Coloring Problem Program in a Futuristic Style!\n\n");
    
    print_graph(graph);
    
    print_edge_list(edges, num_edges);
    
    if(graph_coloring(graph, colors, 0)==1)
    {
        printf("\nGraph can be colored using minimum 4 colors\n\n");
        printf("The colors assigned to each vertex are:\n\n");
        for(int i=0; i<MAX_VERTICES; i++)
        {
            printf("Vertex %d - Color %d\n", i, colors[i]);
        }
    }
    else
    {
        printf("\nGraph cannot be colored using 4 colors\n");
    }
    
    return 0;
}