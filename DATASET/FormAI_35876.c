//FormAI DATASET v1.0 Category: Memory management ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void push(struct node **head_ref, int new_data){

    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int pop(struct node **head_ref){

    struct node *temp = *head_ref;
    (*head_ref) = (*head_ref)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(struct node **head_ref){
    return (*head_ref)->data;
}

int main(){
    struct node* top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    printf("Popped element: %d\n", pop(&top));
    printf("Top element: %d\n", peek(&top));
    push(&top, 40);
    printf("Top element: %d\n", peek(&top));
    return 0;
}