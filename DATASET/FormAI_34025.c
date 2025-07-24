//FormAI DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of records in the database
#define MAX_RECORDS 100  

// define a record structure to hold the data for each record in the database
typedef struct {
    int id;
    char name[20];
    float score;
} Record;

// define a database structure to hold the array of records
typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Database;

// function to add a new record to the database
void addRecord(Database *db, int id, const char *name, float score) {
    // check if the database is full
    if (db->num_records >= MAX_RECORDS) {
        printf("Error: Database is full!\n");
        return;
    }

    // create a new record and add it to the database
    Record record = {id, "", score};
    strncpy(record.name, name, 20);
    db->records[db->num_records++] = record;

    printf("Record added successfully!\n");
}

// function to search for a record by ID
int searchById(Database *db, int id) {
    // loop through each record in the database
    for (int i = 0; i < db->num_records; i++) {
        if (db->records[i].id == id) {
            return i;  // return the index of the found record
        }
    }

    return -1;  // no record was found with the given ID
}

// function to delete a record by ID
void deleteById(Database *db, int id) {
    // search for the record by ID
    int index = searchById(db, id);
    if (index == -1) {
        printf("Error: Record not found!\n");
        return;
    }

    // shift the remaining records down to fill the gap
    for (int i = index; i < db->num_records - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->num_records--;

    printf("Record deleted successfully!\n");
}

// function to print all records in the database
void printAll(Database *db) {
    printf("ID\tName\tScore\n");
    printf("--\t----\t-----\n");
    for (int i = 0; i < db->num_records; i++) {
        printf("%d\t%s\t%.2f\n", db->records[i].id, db->records[i].name, db->records[i].score);
    }
}

// main function to simulate the database
int main() {
    // create a new database object and initialize the number of records to 0
    Database db = {{0}, 0};

    // add some sample records to the database
    addRecord(&db, 1, "John Smith", 85.5);
    addRecord(&db, 2, "Jane Doe", 91.2);
    addRecord(&db, 3, "Bob Johnson", 78.9);

    // print the records in the database
    printf("\nAll Records:\n");
    printAll(&db);

    // search for a record by ID and print the results
    int id = 2;
    int index = searchById(&db, id);
    if (index == -1) {
        printf("Record with ID %d not found!\n", id);
    } else {
        printf("\nRecord with ID %d:\n", id);
        printf("Name: %s\nScore: %.2f\n", db.records[index].name, db.records[index].score);
    }

    // delete a record by ID and print the updated records in the database
    id = 1;
    deleteById(&db, id);
    printf("\nAll Records After Deletion:\n");
    printAll(&db);

    return 0;
}