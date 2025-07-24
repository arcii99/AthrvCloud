//FormAI DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>

// structure to define a node
struct Node {
   int data;
   struct Node* next;
};

// Function to insert at the beginning of the linked list
void insertAtBeginning(struct Node** head, int num) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = num;
   newNode->next = *head;
   *head = newNode;
   printf("\n%d has been inserted at the beginning of the linked list", num);
}

// Function to insert at the end of the linked list
void insertAtEnd(struct Node** head, int num) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   struct Node* last = *head;
   newNode->data = num;
   newNode->next = NULL;
   if (*head == NULL) {
      *head = newNode;
      printf("\n%d has been inserted at the end of the linked list", num);
      return;
   }
   while (last->next != NULL)
      last = last->next;
   last->next = newNode;
   printf("\n%d has been inserted at the end of the linked list", num);
}

// Function to delete a node with a given key
void deleteNode(struct Node** head, int key) {
   struct Node* temp = *head, *prev;
   if (temp != NULL && temp->data == key) {
      *head = temp->next;
      free(temp);
      printf("\n%d has been deleted from the linked list", key);
      return;
   }
   while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next;
   }
   if (temp == NULL) {
      printf("\n%d not found in the linked list", key);
      return;
   }
   prev->next = temp->next;
   free(temp);
   printf("\n%d has been deleted from the linked list", key);
}

// Function to display the linked list
void displayList(struct Node* head) {
   printf("\nLinked List: ");
   while (head != NULL) {
      printf("%d ", head->data);
      head = head->next;
   }
}

int main() {
   struct Node* head = NULL;
   int choice, num;
   while(1){
      printf("\nPlease select an option\n");
      printf("1- Insert at the Beginning\n");
      printf("2- Insert at the End\n");
      printf("3- Delete a Node\n");
      printf("4- Display List\n");
      printf("5- Exit\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);
      switch(choice){
         case 1: 
            printf("\nEnter the number to be inserted: ");
            scanf("%d", &num);
            insertAtBeginning(&head, num);
            break;
         case 2: 
            printf("\nEnter the number to be inserted: ");
            scanf("%d", &num);
            insertAtEnd(&head, num);
            break;
         case 3: 
            printf("\nEnter the number to be deleted: ");
            scanf("%d", &num);
            deleteNode(&head, num);
            break;
         case 4: 
            displayList(head);
            break;
         case 5: 
            exit(0);
         default: 
            printf("\nInvalid choice.");
      }
   }
   return 0;
}