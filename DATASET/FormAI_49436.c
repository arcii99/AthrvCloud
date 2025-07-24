//FormAI DATASET v1.0 Category: Data structures visualization ; Style: detailed
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *createNode(int data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(node **head, int data){
    node *newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    node *temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display(node *head){
    node *temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    node *head=NULL;

    insert(&head,10);
    insert(&head,20);
    insert(&head,30);

    display(head);

    return 0;
}