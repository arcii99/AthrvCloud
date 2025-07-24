//FormAI DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100
#define MAX_RECORDS 1000

/* Struct for a record in the database */
typedef struct record {
    int id;
    char name[MAX_STRING_LENGTH];
    int age;
} Record;

/* Array to store all records in the database */
Record database[MAX_RECORDS];

/* Function to compare records by ID */
int compareById(const void *a, const void *b) {
    const Record *r1 = a;
    const Record *r2 = b;
    return r1->id - r2->id;
}

/* Function to compare records by name */
int compareByName(const void *a, const void *b) {
    const Record *r1 = a;
    const Record *r2 = b;
    return strcmp(r1->name, r2->name);
}

int main() {
    int numRecords = 0;

    /* Add some sample records to the database */
    database[numRecords].id = 1;
    strcpy(database[numRecords].name, "Alice");
    database[numRecords].age = 25;
    numRecords++;

    database[numRecords].id = 2;
    strcpy(database[numRecords].name, "Bob");
    database[numRecords].age = 30;
    numRecords++;

    database[numRecords].id = 3;
    strcpy(database[numRecords].name, "Charlie");
    database[numRecords].age = 35;
    numRecords++;

    /* Sort the records by ID */
    qsort(database, numRecords, sizeof(Record), compareById);

    /* Print the sorted records */
    printf("Sorted by ID:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);
    }

    /* Sort the records by name */
    qsort(database, numRecords, sizeof(Record), compareByName);

    /* Print the sorted records */
    printf("\nSorted by name:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("Name: %s, ID: %d, Age: %d\n", database[i].name, database[i].id, database[i].age);
    }

    return 0;
}