//FormAI DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

node_t *head = NULL; // head of list

int main() {
    int n = 10; // number of nodes to allocate
    
    // allocate memory for nodes
    for (int i=0; i<n; i++) {
        node_t *new_node = (node_t*)malloc(sizeof(node_t));
        if (new_node == NULL) {
            printf("Memory allocation failed. Exiting...\n");
            exit(1);
        }
        new_node->val = i+1;
        new_node->next = head;
        head = new_node; // update head of list
    }
    
    // print values of list
    printf("Values of list: ");
    node_t *current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
    
    // free memory of nodes
    current = head;
    while (current != NULL) {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }
    head = NULL; // reset head of list
    
    return 0;
}