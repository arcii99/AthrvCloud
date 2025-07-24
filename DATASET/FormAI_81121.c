//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void print_list(Node* head) {
    printf("Linked List: ");
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = create_node(1);
    Node* node2 = create_node(2);
    Node* node3 = create_node(3);
    Node* node4 = create_node(4);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;

    printf("Linked List Visualization: \n\n");
    printf("             _______        _______        _______       _______\n");
    printf("            |       |      |       |      |       |     |       |\n");
    printf("head----->  |   1   |----> |   2   |----> |   3   |---->|   4   |---->NULL\n");
    printf("            |_______|      |_______|      |_______|     |_______|\n");

    printf("\n");
    print_list(head);

    return 0;
}