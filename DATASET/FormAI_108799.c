//FormAI DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct LinkedList{
    struct Node* head;
};

void addNode(struct LinkedList* list, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void displayLinkedList(struct LinkedList* list){
    struct Node* ptr = list->head;
    printf("LinkedList: ");
    while(ptr!= NULL){
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main(){
    struct LinkedList* numberList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    addNode(numberList, 4);
    addNode(numberList, 5);
    addNode(numberList, 7);
    addNode(numberList, 9);
    addNode(numberList, 3);
    displayLinkedList(numberList);
    return 0;
}