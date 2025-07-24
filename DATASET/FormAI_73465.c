//FormAI DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>

// Define a structure for graph nodes
typedef struct GraphNode
{
   int vertex;
   struct GraphNode* next;
} GraphNode;

// Define a structure for graphs
typedef struct Graph
{
   int numVertices;
   GraphNode** adjLists;
} Graph;

// Create a new node in the graph
GraphNode* createNode(int vertex)
{
   GraphNode* newNode = malloc(sizeof(GraphNode));
   newNode->vertex = vertex;
   newNode->next = NULL;
   return newNode;
}

// Create a new graph with numVertices vertices
Graph* createGraph(int numVertices)
{
   Graph* graph = malloc(sizeof(Graph));
   graph->numVertices = numVertices;
   graph->adjLists = malloc(numVertices * sizeof(GraphNode*));
   int i;
   for (i = 0; i < numVertices; i++)
      graph->adjLists[i] = NULL;
   return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest)
{
   // Create a new edge from src to dest
   GraphNode* newNode = createNode(dest);
   newNode->next = graph->adjLists[src];
   graph->adjLists[src] = newNode;
   
   // Create a new edge from dest to src
   newNode = createNode(src);
   newNode->next = graph->adjLists[dest];
   graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(Graph* graph)
{
   int i;
   for (i = 0; i < graph->numVertices; i++)
   {
      GraphNode* head = graph->adjLists[i];
      printf("\n Adjacency list of vertex %d\n head ", i);
      while (head)
      {
         printf("-> %d", head->vertex);
         head = head->next;
      }
      printf("\n");
   }
}

// Main function to test the graph functions
int main()
{
   Graph* graph = createGraph(5);
   addEdge(graph, 0, 1);
   addEdge(graph, 0, 4);
   addEdge(graph, 1, 2);
   addEdge(graph, 1, 3);
   addEdge(graph, 1, 4);
   addEdge(graph, 2, 3);
   addEdge(graph, 3, 4);
   printGraph(graph);
   return 0;
}