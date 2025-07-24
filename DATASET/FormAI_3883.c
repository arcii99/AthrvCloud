//FormAI DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* head = NULL;

Node* create_node(int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node) {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

void insert_node(int data) {
    Node *new_node = create_node(data);
    if (new_node) {
        new_node->next = head;
        head = new_node;
    }
}

void display_list() {
    Node *current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete_node(int data) {
    Node *current = head, *prev_node = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (prev_node) {
                prev_node->next = current->next;
            } else {
                head = current->next; // deleting first node
            }
            free(current);
            break;
        }
        prev_node = current;
        current = current->next;
    }
}

void clear_list() {
    Node *current = head, *next_node = NULL;

    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    head = NULL;
}

int main() {
    insert_node(5);
    insert_node(10);
    insert_node(20);
    insert_node(30);

    display_list();

    delete_node(5);
    delete_node(20);

    display_list();

    clear_list();
    return 0;
}