//FormAI DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_RECORDS 10000

typedef struct {
    char key[MAX_KEY_LENGTH];
    int address;
} IndexEntry;

typedef struct {
    char data[100];
} Record;

typedef struct {
    IndexEntry* entries[MAX_RECORDS];
    int num_entries;
} Index;

void add_entry(Index* index, const char* key, const int address) {
    if (index->num_entries == MAX_RECORDS) {
        printf("Index full\n");
        return;
    }

    IndexEntry* entry = malloc(sizeof(IndexEntry));
    strncpy(entry->key, key, MAX_KEY_LENGTH);
    entry->address = address;

    index->entries[index->num_entries++] = entry;
}

int search_index(Index* index, const char* key) {
    for (int i = 0; i < index->num_entries; i++) {
        if (strcmp(index->entries[i]->key, key) == 0) {
            return index->entries[i]->address;
        }
    }

    return -1;
}

int main() {
    Index index;
    index.num_entries = 0;

    Record records[MAX_RECORDS];
    int num_records = 0;

    // Populate records
    strcpy(records[num_records++].data, "Record 1");
    strcpy(records[num_records++].data, "Record 2");
    strcpy(records[num_records++].data, "Record 3");
    strcpy(records[num_records++].data, "Record 4");
    strcpy(records[num_records++].data, "Record 5");

    // Add records to index
    add_entry(&index, "key1", 0);
    add_entry(&index, "key2", 1);
    add_entry(&index, "key3", 2);
    add_entry(&index, "key4", 3);
    add_entry(&index, "key5", 4);

    // Search for records using index
    int address = search_index(&index, "key3");
    if (address == -1) {
        printf("Record not found\n");
    } else {
        printf("Record found: \"%s\"\n", records[address].data);
    }

    return 0;
}