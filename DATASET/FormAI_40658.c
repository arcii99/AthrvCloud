//FormAI DATASET v1.0 Category: Data structures visualization ; Style: automated
#include<stdio.h>
#include<stdlib.h>

/* structure representing a node in the adjacency list */

struct AdjListNode
{
    int dest;
    struct AdjListNode* next;
};

/* structure representing an adjacency list */

struct AdjList
{
    struct AdjListNode* head;
};

/* structure representing a graph which contains an array of adjacency lists */

struct Graph
{
    int num_vertices;
    struct AdjList* adjLists;
};

/* creating a new adjacency list node */

struct AdjListNode* newAdjListNode(int dest)
{
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

/* creating a new graph with a given number of vertices */

struct Graph* createGraph(int num_vertices)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;

    /* creating an array of adjacency lists in graph */

    graph->adjLists = (struct AdjList*) malloc(num_vertices * sizeof(struct AdjList));

    /* initializing each adjacency list as empty by making head as NULL */

    int i;
    for (i = 0; i < num_vertices; i++)
        graph->adjLists[i].head = NULL;

    return graph;
}

/* adding an edge to an undirected graph */

void addEdge(struct Graph* graph, int src, int dest)
{
    /* creating a new node with a given destination and adding it to the adjacency list of source */
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->adjLists[src].head;
    graph->adjLists[src].head = newNode;

    /* creating a new node with a given source and adding it to the adjacency list of destination */
    newNode = newAdjListNode(src);
    newNode->next = graph->adjLists[dest].head;
    graph->adjLists[dest].head = newNode;
}

/* printing the adjacency list of the graph */

void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->num_vertices; v++)
    {
        struct AdjListNode* trav = graph->adjLists[v].head;
        printf("\n Adjacency list of vertex %d\n Head ", v);
        while (trav)
        {
            printf("-> %d", trav->dest);
            trav = trav->next;
        }
        printf("\n");
    }
}

/* main function */

int main()
{
    /* creating a graph with 5 vertices */
    struct Graph* graph = createGraph(5);

    /* adding edges to the graph */
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 

    /* printing the adjacency list of the graph */
    printGraph(graph);

    return 0;
}