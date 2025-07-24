//FormAI DATASET v1.0 Category: Memory management ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    size_t size;
    struct Node *next;
} Node;

static Node *head = NULL;

void *tcalloc(size_t nmemb, size_t size) {
    size_t total_size = nmemb * size;
    void *memory = malloc(total_size);
    if (memory == NULL) {
        return NULL;
    }
    Node *new_node = (Node*)memory;
    new_node->size = total_size;
    new_node->next = head;
    head = new_node;
    printf("Memory allocated successfully!\n");
    return memory;
}

void tfree(void *ptr) {
    Node *current_node = head;
    Node *prev_node = NULL;
    while (current_node != NULL) {
        if ((void*)current_node == ptr) {
            if (prev_node == NULL) {
                head = current_node->next;
            } else {
                prev_node->next = current_node->next;
            }
            free(ptr);
            printf("Memory freed successfully!\n");
            return;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
    printf("Invalid memory address received!\n");
}

int main() {
    int *numbers = tcalloc(5, sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        numbers[i] = i+1;
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }
    tfree(numbers);
    return 0;
}