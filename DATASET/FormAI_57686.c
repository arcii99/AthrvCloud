//FormAI DATASET v1.0 Category: Ebook reader ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
    char* data;
    struct NODE* next;
} Node;

void freeList(Node* head) {
    if(head == NULL){
        return;
    }
    freeList(head->next);
    free(head->data);
    free(head);
}

void printList(Node* head) {
    if(head == NULL){
        return;
    }
    printf("%s\n", head->data);
    printList(head->next);
}

void insert(Node** head, char* data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    
    new_node->data = data;
    new_node->next = *head;
    
    *head = new_node;
}

int main(){
    Node* head = NULL;
    
    insert(&head, "Chapter 1");
    insert(&head, "Chapter 2");
    insert(&head, "Chapter 3");
    insert(&head, "Chapter 4");
    insert(&head, "Chapter 5");
    
    printf("Contents of Ebook:\n");
    printList(head);
    freeList(head);
    
    return 0;
}