//FormAI DATASET v1.0 Category: Database Indexing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char key[50];
    int value;
    struct node* next;
};

//function to create a new node
struct node* create_node(char* key, int value) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->key, key);
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

//function to insert a node into the linked list
void insert(struct node** head_ref, char* key, int value) {
    struct node* new_node = create_node(key, value);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct node* current = *head_ref;
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
}

//function to print the linked list
void print(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%s: %d\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    struct node* hash_table[26]; //creating an array of linked lists
    for (int i = 0; i < 26; i++) {
        hash_table[i] = NULL; //initializing each linked list to be empty
    }
    insert(&hash_table['a'-'a'], "apple", 5);
    insert(&hash_table['b'-'a'], "banana", 10);
    insert(&hash_table['c'-'a'], "cherry", 15);
    insert(&hash_table['a'-'a'], "apricot", 20);
    insert(&hash_table['b'-'a'], "blueberry", 25);
    insert(&hash_table['c'-'a'], "coconut", 30);
    print(hash_table['a'-'a']);
    print(hash_table['b'-'a']);
    print(hash_table['c'-'a']);
    return 0;
}