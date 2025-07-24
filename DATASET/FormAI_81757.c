//FormAI DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Struct to store a single record in the database
typedef struct {
    int id;
    char name[50];
    int age;
} Record;

// Struct to represent the database
typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Prints out all the records in the database
void print_database(Database* db) {
    printf("Records in the database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d\n", db->records[i].id);
        printf("Name: %s\n", db->records[i].name);
        printf("Age: %d\n\n", db->records[i].age);
    }
}

// Adds a new record to the database
void add_record(Database* db, int id, char* name, int age) {
    if (db->count == MAX_RECORDS) {
        printf("Sorry, the database is full!\n");
        return;
    }
    Record new_record = {id, "", age};
    strncpy(new_record.name, name, 49);
    db->records[db->count++] = new_record;
}

// Searches for a record in the database by ID
Record* find_record(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    printf("Sorry, no record found with ID %d.\n", id);
    return NULL;
}

int main() {
    // Create a new database
    Database db = {{0}, 0};
    
    // Add some records to the database
    add_record(&db, 1, "Alice", 25);
    add_record(&db, 2, "Bob", 30);
    add_record(&db, 3, "Charlie", 20);
    add_record(&db, 4, "David", 35);
    
    // Print out the database
    print_database(&db);
    
    // Search for a record by ID
    Record* record = find_record(&db, 2);
    if (record != NULL) {
        printf("Record found:\n");
        printf("ID: %d\n", record->id);
        printf("Name: %s\n", record->name);
        printf("Age: %d\n\n", record->age);
    }
    
    return 0;
}