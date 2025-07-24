//FormAI DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;           // integer data 
    struct node *next;  // pointer to the next node
};

// Function to print the linked list
void printList(struct node *n) {
    while(n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the linked list
void push(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));  // allocate memory for new node
    new_node->data = new_data;      // assign the data for the new node
    new_node->next = (*head_ref);   // set the new node's next to the current head
    (*head_ref) = new_node;         // set the head to the new node
}

// Function to insert a node after a given node
void insertAfter(struct node *prev_node, int new_data) {
    if(prev_node == NULL) {
        printf("Error: The previous node cannot be null.\n");
        return;
    }

    struct node *new_node = (struct node*) malloc(sizeof(struct node));  // allocate memory for new node
    new_node->data = new_data;      // assign the data for the new node
    new_node->next = prev_node->next;  // set the new node's next to the previous node's next
    prev_node->next = new_node;     // set the previous node's next to the new node
}

// Function to insert a node at the end of the linked list
void append(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));  // allocate memory for new node
    struct node *last = *head_ref;  // create a temporary pointer to the head

    new_node->data = new_data;      // assign the data for the new node
    new_node->next = NULL;          // set the new node's next to null

    if(*head_ref == NULL) {
        *head_ref = new_node;       // if the linked list is empty, set the head to the new node
        return;
    }

    while(last->next != NULL) {
        last = last->next;          // iterate through the linked list to find its end
    }
    last->next = new_node;          // set the last node's next to the new node
}

// Function to delete a node with the given key value
void deleteNode(struct node **head_ref, int key) {
    struct node *temp = *head_ref, *prev;

    if(temp != NULL && temp->data == key) {
        *head_ref = temp->next;     // if the head node itself holds the key to be deleted
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key) {
        prev = temp;                // iterate through the linked list to find the node with the given key
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Error: The node with the given key does not exist.\n");
        return;
    }

    prev->next = temp->next;        // unlink the node to be deleted from the linked list
    free(temp);
}

// Main function
int main() {
    struct node *head = NULL;

    printf("Operations that can be performed:\n");
    printf("1. Insert a node at the beginning of the linked list.\n");
    printf("2. Insert a node after a given node.\n");
    printf("3. Insert a node at the end of the linked list.\n");
    printf("4. Delete a node with the given key value from the linked list.\n");
    printf("5. Print the linked list.\n");
    printf("6. Exit.\n");

    int option, new_data, key;

    do {
        printf("Enter an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &new_data);
                push(&head, new_data);
                break;
            case 2:
                printf("Enter the data to be inserted: ");
                scanf("%d", &new_data);

                printf("Enter the data of the previous node: ");
                scanf("%d", &key);
                insertAfter(head, new_data);
                break;
            case 3:
                printf("Enter the data to be inserted: ");
                scanf("%d", &new_data);
                append(&head, new_data);
                break;
            case 4:
                printf("Enter the key value of the node to be deleted: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;
            case 5:
                printf("The linked list is: ");
                printList(head);
                break;
            case 6:
                printf("Exiting the program.");
                exit(0);
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while(option != 6);

    return 0;
}