//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Node structure for handling JSON data
typedef struct node {
    char *key;
    char *value;
    struct node *next;
} Node;

// Function to parse JSON string and store it as a linked list of nodes
Node* parse_json(char *json_string) {
    Node *head = NULL, *tail = NULL;
    char *token = strtok(json_string, ":,\"");

    while (token != NULL) {
        Node *node = malloc(sizeof(Node));
        node->key = strdup(token);

        token = strtok(NULL, ":,\"");
        node->value = strdup(token);

        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }

        token = strtok(NULL, ":,\"");
    }

    return head;
}

// Function to print the JSON data stored in linked list format
void print_json(Node *head) {
    for (Node *node = head; node != NULL; node = node->next) {
        printf("\"%s\": \"%s\"\n", node->key, node->value);
    }
}

int main() {
    char json_string[MAX_LENGTH];
    printf("Enter JSON string: ");
    fgets(json_string, MAX_LENGTH, stdin);
    json_string[strcspn(json_string, "\n")] = 0;

    Node *head = parse_json(json_string);

    printf("\nJSON Data:\n");
    print_json(head);

    return 0;
}