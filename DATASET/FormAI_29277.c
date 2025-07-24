//FormAI DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* currentNode = *head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        return;
    }
    if ((*head)->data == data) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node* prevNode = *head;
    Node* currentNode = (*head)->next;
    while (currentNode != NULL && currentNode->data != data) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) {
        return;
    }
    prevNode->next = currentNode->next;
    free(currentNode);
}

void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List: ");
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
}

int main() {
    Node* head = NULL;
    printf("Welcome to the futuristic Linked List Program!\n\n");
    while (1) {
        printf("\nAvailable Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete Node\n");
        printf("4. Print List\n");
        printf("5. Exit\n");
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int data;
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            }
            case 2: {
                int data;
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            }
            case 3: {
                int data;
                printf("Enter data to be deleted: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            }
            case 4: {
                printList(head);
                break;
            }
            case 5: {
                printf("\nThank you for using the futuristic Linked List Program!\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice! Please try again.\n");
            }
        }
    }
    return 0;
}