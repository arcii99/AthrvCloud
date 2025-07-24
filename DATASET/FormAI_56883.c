//FormAI DATASET v1.0 Category: Linked list operations ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *head = NULL;

void insert(int num){
    node *link = (node*) malloc(sizeof(node));
    link->data = num;
    link->next = head;
    head = link;
}

int delete(){
    if (head == NULL){
        printf("\n List is empty.");
        return -1;
    }
    int val = head->data;
    node *temp = head;
    head = head->next;
    free(temp);
    return val;
}

void display(){
    printf("\n[ ");
    node *current = head;
    while (current!= NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf(" ]");
}

int main(){
    insert(1);
    insert(2);
    insert(3);
    display();
    printf("\nDeleted node with value %d", delete());
    display();
    return 0;
}