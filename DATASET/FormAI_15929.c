//FormAI DATASET v1.0 Category: Data structures visualization ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node* next;
};

void insertAtBeginning(struct Node** head, int data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = data;
   new_node->next = (*head);
   (*head) = new_node;
}

void deleteNode(struct Node** head, int key) {
   struct Node *temp = *head, *prev;
   
   if (temp != NULL && temp->data == key) {
      *head = temp->next;
      free(temp);
      return;
   }

   while (temp != NULL && temp->data != key) {
      prev = temp;
      temp = temp->next; 
   }

   if (temp == NULL) return;
   prev->next = temp->next;
   free(temp); 
}

void displayList(struct Node *head) {
   while (head != NULL) {
      printf("%d -> ", head->data);
      head = head->next;
   }
   printf("NULL\n");
}

int main() {
   struct Node* head = NULL;

   insertAtBeginning(&head, 5); 
   insertAtBeginning(&head, 3);
   insertAtBeginning(&head, 1);
   insertAtBeginning(&head, 7);

   printf("Initial Linked List:\n");
   displayList(head);

   deleteNode(&head, 3);

   printf("Linked List after deleting node with key 3:\n");
   displayList(head);

   deleteNode(&head, 1);

   printf("Linked List after deleting node with key 1:\n");
   displayList(head);

   return 0;
}