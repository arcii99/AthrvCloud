//FormAI DATASET v1.0 Category: Graph representation ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 20

//Node struct to hold each vertex in the graph
typedef struct node
{
    int vertex;
    struct node* next;
} node;

//Graph struct to hold a list of vertices and their neighbors
typedef struct graph
{
    int num_vertices;
    node** adj_list;
    int* visited;
} graph;

//Function to create a new node
node* create_node(int v)
{
    node* new_node = malloc(sizeof(node));
    new_node->vertex = v;
    new_node->next = NULL;
    return new_node;
}

//Function to create a new graph
graph* create_graph(int vertices)
{
    graph* new_graph = malloc(sizeof(graph));
    new_graph->num_vertices = vertices;
    new_graph->adj_list = malloc(vertices * sizeof(node*));
    new_graph->visited = malloc(vertices * sizeof(int));

    for(int i=0;i<vertices;i++)
    {
        new_graph->adj_list[i]=NULL;//initialize all vertices to NULL
        new_graph->visited[i]=0;//set visited status to 0
    }

    return new_graph;
}

//Function to add edges to the graph
void add_edge(graph* g, int src, int dest)
{
    //Add edge from src to dest
    node* new_node=create_node(dest);
    new_node->next=g->adj_list[src];
    g->adj_list[src]=new_node;

    //Add edge from dest to src
    new_node=create_node(src);
    new_node->next=g->adj_list[dest];
    g->adj_list[dest]=new_node;
}

//Function to print the graph
void print_graph(graph* g)
{
    for(int i=0;i<g->num_vertices;i++)
    {
        printf("Vertex %d : ",i);
        node* temp=g->adj_list[i];
        while(temp)
        {
            printf("%d -> ",temp->vertex);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    graph* g=create_graph(5);

    add_edge(g, 0, 1);
    add_edge(g, 0, 4);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 1, 4);
    add_edge(g, 2, 3);
    add_edge(g, 3, 4);

    print_graph(g);

    return 0;
}