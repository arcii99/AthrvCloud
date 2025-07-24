//FormAI DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_PHONE_LEN 10

struct Contact {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
};

struct Node {
    struct Node *left;
    struct Node *right;
    struct Contact contact;
};

struct Tree {
    struct Node *root;
};

void add_contact(struct Node **node, struct Contact contact);
void print_contacts(struct Node *node);
void free_tree(struct Node *node);
struct Contact create_contact(char *name, char *phone);
void add_contact_to_tree(struct Tree *tree, struct Contact contact, char *index_type);

int main() {
    struct Tree name_index;
    name_index.root = NULL;
    struct Tree phone_index;
    phone_index.root = NULL;

    add_contact_to_tree(&name_index, create_contact("John Doe", "1234567890"), "name");
    add_contact_to_tree(&name_index, create_contact("Jane Smith", "2345678901"), "name");
    add_contact_to_tree(&phone_index, create_contact("Bob Johnson", "3456789012"), "phone");
    add_contact_to_tree(&phone_index, create_contact("Mary Lee", "4567890123"), "phone");

    printf("Index by name:\n");
    print_contacts(name_index.root);
    free_tree(name_index.root);

    printf("\nIndex by phone:\n");
    print_contacts(phone_index.root);
    free_tree(phone_index.root);

    return 0;
}

void add_contact(struct Node **node, struct Contact contact) {
    if (*node == NULL) {
        *node = malloc(sizeof(struct Node));
        (*node)->left = NULL;
        (*node)->right = NULL;
        (*node)->contact = contact;
    } else if (strcmp(contact.name, (*node)->contact.name) < 0) {
        add_contact(&(*node)->left, contact);
    } else {
        add_contact(&(*node)->right, contact);
    }
}

void print_contacts(struct Node *node) {
    if (node != NULL) {
        print_contacts(node->left);
        printf("Name: %s, Phone: %s\n", node->contact.name, node->contact.phone);
        print_contacts(node->right);
    }
}

void free_tree(struct Node *node) {
    if (node != NULL) {
        free_tree(node->left);
        free_tree(node->right);
        free(node);
    }
}

struct Contact create_contact(char *name, char *phone) {
    struct Contact contact;
    strncpy(contact.name, name, MAX_NAME_LEN);
    strncpy(contact.phone, phone, MAX_PHONE_LEN);
    return contact;
}

void add_contact_to_tree(struct Tree *tree, struct Contact contact, char *index_type) {
    if (strcmp(index_type, "name") == 0) {
        add_contact(&tree->root, contact);
    } else if (strcmp(index_type, "phone") == 0) {
        add_contact(&tree->root, contact);
    } else {
        printf("Invalid index type specified\n");
    }
}