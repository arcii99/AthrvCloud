//FormAI DATASET v1.0 Category: Graph representation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

//SURPRISE!!! This is a unique Graph representation program
//that generates a random sequence of numbers as a Graph!

struct node{
    int data;
    struct node* next;
};

struct Graph{
    int vertices;
    struct node** adj_list;
};

//Function to create a new node
struct node* create_node(int vertex){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = vertex;
    new_node->next = NULL;
    return new_node;
}

//Function to create a Graph
struct Graph* create_graph(int vertices){
    struct Graph* new_graph = (struct Graph*) malloc(sizeof(struct Graph));
    new_graph->vertices = vertices;
    new_graph->adj_list = (struct node**) malloc(vertices * sizeof(struct node*));
    
    int i;
    for(i=0;i<vertices;i++){
        new_graph->adj_list[i] = NULL;
    }
    
    //SURPRISE!!! Generating a random Graph
    
    srand(time(0));
    int j;
    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            if(rand()%2){
                struct node* new_node = create_node(j);
                new_node->next = new_graph->adj_list[i];
                new_graph->adj_list[i] = new_node;
            }
        }
    }
    //END of random Graph generation
    
    return new_graph;
}

//Function to add an edge to the Graph
void add_edge(struct Graph* graph, int src, int dest){
    struct node* new_node = create_node(dest);
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;
    
    //SURPRISE!!! Printing the added edge
    
    printf("Added edge from vertex %d to vertex %d\n", src, dest);
    
    //END of edge addition
}

//Function to print the Graph
void print_graph(struct Graph* graph){
    int i;
    for(i=0;i<graph->vertices;i++){
        struct node* temp = graph->adj_list[i];
        printf("Vertex %d: ", i);
        while(temp){
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

//Main function that calls all other functions
int main(){
    //SURPRISE!!! Generating the Graph with 5 vertices
    struct Graph* graph = create_graph(5);
    printf("Generated Random Graph:\n");
    print_graph(graph);
    //END of Graph generation
    
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 0);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 3);
    
    printf("\nGraph:\n");
    print_graph(graph);
    
    return 0;
}