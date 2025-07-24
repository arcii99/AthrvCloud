//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: enthusiastic
//Hey there! Welcome to my unique C Network Topology Mapper program!
//I am so excited to show you what I've got!

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

typedef struct Graph{
    int V;
    Node **array;
}Graph;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->array = (Node**)malloc(V * sizeof(Node*));
    int i;
    for(i = 0; i < V; i++){
        graph->array[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest){
    Node* newNode = createNode(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->array[dest];
    graph->array[dest] = newNode;
}

void printGraph(Graph* graph){
    int i;
    for(i=0;i<graph->V;i++){
        Node* ptr = graph->array[i];
        printf("\n [Vertex %d]-->",i);
        while(ptr!=NULL){
            printf(" %d",ptr->val);
            ptr=ptr->next;
        }
        printf("\n");
    }
}

int main(){
    printf("Let's create a graph for our Network Topology Mapper program!\n");

    int V = 6; 
    Graph* graph = createGraph(V);
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,4);
    addEdge(graph,4,5);

    printf("\n\nGreat job! Now let's check the graph that we have created:\n");
    printGraph(graph);

    return 0;
}