//FormAI DATASET v1.0 Category: Data structures visualization ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Linked_list {
    int size;
    struct Node *head;
} Linked_list;

void insert(Linked_list *list, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void print(Linked_list *list) {
    Node *tmp = list->head;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    Linked_list *list = malloc(sizeof(Linked_list));
    list->size = 0;
    list->head = NULL;

    insert(list, 1);
    insert(list, 2);
    insert(list, 3);
    insert(list, 4);
    insert(list, 5);

    printf("Linked list with %d elements:\n", list->size);
    print(list);

    return 0;
}