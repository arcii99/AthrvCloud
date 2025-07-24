//FormAI DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

//define structure for a node
struct node {
    int data;
    struct node *next;
};

//function to insert a node at the beginning of the linked list
void insert_at_beginning(struct node **head, int data) {
    //create a new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    //set its data value to the input data
    new_node->data = data;
    //set its next pointer to the current head (which may be NULL)
    new_node->next = *head;
    //update the head pointer to the new node
    *head = new_node;
}

//function to insert a node at the end of the linked list
void insert_at_end(struct node **head, int data) {
    //create a new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    //set its data value to the input data
    new_node->data = data;
    //set its next pointer to NULL (it will be the last node in the list)
    new_node->next = NULL;
    //if the list is empty, set the head to the new node
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    //otherwise, traverse to the end of the list and append the new node
    struct node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

//function to delete a node with a given data value from the linked list
void delete_node(struct node **head, int data) {
    if (*head == NULL) {
        return;
    }
    //if the head node is the one to be deleted, simply update the head pointer
    if ((*head)->data == data) {
        struct node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    //traverse the list until the node to be deleted is found
    struct node *current = *head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    //if the node was not found in the list, return
    if (current->next == NULL) {
        return;
    }
    //otherwise, delete the node by updating its predecessor's next pointer
    struct node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

//function to print the linked list
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    //insert some nodes at the beginning of the list
    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 4);
    insert_at_beginning(&head, 3);
    //insert some nodes at the end of the list
    insert_at_end(&head, 6);
    insert_at_end(&head, 7);
    insert_at_end(&head, 8);
    //print the list before deleting any nodes
    printf("List before deleting any nodes: ");
    print_list(head);
    //delete some nodes from the list
    delete_node(&head, 4);
    delete_node(&head, 8);
    //print the list after deleting some nodes
    printf("List after deleting some nodes: ");
    print_list(head);
    return 0;
}