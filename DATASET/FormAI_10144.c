//FormAI DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Structure for node in the graph
typedef struct node {
    int data;
    struct node* next;
} Node;

int main() {

    // Array for storing nodes of the graph
    Node* graph[5];
    int i;

    // Creating and appending nodes to graph
    for (i=0; i<5; i++) {
        graph[i] = (Node*)malloc(sizeof(Node));
        graph[i]->data = i;
        graph[i]->next = NULL;
    }

    // Connecting nodes to form a graph
    graph[0]->next = graph[1];
    graph[0]->next->next = graph[2];
    graph[1]->next = graph[3];
    graph[2]->next = graph[3];
    graph[3]->next = graph[4];

    // Printing the graph representation
    for (i=0; i<5; i++) {
        Node* current = graph[i];
        printf("%d: ", current->data);
        if (current->next == NULL) {
            printf("NULL");
        } else {
            while (current->next != NULL) {
                current = current->next;
                printf("%d ", current->data);
            }
        }
        printf("\n");
    }

    return 0;
}