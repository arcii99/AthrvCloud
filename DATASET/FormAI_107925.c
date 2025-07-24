//FormAI DATASET v1.0 Category: Linked list operations ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the node
typedef struct node {
    int data;
    struct node *next;
} Node;

// Create a function to create a new node
Node *createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a function to insert a node at the beginning of a linked list
void insertAtBegin(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Create a function to insert a node at the end of a linked list
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Create a function to delete a node from the beginning of a linked list
void deleteFromBegin(Node **head) {
    if (*head == NULL) {
        printf("The linked list is empty\n");
        return;
    }
    Node *temp = *head;
    *head = temp->next;
    free(temp);
}

// Create a function to delete a node from the end of a linked list
void deleteFromEnd(Node **head) {
    if (*head == NULL) {
        printf("The linked list is empty\n");
        return;
    }
    Node *current = *head;
    Node *previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    free(current);
}

// Create a function to display the linked list
void displayList(Node *head) {
    Node *current = head;
    printf("The linked list is: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    printf("Welcome to my linked list program!\n\n");
    while (1) {
        int option, data;
        printf("Please select an option:\n");
        printf("1 - Insert at the beginning\n");
        printf("2 - Insert at the end\n");
        printf("3 - Delete from the beginning\n");
        printf("4 - Delete from the end\n");
        printf("5 - Display the linked list\n");
        printf("6 - Exit the program\n");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Please enter the data to be inserted at the beginning: ");
                scanf("%d", &data);
                insertAtBegin(&head, data);
                printf("The data %d has been inserted at the beginning of the linked list\n\n", data);
                break;
            case 2:
                printf("Please enter the data to be inserted at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                printf("The data %d has been inserted at the end of the linked list\n\n", data);
                break;
            case 3:
                deleteFromBegin(&head);
                printf("The first node in the linked list has been deleted\n\n");
                break;
            case 4:
                deleteFromEnd(&head);
                printf("The last node in the linked list has been deleted\n\n");
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                printf("Thank you for using my program!\n");
                exit(0);
            default:
                printf("Invalid option selected. Please try again.\n\n");
                break;
        }
    }
    return 0;
}