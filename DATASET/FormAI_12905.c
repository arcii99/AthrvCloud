//FormAI DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createLinkedList(int* arr, int size);
void printLinkedList(Node* head);

int main() {
    int size = 5;
    int arr[5] = {4, 7, 2, 9, 1};
    Node* head = createLinkedList(arr, size);
    printLinkedList(head);
    return 0;
}

Node* createLinkedList(int* arr, int size) {
    Node* head = NULL;
    for (int i = 0; i < size; i++) {
        Node* curr = (Node*) malloc(sizeof(Node));
        if (curr == NULL) {
            printf("Error: Could not allocate memory for node.\n");
            return head;
        }
        curr->data = arr[i];
        curr->next = head;
        head = curr;
    }
    return head;
}

void printLinkedList(Node* head) {
    Node* curr = head;
    printf("NULL - ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}