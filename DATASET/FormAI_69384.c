//FormAI DATASET v1.0 Category: Linked list operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* next;
};
 
void insert(struct node** head, int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
}
 
void delete(struct node** head, int key) {
    struct node* temp = *head, *prev;
 
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
 
void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}
 
int main() {
    struct node* head = NULL;
 
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
 
    printf("Before deletion: ");
    printList(head);
 
    delete(&head, 3);
 
    printf("\nAfter deletion: ");
    printList(head);
 
    return 0;
}