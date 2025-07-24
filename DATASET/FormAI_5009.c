//FormAI DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records in the database

// Struct for each record in the database
typedef struct {
    int id;
    char name[20];
    char email[30];
} Record;

// Struct for the database itself
typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

// Function prototypes
void init_db(Database *db);
void add_record(Database *db, Record new_record);
void delete_record(Database *db, int id);
void print_database(Database *db);
bool record_exists(Database *db, int id);

// Main function to test the database
int main(void) {
    Database my_db;
    init_db(&my_db);

    // Add some records to the database
    Record record1 = {1, "John Smith", "john.smith@gmail.com"};
    Record record2 = {2, "Jane Doe", "jane.doe@hotmail.com"};
    Record record3 = {3, "Bob Johnson", "bob.johnson@yahoo.com"};
    add_record(&my_db, record1);
    add_record(&my_db, record2);
    add_record(&my_db, record3);

    // Print the database
    printf("Original Database:\n");
    print_database(&my_db);

    // Delete a record and print the updated database
    printf("\nDeleting record with ID 2...\n");
    delete_record(&my_db, 2);
    printf("\nUpdated Database:\n");
    print_database(&my_db);

    // Try to delete a record that doesn't exist
    printf("\nAttempting to delete record with ID 2 again...\n");
    delete_record(&my_db, 2);

    return 0;
}

// Initialize the database (zero out the memory and set num_records to 0)
void init_db(Database *db) {
    memset(db->records, 0, sizeof(db->records));
    db->num_records = 0;
}

// Add a new record to the database
void add_record(Database *db, Record new_record) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Error: database is full\n");
        return;
    }
    db->records[db->num_records] = new_record;
    db->num_records++;
}

// Delete a record from the database by ID
void delete_record(Database *db, int id) {
    if (!record_exists(db, id)) {
        printf("Record with ID %d does not exist in database\n", id);
        return;
    }
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            break;
        }
    }
    for (; i < db->num_records-1; i++) {
        db->records[i] = db->records[i+1];
    }
    db->num_records--;
}

// Print the database
void print_database(Database *db) {
    printf("ID\tName\t\t\tEmail\n");
    printf("-------------------------------------------\n");
    int i;
    for (i = 0; i < db->num_records; i++) {
        printf("%d\t%-20s\t%s\n", db->records[i].id, db->records[i].name, db->records[i].email);
    }
}

// Check if a record exists in the database by ID
bool record_exists(Database *db, int id) {
    int i;
    for (i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            return true;
        }
    }
    return false;
}