//FormAI DATASET v1.0 Category: Linked list operations ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
  int data;
  struct node *next;
}node;

node *createNode(int val) {           //creating a new node
  node *newNode = malloc(sizeof(node));
  newNode->data = val;
  newNode->next = NULL;
  return newNode;
}

void insertAtBeginning(node **head, int val) {   //Inserting a new node at the beginning of the list
  node *newNode = createNode(val);
  newNode->next = *head;
  *head = newNode;
  printf("%d inserted at the beginning\n", val);
}

void insertAtEnd(node **head, int val) {   //Inserting a new node at the end of the list
  node *newNode = createNode(val);
  if(*head == NULL) {
    *head = newNode;
    return;
  }
  node *ptr = *head;
  while(ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = newNode;
  printf("%d inserted at the end\n", val);
}

void insertAtPosition(node **head, int val, int pos) {   //Inserting a new node at the specified position
  if(pos < 1) {
    printf("Invalid position\n");
    return;
  }
  if(pos == 1) {
    insertAtBeginning(head, val);
    return;
  }
  node *newNode = createNode(val);
  node *ptr = *head;
  int count = 1;
  while(count < pos-1) {
    if(ptr == NULL) {
      printf("Invalid position\n");
      return;
    }
    ptr = ptr->next;
    count++;
  }
  newNode->next = ptr->next;
  ptr->next = newNode;
  printf("%d inserted at position %d\n", val, pos);
}

void deleteFromBeginning(node **head) {    //Deleting the first node in the list
  if(*head == NULL) {
    printf("List is empty\n");
    return;
  }
  node *temp = *head;
  *head = (*head)->next;
  printf("%d deleted from beginning\n", temp->data);
  free(temp);
}

void deleteFromEnd(node **head) {
  if(*head == NULL) {    //Deleting the last node in the list
    printf("List is empty\n");
    return;
  }
  node *temp = *head;
  if(temp->next == NULL) {
    *head = NULL;
    printf("%d deleted from the end\n", temp->data);
    free(temp);
    return;
  }
  while(temp->next->next != NULL) {
    temp = temp->next;
  }
  printf("%d deleted from the end\n", temp->next->data);
  free(temp->next);
  temp->next = NULL;
}

void deleteFromPosition(node **head, int pos) {   //Deleting a node from a specified position
  if(*head == NULL) {
    printf("List is empty\n");
    return;
  }
  if(pos < 1) {
    printf("Invalid position\n");
    return;
  }
  if(pos == 1) {
    deleteFromBeginning(head);
    return;
  }
  node *temp = *head;
  int count = 1;
  while(count < pos-1) {
    if(temp == NULL) {
      printf("Invalid position\n");
      return;
    }
    temp = temp->next;
    count++;
  }
  if(temp->next == NULL) {
    printf("Invalid position\n");
    return;
  }
  printf("%d deleted from position %d\n", temp->next->data, pos);
  node *temp2 = temp->next;
  temp->next = temp2->next;
  free(temp2);
}

void display(node *head) {    //Displaying the elements of the list
  node *ptr = head;
  if(ptr == NULL) {
    printf("List is empty\n");
    return;
  }
  while(ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

int main() {
  node *head = NULL;
  int choice, val, pos;
  while(1) {
    printf("********** C Linked List Operations **********\n");
    printf("1. Insert at beginning\n2. Insert at end\n3. Insert at position\n4. Delete from beginning\n5. Delete from end\n6. Delete from position\n7. Display\n8. Exit\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter the value to be inserted: ");
        scanf("%d", &val);
        insertAtBeginning(&head, val);
        break;
      case 2:
        printf("Enter the value to be inserted: ");
        scanf("%d", &val);
        insertAtEnd(&head, val);
        break;
      case 3:
        printf("Enter the value to be inserted: ");
        scanf("%d", &val);
        printf("Enter the position: ");
        scanf("%d", &pos);
        insertAtPosition(&head, val, pos);
        break;
      case 4:
        deleteFromBeginning(&head);
        break;
      case 5:
        deleteFromEnd(&head);
        break;
      case 6:
        printf("Enter the position: ");
        scanf("%d", &pos);
        deleteFromPosition(&head, pos);
        break;
      case 7:
        display(head);
        break;
      case 8:
        printf("Exiting the program...\n");
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}