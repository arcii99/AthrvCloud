//FormAI DATASET v1.0 Category: Graph representation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Custom data type to represent a node
typedef struct Node
{
    int value;
    struct Node* next;
} Node;

// Create a new node with given value
Node* createNode(int value)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

// Add a new edge between nodes with values v1 and v2
void addEdge(Node* nodes[], int v1, int v2)
{
    // Create the nodes if they don't exist yet
    if (nodes[v1] == NULL)
        nodes[v1] = createNode(v1);
    if (nodes[v2] == NULL)
        nodes[v2] = createNode(v2);
        
    // Add v2 to the neighbor list of v1
    Node* neighbor = createNode(v2);
    neighbor->next = nodes[v1]->next;
    nodes[v1]->next = neighbor;
}

// Print the graph in adjacency list format
void printGraph(Node* nodes[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Node %d: ", i);
        if (nodes[i] == NULL)
        {
            printf("No neighbors\n");
            continue;
        }
        Node* neighbor = nodes[i]->next;
        while (neighbor != NULL)
        {
            printf("%d ", neighbor->value);
            neighbor = neighbor->next;
        }
        printf("\n");
    }
}

int main()
{
    // Create an array of nodes with size 5
    int n = 5;
    Node* nodes[n];
    for (int i = 0; i < n; i++)
        nodes[i] = NULL;
        
    // Add some edges to the graph
    addEdge(nodes, 0, 1);
    addEdge(nodes, 0, 2);
    addEdge(nodes, 1, 2);
    addEdge(nodes, 1, 3);
    addEdge(nodes, 2, 3);
    addEdge(nodes, 3, 4);
    
    // Print the graph
    printGraph(nodes, n);
    
    return 0;
}