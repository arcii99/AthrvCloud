//FormAI DATASET v1.0 Category: Mailing list manager ; Style: distributed
// C Mailing list manager example program in a distributed style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 1000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct node {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
    struct node *next;
} node_t;

node_t *head[MAX_EMAILS];

void add_email(char *name, char *email) {
    int index = email[0] - 'a';
    node_t *new_node = malloc(sizeof(node_t));
    strncpy(new_node->name, name, MAX_NAME_LEN);
    strncpy(new_node->email, email, MAX_EMAIL_LEN);
    new_node->next = head[index];
    head[index] = new_node;
}

void remove_email(char *email) {
    int index = email[0] - 'a';
    node_t *current_node = head[index];
    node_t *previous_node = NULL;
    while (current_node != NULL) {
        if (strcmp(current_node->email, email) == 0) {
            if (previous_node == NULL) {
                head[index] = current_node->next;
            } else {
                previous_node->next = current_node->next;
            }
            free(current_node);
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    printf("Email not found: %s\n", email);
}

void print_emails() {
    printf("Mailing List:\n");
    for (int i = 0; i < MAX_EMAILS; i++) {
        node_t *current_node = head[i];
        while (current_node != NULL) {
            printf("%s, %s\n", current_node->name, current_node->email);
            current_node = current_node->next;
        }
    }
}

int main() {
    // Initialize head pointers to NULL
    for (int i = 0; i < MAX_EMAILS; i++) {
        head[i] = NULL;
    }

    // Add some test emails
    add_email("Alice", "alice@example.com");
    add_email("Bob", "bob@example.com");
    add_email("Charlie", "charlie@example.com");
    add_email("David", "david@example.com");
    print_emails();

    printf("\nRemoving Bob\n");
    remove_email("bob@example.com");
    print_emails();

    printf("\nAdding Eve\n");
    add_email("Eve", "eve@example.com");
    print_emails();

    return 0;
}