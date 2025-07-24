//FormAI DATASET v1.0 Category: Linked list operations ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

struct node {
   int data; 
   struct node *next; //pointer to the next node
};

void insert(struct node **head, int data) {
   struct node *n = (struct node*) malloc(sizeof(struct node)); //allocate memory for new node
   n->data = data; //set the data of new node to desired value
   n->next = *head; //set the next pointer of new node to the current head
   *head = n; //make the new node the head of the list
}

void delete(struct node **head, int data) {
   struct node *temp = *head, *prev; //temp stores reference to current node, prev stores reference to previous node 
   
   if (temp != NULL && temp->data == data) { //if head node matches the desired value
      *head = temp->next; //update head to point to next node
      free(temp); //delete current node
      return; //exit function
   }

   while (temp != NULL && temp->data != data) { //search for node to delete
      prev = temp; //update previous node
      temp = temp->next; //update current node
   }

   if (temp == NULL) return; //if desired node not found, exit function

   prev->next = temp->next; //update the previous node to point to the node after the current node
   free(temp); //delete current node
}

void printList(struct node *node) {
   while (node != NULL) { //iterate over all nodes in list
      printf("%d ", node->data); //print data of current node
      node = node->next; //update reference to current node
   }
}

int main() {
   struct node *head = NULL; //initialize head of list
   
   //insert some nodes at the start of the list
   insert(&head, 5);
   insert(&head, 2);
   insert(&head, 3);
   insert(&head, 9);
   insert(&head, 7);
   
   printf("Linked list before deletion: ");
   printList(head); //print list before deletion
   
   //delete node with value 3 from list
   delete(&head, 3);
   
   printf("\nLinked list after deletion: ");
   printList(head); //print list after deletion
   
   return 0; //exit program
}