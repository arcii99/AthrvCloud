//FormAI DATASET v1.0 Category: Database simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATABASE_SIZE 100 // maximum number of records in the database

// define a structure for each record
typedef struct Record {
    int id;
    char name[50];
    int age;
    char gender;
} Record;

// define a structure for the database
typedef struct Database {
    Record records[MAX_DATABASE_SIZE];
    int size;
} Database;

// function to add a record to the database
void addRecord(Database *db, int id, char name[], int age, char gender) {
    // create a new record
    Record newRecord;
    newRecord.id = id;
    strcpy(newRecord.name, name);
    newRecord.age = age;
    newRecord.gender = gender;

    // add the new record to the database
    db->records[db->size] = newRecord;
    db->size++;
}

// function to print all the records in the database
void printAllRecords(Database *db) {
    printf("==================================\n");
    printf("           DATABASE (%d entries)\n", db->size);
    printf("==================================\n");
    for (int i = 0; i < db->size; i++) {
        printf("ID: %d\n", db->records[i].id);
        printf("Name: %s\n", db->records[i].name);
        printf("Age: %d\n", db->records[i].age);
        printf("Gender: %c\n", db->records[i].gender);
        printf("------------------------------\n");
    }
}

int main() {
    // create a new database and initialize its size to 0
    Database db;
    db.size = 0;

    // add some records to the database
    addRecord(&db, 1001, "John Smith", 34, 'M');
    addRecord(&db, 1002, "Jane Doe", 27, 'F');
    addRecord(&db, 1003, "Bob Johnson", 42, 'M');
    addRecord(&db, 1004, "Sarah Williams", 19, 'F');

    // print all the records in the database
    printAllRecords(&db);

    return 0;
}