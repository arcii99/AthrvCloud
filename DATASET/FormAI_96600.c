//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 256

typedef struct node {
    char data;
    struct node* next;
} Node;

void add_node(Node** head, char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void delete_list(Node* head) {
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

char* hash(char* input) {
    Node* hash_table[HASH_SIZE] = { NULL };
    int input_len = strlen(input);

    for (int i = 0; i < input_len; i++) {
        add_node(&hash_table[(int)input[i] % HASH_SIZE], input[i]);
    }

    char* hashed = (char*)malloc((HASH_SIZE + 1) * sizeof(char));
    int hashed_index = 0;

    for (int i = 0; i < HASH_SIZE; i++) {
        int count = 0;
        Node* current = hash_table[i];
        while (current != NULL) {
            count++;
            current = current->next;
        }
        hashed[hashed_index++] = count % 10 + '0';
    }
    hashed[hashed_index] = '\0';

    for (int i = 0; i < HASH_SIZE; i++) {
        delete_list(hash_table[i]);
    }

    return hashed;
}

int main() {
    char* input = "cryptography";
    char* hashed = hash(input);

    printf("%s: %s\n", input, hashed);

    free(hashed);

    return 0;
}