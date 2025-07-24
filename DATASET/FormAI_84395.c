//FormAI DATASET v1.0 Category: Database Indexing System ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define INDEX_SIZE 1000

// Struct to hold information about each entry in the database
struct Entry {
    int id;
    char name[50];
    char address[100];
    int age;
};

// Struct to hold information about each index in the database
struct Index {
    int key;
    int value;
};

// Array to hold the entries in the database
struct Entry database[10000];
int entries_count = 0;

// Hash table to store the indexes
struct Index index_table[INDEX_SIZE];
int index_table_count = 0;

// Hash function for the index hash table
int hash(int key) {
    return key % INDEX_SIZE;
}

// Function to insert an entry into the database
void insert_entry(int id, char* name, char* address, int age) {
    database[entries_count].id = id;
    strcpy(database[entries_count].name, name);
    strcpy(database[entries_count].address, address);
    database[entries_count].age = age;
    entries_count++;
    
    // Calculate the index key based on the ID
    int key = id % INDEX_SIZE;

    // Check if an index with the same key already exists
    for(int i=0; i<index_table_count; i++) {
        if(index_table[i].key == key) {
            // If it does, update the value to point to the new entry
            index_table[i].value = entries_count-1;
            return;
        }
    }

    // If an index with the same key does not exist, add a new index to the table
    index_table[index_table_count].key = key;
    index_table[index_table_count].value = entries_count-1;
    index_table_count++;
}

// Function to search the database using an indexing algorithm
bool search_entry(int id, struct Entry* result) {
    // Calculate the index key based on the ID
    int key = id % INDEX_SIZE;

    // Search the index table for an index with the same key
    for(int i=0; i<index_table_count; i++) {
        if(index_table[i].key == key) {
            // If an index with the same key is found, use the value to retrieve the correct entry
            *result = database[index_table[i].value];
            return true;
        }
    }

    // If an index with the same key does not exist, return false
    return false;
}

// Example usage of the indexing system
int main() {
    insert_entry(1, "John Smith", "123 Main St", 25);
    insert_entry(2, "Jane Doe", "456 Oak St", 30);
    insert_entry(3, "Bob Johnson", "789 Elm St", 40);

    struct Entry result;

    if(search_entry(2, &result)) {
        printf("Entry found: ID=%d, Name=%s, Address=%s, Age=%d\n", result.id, result.name, result.address, result.age);
    } else {
        printf("Entry not found\n");
    }

    return 0;
}