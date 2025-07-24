//FormAI DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
   int data;
   struct Node *next;
};

// Function to insert a new node at the beginning of the list
void insert_node_at_beginning(struct Node** head, int data) {
   // Create a new node
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
   new_node->data = data;
  
   new_node->next = (*head);
 
   (*head) = new_node;
}

// Function to delete the first occurrence of a specific node in the linked list
void delete_node(struct Node **head, int key) {
    // Check if the linked list is empty
    if (*head == NULL) {
        return;
    }
    
    // Store the head node
    struct Node* temp = *head, *prev;
    
    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    
    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // If the key was not present in the linked list
    if (temp == NULL) {
        return;
    }
    
    // Unlink the node from the linked list
    prev->next = temp->next;
    
    free(temp);
}

// Function to print the linked list
void print_linked_list(struct Node *head) {
   while(head != NULL) {
      printf(" %d ", head->data);
      head = head->next;
   }
   printf("\n");
}

int main() {
    // Create an empty linked list
    struct Node* head = NULL;

    // Insert nodes at the beginning
    insert_node_at_beginning(&head, 10);
    insert_node_at_beginning(&head, 20);
    insert_node_at_beginning(&head, 30);
    insert_node_at_beginning(&head, 40);
    insert_node_at_beginning(&head, 50);

    // Print the linked list
    printf("Linked list after insertion: ");
    print_linked_list(head);
    
    // Delete a specific node from the linked list
    delete_node(&head, 30);
    
    // Print the linked list
    printf("Linked list after deletion: ");
    print_linked_list(head);

    return 0;
}