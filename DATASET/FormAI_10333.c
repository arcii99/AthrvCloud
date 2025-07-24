//FormAI DATASET v1.0 Category: Database Indexing System ; Style: systematic
// A simple implementation of a database indexing system in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records we can hold
#define MAX_RECORDS 100

// Define the maximum length of a record's name
#define MAX_NAME_LEN 50

// Define the maximum length of a record's address
#define MAX_ADDRESS_LEN 100

// Define the maximum length of a record's phone number
#define MAX_PHONE_LEN 15

// Define a struct for a single record
struct Record {
    char name[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    char phone[MAX_PHONE_LEN];
};

// Define a struct for an index entry
struct IndexEntry {
    char key[MAX_NAME_LEN];
    int index;
};

// Define a struct for the database
struct Database {
    struct Record records[MAX_RECORDS];
    struct IndexEntry index[MAX_RECORDS];
    int num_records;
};

// Search for a record by name
int search_record_by_name(struct Database *db, char *name) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Search for a record by address
int search_record_by_address(struct Database *db, char *address) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].address, address) == 0) {
            return i;
        }
    }
    return -1;
}

// Search for a record by phone number
int search_record_by_phone(struct Database *db, char *phone) {
    for (int i = 0; i < db->num_records; i++) {
        if (strcmp(db->records[i].phone, phone) == 0) {
            return i;
        }
    }
    return -1;
}

// Add a new record to the database
void add_record_to_database(struct Database *db, struct Record *record) {
    // Add the record
    db->records[db->num_records] = *record;

    // Add an index entry for the record's name
    strcpy(db->index[db->num_records].key, record->name);
    db->index[db->num_records].index = db->num_records;

    // Increment the number of records in the database
    db->num_records++;
}

// Search for records by name
void search_records_by_name(struct Database *db, char *name) {
    int index = search_record_by_name(db, name);
    if (index == -1) {
        printf("No record found with name '%s'\n", name);
    } else {
        printf("Record found:\n");
        printf("Name: %s\nAddress: %s\nPhone: %s\n", 
            db->records[index].name, db->records[index].address, db->records[index].phone);
    }
}

// Search for records by address
void search_records_by_address(struct Database *db, char *address) {
    int index = search_record_by_address(db, address);
    if (index == -1) {
        printf("No record found with address '%s'\n", address);
    } else {
        printf("Record found:\n");
        printf("Name: %s\nAddress: %s\nPhone: %s\n",
            db->records[index].name, db->records[index].address, db->records[index].phone);
    }
}

// Search for records by phone number
void search_records_by_phone(struct Database *db, char *phone) {
    int index = search_record_by_phone(db, phone);
    if (index == -1) {
        printf("No record found with phone number '%s'\n", phone);
    } else {
        printf("Record found:\n");
        printf("Name: %s\nAddress: %s\nPhone: %s\n",
            db->records[index].name, db->records[index].address, db->records[index].phone);
    }
}

int main() {
    struct Database db;
    db.num_records = 0;

    // Add some example records
    struct Record record1, record2;
    strcpy(record1.name, "John Doe");
    strcpy(record1.address, "123 Main St.");
    strcpy(record1.phone, "555-1234");
    add_record_to_database(&db, &record1);

    strcpy(record2.name, "Jane Smith");
    strcpy(record2.address, "456 Oak St.");
    strcpy(record2.phone, "555-5678");
    add_record_to_database(&db, &record2);

    // Search for a record by name
    search_records_by_name(&db, "John Doe");

    // Search for a record by address
    search_records_by_address(&db, "456 Oak St.");

    // Search for a record by phone number
    search_records_by_phone(&db, "555-5678");

    return 0;
}