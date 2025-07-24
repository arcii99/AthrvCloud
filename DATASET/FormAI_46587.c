//FormAI DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

Record database[MAX_RECORDS];
int num_records = 0;

// Indexing function
int hash(const char* name) {
    int hash_val = 0;
    for (int i = 0; i < strlen(name); i++) {
        hash_val += name[i];
    }
    return hash_val % MAX_RECORDS; // modulo to ensure hash fits within array bounds
}

// Insert a record into the database
void insert(const Record* record) {
    int index = hash(record->name);
    if (database[index].id == 0) {
        database[index] = *record;
        num_records++;
    } else {
        // Linear probing collision resolution
        while (database[index].id != 0) {
            index = (index + 1) % MAX_RECORDS;
        }
        database[index] = *record;
        num_records++;
    }
}

// Find a record by name
Record* find(const char* name) {
    int index = hash(name);
    if (strcmp(database[index].name, name) == 0) {
        return &database[index];
    } else {
        // Linear probing collision resolution
        while (strcmp(database[index].name, name) != 0) {
            index = (index + 1) % MAX_RECORDS;
            if (database[index].id == 0) {
                return NULL;
            }
        }
        return &database[index];
    }
}

int main() {
    Record r1 = { 1, "John Doe" };
    insert(&r1);
    Record r2 = { 2, "Jane Smith" };
    insert(&r2);

    Record* found = find("John Doe");
    if (found) {
        printf("Found record: id=%d name=%s\n", found->id, found->name);
    } else {
        printf("Record not found\n");
    }
    return 0;
}