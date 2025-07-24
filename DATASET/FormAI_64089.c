//FormAI DATASET v1.0 Category: Database simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATABASE_CAPACITY 100 // maximum records the database can contain

// structure for storing a single record in the database
typedef struct {
    int id;
    char name[50];
    char email[50];
} Record;

// structure for representing our database
typedef struct {
    int size;
    Record records[DATABASE_CAPACITY];
} Database;

// function to initialize a new database
void initializeDatabase(Database *database)
{
    database->size = 0;
}

// function to insert a new record into the database
void insertRecord(Database *database, Record record)
{
    if (database->size < DATABASE_CAPACITY) {
        database->records[database->size] = record;
        database->size++;
    } else {
        printf("Error: database is full\n");
    }
}

// function to find a record in the database by its id
Record *findRecordById(Database *database, int id)
{
    int i;
    for (i = 0; i < database->size; i++) {
        if (database->records[i].id == id) {
            return &database->records[i];
        }
    }
    return NULL;
}

// function to print all the records in the database
void printDatabase(Database *database)
{
    int i;
    printf("ID\tName\tEmail\n");
    for (i = 0; i < database->size; i++) {
        printf("%d\t%s\t%s\n", database->records[i].id, database->records[i].name, database->records[i].email);
    }
}

// main function for testing the database
int main()
{
    Database db;
    Record r1 = {1, "Alice", "alice@example.com"};
    Record r2 = {2, "Bob", "bob@example.com"};
    Record r3 = {3, "Charlie", "charlie@example.com"};

    // initialize the database
    initializeDatabase(&db);

    // add some records
    insertRecord(&db, r1);
    insertRecord(&db, r2);
    insertRecord(&db, r3);

    // find a record by id and update the email address
    Record *r = findRecordById(&db, 2);
    if (r != NULL) {
        strcpy(r->email, "bob.updated@example.com");
    }

    // print all the records in the database
    printDatabase(&db);

    return 0;
}