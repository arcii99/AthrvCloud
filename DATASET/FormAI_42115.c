//FormAI DATASET v1.0 Category: Data mining ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};

typedef struct node Node;

void addNode(Node **head, int n){
    Node *newNode = malloc(sizeof(Node));
    newNode->value = n;
    newNode->next = *head;
    *head = newNode;
}

int findLargest(Node *head){
    int largest = head->value;
    Node *temp = head->next;
    while(temp != NULL){
        if(temp->value > largest){
            largest = temp->value;
        }
        temp = temp->next;
    }
    return largest;
}

int main(){
    Node *list = NULL;
    addNode(&list, 5);
    addNode(&list, 12);
    addNode(&list, 7);
    addNode(&list, 18);
    printf("The largest value in the list is %d\n", findLargest(list));
    return 0;
}