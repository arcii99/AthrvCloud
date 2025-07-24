//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: energetic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// the size of hash table
#define HASH_TABLE_SIZE 100001

// the structure of node in hash table
typedef struct Node {
    char* key;
    struct Node* next;
} Node;

// the hash table
Node* hashtable[HASH_TABLE_SIZE];

// function to calculate the hash value of a string
unsigned long hash(char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash % HASH_TABLE_SIZE;
}

// function to add a key to the hash table
void add_key(char* key) {
    // calculate the hash value of the key
    unsigned long hash_value = hash(key);

    // create a new node
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->key = key;
    new_node->next = NULL;

    // insert the new node at the head of the linked list
    if (hashtable[hash_value] == NULL) {
        hashtable[hash_value] = new_node;
    } else {
        new_node->next = hashtable[hash_value];
        hashtable[hash_value] = new_node;
    }
}

// function to check if a key is in the hash table
int check_key(char* key) {
    // calculate the hash value of the key
    unsigned long hash_value = hash(key);

    // traverse the linked list to find the key
    Node* node = hashtable[hash_value];
    while (node != NULL) {
        if (strcmp(node->key, key) == 0) {
            return 1;
        } else {
            node = node->next;
        }
    }

    return 0;
}

int main() {
    // example usage of the hash table
    add_key("hello");
    add_key("world");
    add_key("foo");
    add_key("bar");

    printf("%d\n", check_key("hello")); // output: 1
    printf("%d\n", check_key("world")); // output: 1
    printf("%d\n", check_key("foo")); // output: 1
    printf("%d\n", check_key("bar")); // output: 1
    printf("%d\n", check_key("baz")); // output: 0

    return 0;
}