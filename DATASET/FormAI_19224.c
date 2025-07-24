//FormAI DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

// Define struct for Node
typedef struct node {
    int data; 
    struct node *next; 
} Node;

// Define struct for LinkedList
typedef struct linkedlist {
    Node *head;
} LinkedList;

// Initialize LinkedList
void init_linkedlist(LinkedList *list) {
    list->head = NULL;
}

// Insert Node at the end of LinkedList
void insert_end(LinkedList *list, int value) {
    Node *new_node = (Node*) malloc(sizeof(Node)); 
    new_node->data = value; 
    new_node->next = NULL; 

    if(list->head == NULL) { 
        list->head = new_node; 
    }
    else {
        Node *curr_node = list->head; 

        while(curr_node->next != NULL) { 
            curr_node = curr_node->next; 
        }

        curr_node->next = new_node; 
    }
}

// Print LinkedList Data
void print_list(LinkedList *list) {
    Node *curr_node = list->head; 

    while(curr_node != NULL) {
        printf("%d ", curr_node->data); 
        curr_node = curr_node->next; 
    }
}

int main() {
    LinkedList list; 
    init_linkedlist(&list); 

    insert_end(&list, 5); 
    insert_end(&list, 6); 
    insert_end(&list, 7); 
    insert_end(&list, 8); 

    printf("LinkedList: ");
    print_list(&list); 

    return 0; 
}