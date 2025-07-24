//FormAI DATASET v1.0 Category: Compression algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a structure for a linked list node
struct Node {
    char data;
    int count;
    struct Node *next;
};

// function to insert a new node into the linked list
void insert(char c, struct Node** head) {
    // if first node is empty, create a new node
    if (*head == NULL) {
        *head = (struct Node*) malloc(sizeof(struct Node));
        (*head)->data = c;
        (*head)->count = 1;
        (*head)->next = NULL;
    } else {
        // check if node already exists
        struct Node* curr = *head;
        while (curr != NULL) {
            if (curr->data == c) {
                curr->count++;
                return;
            }
            curr = curr->next;
        }
        // node doesn't exist, create a new node
        curr = (struct Node*) malloc(sizeof(struct Node));
        curr->data = c;
        curr->count = 1;
        curr->next = *head;
        *head = curr;
    }
}

// function to compress a string using a linked list compression algorithm
char* compress(char* s) {
    struct Node* head = NULL;
    // insert all characters in string into linked list
    for (int i = 0; i < strlen(s); i++) {
        insert(s[i], &head);
    }
    // count number of unique characters in linked list
    int count = 0;
    struct Node* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    // convert linked list into compressed string
    char* compressed = (char*) malloc(sizeof(char) * count * 3);
    curr = head;
    int index = 0;
    while (curr != NULL) {
        compressed[index++] = curr->data;
        compressed[index++] = ':';
        compressed[index++] = (char) (curr->count + '0');
        curr = curr->next;
    }
    // null-terminate the string
    compressed[index] = '\0';
    return compressed;
}

// main function to test linked list compression algorithm
int main() {
    char* s = "hello world";
    printf("Original string: %s\n", s);
    char* compressed = compress(s);
    printf("Compressed string: %s\n", compressed);
    free(compressed);
    return 0;
}