//FormAI DATASET v1.0 Category: Linked list operations ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct node {
  int data;
  struct node *next;
} Node;

// Function to create a new node
Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a node at the beginning of the linked list
Node *insertAtBeginning(Node *head, int data) {
  Node *newNode = createNode(data);
  newNode->next = head;
  head = newNode;
  return head;
}

// Function to insert a node at the end of the linked list
Node *insertAtEnd(Node *head, int data) {
  Node *newNode = createNode(data);
  if (head == NULL) {
    head = newNode;
    return head;
  }
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

// Function to delete a node from the beginning of the linked list
Node *deleteFromBeginning(Node *head) {
  if (head == NULL) {
    printf("The linked list is empty\n");
    return head;
  }
  Node *temp = head;
  head = head->next;
  free(temp);
  return head;
}

// Function to delete a node from the end of the linked list
Node *deleteFromEnd(Node *head) {
  if (head == NULL) {
    printf("The linked list is empty\n");
    return head;
  } else if (head->next == NULL) {
    free(head);
    head = NULL;
    return head;
  }
  Node *temp = head;
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
  return head;
}

// Function to display the linked list
void display(Node *head) {
  printf("Linked List: ");
  Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  Node *head = NULL;
  int choice, data;
  do {
    printf("Enter Your Choice:\n");
    printf("1: Insert at the Beginning\n");
    printf("2: Insert at the End\n");
    printf("3: Delete from the Beginning\n");
    printf("4: Delete from the End\n");
    printf("5: Display the Linked List\n");
    printf("6: Exit\n");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        printf("Enter data to insert at beginning: ");
        scanf("%d", &data);
        head = insertAtBeginning(head, data);
        break;
      case 2:
        printf("Enter data to insert at end: ");
        scanf("%d", &data);
        head = insertAtEnd(head, data);
        break;
      case 3:
        head = deleteFromBeginning(head);
        break;
      case 4:
        head = deleteFromEnd(head);
        break;
      case 5:
        display(head);
        break;
      case 6:
        printf("Exiting...\n");
        break;
      default:
        printf("Invalid Choice\n");
        break;
    }
  } while (choice != 6);
  return 0;
}