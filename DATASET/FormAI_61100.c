//FormAI DATASET v1.0 Category: Mailing list manager ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 30
#define EMAIL_LEN 50

struct mailing_list_node {
    char name[NAME_LEN];
    char email[EMAIL_LEN];
    struct mailing_list_node *next;
};

typedef struct mailing_list_node Node;
typedef Node* NodePtr;

NodePtr create_node(char *name, char *email);
void add_node(NodePtr *head, char *name, char *email);
void print_list(NodePtr head);
void delete_list(NodePtr *head);

int main() {
    NodePtr head = NULL;

    add_node(&head, "John Smith", "johnsmith@example.com");
    add_node(&head, "Jane Doe", "janedoe@example.com");
    add_node(&head, "Bob Johnson", "bobjohnson@example.com");

    printf("Printing Mailing List...\n");
    print_list(head);

    printf("Deleting Mailing List...\n");
    delete_list(&head);

    return 0;
}

NodePtr create_node(char *name, char *email) {
    NodePtr new_node = (NodePtr) malloc(sizeof(Node));
    if (new_node != NULL) {
        strcpy(new_node->name, name);
        strcpy(new_node->email, email);
        new_node->next = NULL;
    }
    return new_node;
}

void add_node(NodePtr *head, char *name, char *email) {
    NodePtr new_node = create_node(name, email);
    if (new_node != NULL) {
        if (*head == NULL) {
            *head = new_node;
        } else {
            NodePtr current_node = *head;
            while (current_node->next != NULL) {
                current_node = current_node->next;
            }
            current_node->next = new_node;
        }
    }
}

void print_list(NodePtr head) {
    if (head == NULL) {
        printf("Mailing List is Empty.\n");
    } else {
        NodePtr current_node = head;
        while (current_node != NULL) {
            printf("%s (%s)\n", current_node->name, current_node->email);
            current_node = current_node->next;
        }
    }
}

void delete_list(NodePtr *head) {
    while (*head != NULL) {
        NodePtr current_node = *head;
        *head = (*head)->next;
        free(current_node);
    }
}