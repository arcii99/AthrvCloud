//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person{
    char name[20];
    int age;
    char gender;
}Person;

typedef struct node{
    Person data;
    struct node* next;
}Node;

Node* head = NULL;

void insert(Person p){
    Node* newNode = (Node*) malloc(sizeof(Node));
    if(!newNode) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = p;
    newNode->next = head;
    head = newNode;
}

void printList(){
    Node* current = head;
    while(current){
        printf("%s is %d years old and their gender is %c.\n", current->data.name, current->data.age, current->data.gender);
        current = current->next;
    }
}

int main(){
    Person p1 = {"John", 25, 'M'};
    Person p2 = {"Emily", 30, 'F'};
    Person p3 = {"Sam", 42, 'M'};
    insert(p1);
    insert(p2);
    insert(p3);
    printList();
    return 0;
}