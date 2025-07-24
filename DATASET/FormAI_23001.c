//FormAI DATASET v1.0 Category: Ebook reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} Node;

Node* createNode(int data){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head){
    if (head == NULL) return;
    printf("%d ", head->data);
    printList(head->next);
}

void insertNode(Node** head, int data){
    if (*head == NULL){
        *head = createNode(data);
        return;
    }
    insertNode(&((*head)->next), data);
}

void deleteList(Node* head){
    if (head == NULL) return;
    deleteList(head->next);
    free(head);
}

int main(){
    Node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    printf("List created: ");
    printList(head);
    deleteList(head);
    return 0;
}