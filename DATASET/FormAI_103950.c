//FormAI DATASET v1.0 Category: Database simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATABASE_SIZE 1000 // maximum number of records
#define FIELD_SIZE 50 // maximum field size

// define a struct to represent a record in the database
typedef struct {
    char name[FIELD_SIZE];
    int age;
    char address[FIELD_SIZE];
} Record;

// define a struct to represent the database
typedef struct {
    Record records[DATABASE_SIZE];
    int num_records;
} Database;

// function to add a record to the database
void addRecord(Database *db, char name[], int age, char address[]) {
    if (db->num_records >= DATABASE_SIZE) {
        printf("Error: database is full\n");
        return;
    }
    Record new_record;
    strcpy(new_record.name, name);
    new_record.age = age;
    strcpy(new_record.address, address);
    db->records[db->num_records] = new_record;
    db->num_records++;
}

// function to print all records in the database
void printRecords(Database *db) {
    printf("Name\tAge\tAddress\n");
    for (int i = 0; i < db->num_records; i++) {
        Record r = db->records[i];
        printf("%s\t%d\t%s\n", r.name, r.age, r.address);
    }
}

int main() {
    // initialize the database
    Database db;
    db.num_records = 0;

    // add some records to the database
    addRecord(&db, "Alice", 25, "123 Main St.");
    addRecord(&db, "Bob", 30, "456 Oak Ave.");
    addRecord(&db, "Charlie", 35, "789 Pine Rd.");

    // print all records
    printRecords(&db);

    return 0;
}