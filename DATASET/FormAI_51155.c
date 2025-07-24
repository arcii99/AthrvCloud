//FormAI DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records our database can hold
#define MAX_RECORDS 100

// Define a struct to represent a database record (a person)
typedef struct {
    int id;
    char name[50];
    int age;
} Person;

// Define a struct to represent the database itself
typedef struct {
    Person records[MAX_RECORDS];
    int num_records;
} Database;

// Function to add a new record to the database
void add_record(Database *db, Person person) {
    if (db->num_records < MAX_RECORDS) {
        db->records[db->num_records++] = person;
    } else {
        printf("Error: database is full!\n");
    }
}

// Function to display all records in the database
void display_records(Database *db) {
    printf("ID\tName\t\tAge\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < db->num_records; i++) {
        printf("%d\t%s\t\t%d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

int main() {
    // Initialize an empty database
    Database my_db;
    my_db.num_records = 0;

    // Add some records to the database
    Person p1 = {1, "Alice", 25};
    Person p2 = {2, "Bob", 30};
    Person p3 = {3, "Charlie", 35};
    add_record(&my_db, p1);
    add_record(&my_db, p2);
    add_record(&my_db, p3);

    // Display all records in the database
    display_records(&my_db);

    // Exit the program
    return 0;
}