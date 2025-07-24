//FormAI DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 1001

// A linked list node to store a record
typedef struct node {
    int key;
    char name[50];
    struct node* next;
} Node;

// A hash table struct that contains a pointer to an array of linked lists
typedef struct {
    Node* hash_table[HASH_TABLE_SIZE];
} HashTable;

// A hash function that generates a hash value for the given key
int hash(int key) {
    return key % HASH_TABLE_SIZE;
}

// A function to add a record to the hash table
void add_record(HashTable* ht, int key, char* name) {
    Node* new_node = (Node*) malloc(sizeof(Node));  // create a new node
    new_node->key = key;
    strcpy(new_node->name, name);
    new_node->next = NULL;
    
    int index = hash(key);  // get the index of the linked list
    Node* head = ht->hash_table[index];  // get the head of the linked list
    
    if (head == NULL) {  // if the linked list is empty
        ht->hash_table[index] = new_node;  // add the new node as the head
    } else {
        Node* last_node = head;
        
        while (last_node->next != NULL) {  // find the last node in the linked list
            last_node = last_node->next;
        }
        
        last_node->next = new_node;  // add the new node to the end of the linked list
    }
}

// A function to search for a record in the hash table
void search_record(HashTable* ht, int key) {
    int index = hash(key);  // get the index of the linked list
    Node* head = ht->hash_table[index];  // get the head of the linked list
    
    if (head == NULL) {  // if the linked list is empty
        printf("Record not found\n");
    } else {
        Node* node = head;
        
        while (node != NULL) {  // traverse the linked list
            if (node->key == key) {  // if the key matches
                printf("Name: %s\n", node->name);  // print the name
                return;
            }
            
            node = node->next;
        }
        
        printf("Record not found\n");  // if no match is found
    }
}

int main() {
    HashTable ht;
    memset(ht.hash_table, 0, sizeof(ht.hash_table));  // initialize the hash table
    
    // add some sample records
    add_record(&ht, 123, "John");
    add_record(&ht, 456, "Jane");
    add_record(&ht, 789, "Bob");
    add_record(&ht, 321, "Alice");
    add_record(&ht, 654, "Dave");
    add_record(&ht, 987, "Eve");
    
    // search for some records
    search_record(&ht, 123);
    search_record(&ht, 456);
    search_record(&ht, 789);
    search_record(&ht, 321);
    search_record(&ht, 654);
    search_record(&ht, 987);
    search_record(&ht, 111);
    
    return 0;
}