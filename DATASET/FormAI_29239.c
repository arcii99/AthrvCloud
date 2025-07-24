//FormAI DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Define a Structure to Store Database Records
struct Record {
    int id;
    char name[20];
    char address[50];
};

// Define Database Structure to Store Records
struct Database {
    struct Record records[MAX_RECORDS];
    int num_records;
};

// Function to Add a New Record to the Database
void add_record(struct Database *db, struct Record record) {
    db->records[db->num_records++] = record;
}

// Function to Print Records in the Database
void print_records(struct Database db) {
    for (int i = 0; i < db.num_records; i++) {
        printf("Record %d:\n", i+1);
        printf("\tID: %d\n", db.records[i].id);
        printf("\tName: %s\n", db.records[i].name);
        printf("\tAddress: %s\n", db.records[i].address);
    }
}

int main() {
    struct Database my_db;
    my_db.num_records = 0;

    // Add Some Records to the Database
    struct Record record1 = {1, "John Doe", "123 Main St."};
    add_record(&my_db, record1);
    struct Record record2 = {2, "Jane Smith", "456 Elm St."};
    add_record(&my_db, record2);

    // Print Records in the Database
    printf("Database Records:\n");
    print_records(my_db);

    return 0;
}