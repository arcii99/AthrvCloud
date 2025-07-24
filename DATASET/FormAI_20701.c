//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50

// Define a struct to represent a person in our database
typedef struct Person {
    int id;
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Person;

// Define a struct to represent our database
typedef struct Database {
    Person records[MAX_RECORDS];
    int num_records;
} Database;

// Define a function to add a person to the database
void add_record(Database* db, char* name, char* email) {
    if (db->num_records >= MAX_RECORDS) {
        printf("Error: database is full\n");
        return;
    }

    Person new_person = {
        .id = db->num_records,
    };
    strcpy(new_person.name, name);
    strcpy(new_person.email, email);

    db->records[db->num_records++] = new_person;
}

// Define a function to print all records in the database
void print_database(Database* db) {
    printf("%-15s %-30s %-30s\n", "ID", "Name", "Email");
    for (int i = 0; i < db->num_records; i++) {
        Person p = db->records[i];
        printf("%-15d %-30s %-30s\n", p.id, p.name, p.email);
    }
}

// Define a function to search for records by name
void search_by_name(Database* db, char* name) {
    printf("%-15s %-30s %-30s\n", "ID", "Name", "Email");
    for (int i = 0; i < db->num_records; i++) {
        Person p = db->records[i];
        if (strcmp(p.name, name) == 0) {
            printf("%-15d %-30s %-30s\n", p.id, p.name, p.email);
        }
    }
}

// Define a function to search for records by email
void search_by_email(Database* db, char* email) {
    printf("%-15s %-30s %-30s\n", "ID", "Name", "Email");
    for (int i = 0; i < db->num_records; i++) {
        Person p = db->records[i];
        if (strcmp(p.email, email) == 0) {
            printf("%-15d %-30s %-30s\n", p.id, p.name, p.email);
        }
    }
}

int main() {
    // Create a new database
    Database db = {
        .num_records = 0,
    };

    // Add some records to the database
    add_record(&db, "Alice", "alice@example.com");
    add_record(&db, "Bob", "bob@example.com");
    add_record(&db, "Charlie", "charlie@example.com");

    // Print all records in the database
    printf("All records:\n");
    print_database(&db);

    // Search for records by name
    printf("\nSearching for records with name = 'Bob':\n");
    search_by_name(&db, "Bob");

    // Search for records by email
    printf("\nSearching for records with email = 'charlie@example.com':\n");
    search_by_email(&db, "charlie@example.com");

    return 0;
}