//FormAI DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the max size of the database
#define MAX_SIZE 100

// data structure to store the database records
typedef struct {
    int id;
    char name[50];
    int age;
    char address[100];
} Record;

// data structure to represent the database
typedef struct {
    Record database[MAX_SIZE];
    int num_records;
} Database;

// function to add a new record to the database
void add_record(Database* db, int id, char* name, int age, char* address) {
    if (db->num_records == MAX_SIZE) {
        printf("Cannot add record. Database is full.\n");
        return;
    }

    // create a new record with the given values
    Record new_record;
    new_record.id = id;
    strcpy(new_record.name, name);
    new_record.age = age;
    strcpy(new_record.address, address);

    // add the new record to the database
    db->database[db->num_records] = new_record;
    db->num_records++;

    printf("Record added successfully.\n");
}

// function to search for a record by ID
void search_record(Database* db, int id) {
    for (int i = 0; i < db->num_records; i++) {
        if (db->database[i].id == id) {
            printf("Record found:\n");
            printf("ID: %d\n", db->database[i].id);
            printf("Name: %s\n", db->database[i].name);
            printf("Age: %d\n", db->database[i].age);
            printf("Address: %s\n", db->database[i].address);
            return;
        }
    }

    printf("Record with ID %d not found.\n", id);
}

// function to display all records in the database
void display_records(Database* db) {
    if (db->num_records == 0) {
        printf("Database is empty.\n");
        return;
    }

    printf("Records in the database:\n");
    for (int i = 0; i < db->num_records; i++) {
        printf("ID: %d\n", db->database[i].id);
        printf("Name: %s\n", db->database[i].name);
        printf("Age: %d\n", db->database[i].age);
        printf("Address: %s\n", db->database[i].address);
        printf("---------------------------------\n");
    }
}

int main() {
    // create a new database object
    Database db;
    db.num_records = 0;

    // add some initial records to the database
    add_record(&db, 1001, "John", 30, "123 Main St");
    add_record(&db, 1002, "Jane", 25, "456 Elm St");

    // search for a record by ID
    search_record(&db, 1001);

    // display all records in the database
    display_records(&db);

    return 0;
}