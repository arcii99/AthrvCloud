//FormAI DATASET v1.0 Category: Data structures visualization ; Style: scalable
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node* next;
}Node;

void insert(Node** head, int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = data;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        Node* current = *head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

void visualize(Node* head){
    printf(" |  ");
    Node* current = head;
    while(current!=NULL){
        printf("%d", current->value);
        current=current->next;
        if(current!=NULL){
            printf(" -> ");
        }
    }
    printf(" -> NULL \n");
}

int main(){
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    printf("\nLinked List Visualization:\n\n");
    visualize(head);
    return 0;
}