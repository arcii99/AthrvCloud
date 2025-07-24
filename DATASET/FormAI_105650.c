//FormAI DATASET v1.0 Category: Database Indexing System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASH_SIZE 101

struct node {
    int key;
    char value[50];
    struct node *next;
};

struct node *hashtable[HASH_SIZE];

// This function takes a key and returns the hash value.
int hash(int key) {
    return key % HASH_SIZE;
}

// This function initializes the hashtable
void init() {
    int i;
    for (i = 0; i < HASH_SIZE; i++) {
        hashtable[i] = NULL;
    }
}

// This function inserts a node into the hashtable
void insert(int key, char value[]) {
    int h = hash(key);
    struct node *new_node = malloc(sizeof(struct node));
    new_node->key = key;
    strcpy(new_node->value, value);
    new_node->next = hashtable[h];
    hashtable[h] = new_node;
}

// This function searches for a node in the hashtable and returns it, or NULL if it is not found
struct node *search(int key) {
    int h = hash(key);
    struct node *p = hashtable[h];
    while (p != NULL && p->key != key) {
        p = p->next;
    }
    return p;
}

// This function removes a node from the hashtable
void remove_node(int key) {
    int h = hash(key);
    struct node *p = hashtable[h];
    struct node *prev = NULL;
    while (p != NULL && p->key != key) {
        prev = p;
        p = p->next;
    }
    if (p != NULL) {
        if (prev == NULL) {
            hashtable[h] = p->next;
        } else {
            prev->next = p->next;
        }
        free(p);
    }
}

// This function prints the contents of the hashtable
void print() {
    int i;
    for (i = 0; i < HASH_SIZE; i++) {
        struct node *p = hashtable[i];
        printf("%d: ", i);
        while (p != NULL) {
            printf("(%d, %s) ", p->key, p->value);
            p = p->next;
        }
        printf("\n");
    }
}

int main() {
    init();

    // Insert some nodes
    insert(1, "apple");
    insert(2, "banana");
    insert(3, "cherry");

    // Print the contents of the hashtable
    print();

    // Search for a node and print its value
    struct node *p = search(2);
    if (p != NULL) {
        printf("%s\n", p->value);
    }

    // Remove a node
    remove_node(1);

    // Print the contents of the hashtable
    print();

    return 0;
}