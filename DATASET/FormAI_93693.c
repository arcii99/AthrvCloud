//FormAI DATASET v1.0 Category: Graph representation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    int child_count;
    struct node *next;
    struct node **children;
};

typedef struct node Node;

Node *newNode(int data, int child_count) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->child_count = child_count;
    temp->next = NULL;
    temp->children = (Node**)malloc(child_count*sizeof(Node*));
    return temp;
}

void addChildren(Node *parent) {
    int i;
    for(i=0;i<parent->child_count;i++) {
        int data = parent->data*parent->data+i+1;
        int child_count = data%4+1;
        Node *child = newNode(data, child_count);
        parent->children[i] = child;
        addChildren(child);
    }
}

void printGraph(Node *head, int level) {
    int i;
    for(i=0;i<level;i++)
        printf("  ");
    printf("%d\n", head->data);
    for(i=0;i<head->child_count;i++)
        printGraph(head->children[i], level+1);
}

int main() {
    Node *head = newNode(1, 3);
    addChildren(head);
    printGraph(head, 0);
    return 0;
}