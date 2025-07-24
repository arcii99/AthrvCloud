//FormAI DATASET v1.0 Category: Graph representation ; Style: complex
#include<stdio.h>

//structure for graph node
struct GraphNode{
    int vertex; 
    struct GraphNode* next; 
};

//structure for graph
struct Graph{
    int numVertices; 
    struct GraphNode** adjLists; 
};

//function to create graph node
struct GraphNode* createGraphNode(int v){
    struct GraphNode* newNode = malloc(sizeof(struct GraphNode)); 
    newNode->vertex = v; 
    newNode->next = NULL; 
    return newNode; 
}

//function to create graph
struct Graph* createGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph)); 
    graph->numVertices = vertices; 
    
    graph->adjLists = malloc(vertices * sizeof(struct GraphNode*)); 
    
    int i;
    for(i=0; i<vertices; i++){
        graph->adjLists[i] = NULL; 
    }
    
    return graph; 
}

//function to add edge to graph
void addEdge(struct Graph* graph, int src, int dest){
    //add edge from src to dest
    struct GraphNode* newNode = createGraphNode(dest); 
    newNode->next = graph->adjLists[src]; 
    graph->adjLists[src] = newNode; 
    
    //add edge from dest to src
    newNode = createGraphNode(src); 
    newNode->next = graph->adjLists[dest]; 
    graph->adjLists[dest] = newNode; 
}

//function to print graph
void printGraph(struct Graph* graph){
    printf("Graph Representation:\n");
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct GraphNode* current = graph->adjLists[v];
        printf("\nVertex %d: ", v);
        while (current != NULL)
        {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

//main function
int main(){
    struct Graph* graph = createGraph(5); //creating a graph with 5 vertices
    
    //adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    //printing the graph
    printGraph(graph);

    return 0;
}