//FormAI DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

typedef struct {
    struct Node* head;
} Index;

// Add a new element to the index
void add(Index* index, int value) {
    struct Node* new_node = malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = index->head;
    index->head = new_node;
}

// Search for an element in the index
int search(Index* index, int value) {
    struct Node* current_node = index->head;
    while (current_node != NULL) {
        if (current_node->value == value) {
            return 1;
        }
        current_node = current_node->next;
    }
    return 0;
}

int main() {
    Index my_index;
    my_index.head = NULL;

    add(&my_index, 10);
    add(&my_index, 20);
    add(&my_index, 30);

    int search_val = 20;
    printf("Search result for %d: %d\n", search_val, search(&my_index, search_val));

    search_val = 40;
    printf("Search result for %d: %d\n", search_val, search(&my_index, search_val));

    return 0;
}