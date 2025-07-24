//FormAI DATASET v1.0 Category: Graph representation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void add_edge(struct node* edges[], int src, int dest){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = dest;
    newNode->next = edges[src];
    edges[src] = newNode;
}

void print_graph(struct node* edges[], int vertices){
    int i;
    for(i=0; i<vertices; i++){
        struct node* ptr = edges[i];
        printf("\nVertex %d: ", i);
        while(ptr!=NULL){
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

int main(){
    int vertices = 6;
    struct node* edges[vertices];
    int i;
    for(i=0; i<vertices; i++){
        edges[i] = NULL;
    }
    add_edge(edges, 0, 1);
    add_edge(edges, 1, 2);
    add_edge(edges, 2, 3);
    add_edge(edges, 3, 4);
    add_edge(edges, 4, 5);
    add_edge(edges, 5, 1);
    add_edge(edges, 2, 5);
    print_graph(edges, vertices);
    return 0;
}