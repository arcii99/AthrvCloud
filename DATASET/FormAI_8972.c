//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct linked_list {
    Node* head;
    int size;
} LinkedList;

LinkedList* createLinkedList() {
    LinkedList* llist = (LinkedList*) malloc(sizeof(LinkedList));
    llist->head = NULL;
    llist->size = 0;
    return llist;
}

void traverseLinkedList(LinkedList* llist) {
    printf("Linked List Visualization:\n\n");
    Node* temp = llist->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("\nLinked List Size: %d\n\n", llist->size);
}

void insertBeginning(LinkedList* llist, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = llist->head;
    llist->head = node;
    llist->size++;
    printf("Inserted %d at the beginning of the linked list!\n", data);
}

int main() {
    LinkedList* llist = createLinkedList();
    insertBeginning(llist, 10);
    insertBeginning(llist, 20);
    insertBeginning(llist, 30);
    traverseLinkedList(llist);
    return 0;
}