//FormAI DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// define a struct for the index entry of the database
typedef struct {
    int key;
    int block;
    int offset;
} IndexEntry;

// declare functions to be used later
void insert_entry(IndexEntry *entries, int *num_entries, int key, int block, int offset);
int search_entry(IndexEntry *entries, int num_entries, int key);
void print_entries(IndexEntry *entries, int num_entries);

int main() {
    int num_entries = 0;
    IndexEntry entries[100];
    
    // insert some entries into the database index
    insert_entry(entries, &num_entries, 10, 0, 0);
    insert_entry(entries, &num_entries, 15, 1, 0);
    insert_entry(entries, &num_entries, 20, 1, 1);
    insert_entry(entries, &num_entries, 25, 2, 0);
    insert_entry(entries, &num_entries, 30, 2, 1);
    
    // print out all entries in the index
    printf("All Entries:\n");
    print_entries(entries, num_entries);
    
    // search for an entry with key 20
    int index = search_entry(entries, num_entries, 20);
    if (index == -1) {
        printf("Entry not found\n");
    } else {
        printf("Entry found at index %d\n", index);
    }
    
    return 0;
}

void insert_entry(IndexEntry *entries, int *num_entries, int key, int block, int offset) {
    entries[*num_entries].key = key;
    entries[*num_entries].block = block;
    entries[*num_entries].offset = offset;
    *num_entries += 1;
}

int search_entry(IndexEntry *entries, int num_entries, int key) {
    int i;
    for (i = 0; i < num_entries; i++) {
        if (entries[i].key == key) {
            return i;
        }
    }
    return -1;
}

void print_entries(IndexEntry *entries, int num_entries) {
    int i;
    for (i = 0; i < num_entries; i++) {
        printf("Key: %d, Block: %d, Offset: %d\n", entries[i].key, entries[i].block, entries[i].offset);
    }
}