//FormAI DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

Node *head = NULL;

void insert_node(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = head;
    head = new_node;
}

void compress_array(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        insert_node(arr[i]);
    }
}

void print_list() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("The compressed list is: ");
    Node *current_node = head;
    while (current_node != NULL) {
        printf("%d", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5, 5};
    int size = sizeof(arr) / sizeof(int);
    compress_array(arr, size);
    print_list();
    return 0;
}