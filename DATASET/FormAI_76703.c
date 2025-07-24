//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Defining Node Structure */
typedef struct node {
    char name[20];
    int visited;
    struct node *next;
    struct edge *edges;
} Node;

/* Defining Edge Structure */
typedef struct edge {
    int weight;
    struct node *from;
    struct node *to;
    struct edge *next;
} Edge;

/* Function to add Node to Linked List */
void add_node(Node **head, char *name){
    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->visited = 0;
    new_node->next = *head;
    new_node->edges = NULL;
    *head = new_node;
}

/* Function to add Edge to Linked List */
void add_edge(Node *one, Node *two, int weight){
    Edge *new_edge = (Edge *)malloc(sizeof(Edge));
    new_edge->weight = weight;
    new_edge->from = one;
    new_edge->to = two;
    new_edge->next = one->edges;
    one->edges = new_edge;
}

/* Depth First Search Recursive Function */
void dfs(Node *start){
    start->visited = 1;
    printf("%s -> ", start->name);
    Edge *edge = start->edges;
    while(edge){
        if(edge->to->visited == 0){
            dfs(edge->to);
        }
        edge = edge->next;
    }
}

/* Function to Print Adjacency List for Debugging */
void print_adjacency_list(Node *head){
    while(head){
        Edge *edge = head->edges;
        printf("%s -> ", head->name);
        while(edge){
            printf("%s(%d) -> ", edge->to->name, edge->weight);
            edge = edge->next;
        }
        printf("NULL\n");
        head = head->next;
    }
}

/* Main Function */
int main(){
    Node *start = NULL;
    add_node(&start, "A");
    add_node(&start, "B");
    add_node(&start, "C");
    add_node(&start, "D");
    add_node(&start, "E");

    /* Adding Edges */
    add_edge(start->next, start, 4);
    add_edge(start->next, start->next->next, 3);
    add_edge(start->next->next, start->next, 1);
    add_edge(start->next->next, start, 2);
    add_edge(start->next->next, start->next->next->next, 5);
    add_edge(start->next->next->next, start->next, 6);
    add_edge(start->next->next->next, start, 7);

    printf("Adjacency List Before DFS:\n");
    print_adjacency_list(start);

    printf("DFS: ");
    dfs(start);
    printf("NULL\n");

    return 0;
}