//FormAI DATASET v1.0 Category: Database Indexing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100
#define MAX_PHONE_LENGTH 20

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Record;

typedef struct {
    int id;
    int index;
} Index;

typedef struct {
    Record records[MAX_RECORDS];
    Index index[MAX_RECORDS];
    int size;
} Database;

int compare_indexes(const void *a, const void *b) {
    Index *ia = (Index *)a;
    Index *ib = (Index *)b;
    return (ia->id - ib->id);
}

void add_record(Database *db, int id, char *name, char *address, char *phone) {
    // Add the record
    Record new_record = {id};
    strncpy(new_record.name, name, MAX_NAME_LENGTH);
    strncpy(new_record.address, address, MAX_ADDRESS_LENGTH);
    strncpy(new_record.phone, phone, MAX_PHONE_LENGTH);
    db->records[db->size] = new_record;
    
    // Add the index
    Index new_index = {id, db->size};
    db->index[db->size] = new_index;
    db->size++;
    
    // Sort the indexes
    qsort(db->index, db->size, sizeof(Index), compare_indexes);
}

Record *find_record(Database *db, int id) {
    // Find the index
    Index key = {id};
    Index *result = bsearch(&key, db->index, db->size, sizeof(Index), compare_indexes);
    
    // Return null if the record was not found
    if (result == NULL) {
        return NULL;
    }
    
    // Return a pointer to the record
    return &db->records[result->index];
}

int main() {
    // Initialize the database
    Database db = {0};
    
    // Add some records
    add_record(&db, 1, "John Doe", "123 Main St", "(555) 555-1234");
    add_record(&db, 2, "Jane Smith", "456 Oak Ave", "(555) 555-5678");
    add_record(&db, 3, "Bob Johnson", "789 Elm St", "(555) 555-9012");
    
    // Find a record
    Record *result = find_record(&db, 2);
    if (result != NULL) {
        printf("Record found: %d, %s, %s, %s\n", result->id, result->name, result->address, result->phone);
    } else {
        printf("Record not found\n");
    }
    
    return 0;
}