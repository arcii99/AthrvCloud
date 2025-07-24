//FormAI DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_RECORDS 1000
#define MAX_NAME_LENGTH 50

// Structs
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    float height;
} Record;

typedef struct {
    int id;
    int index;
} Index;

// Function declarations
void addRecord(Record records[], Index index[], int *recordCount, int *indexCount, Record newRecord);
void printRecords(Record records[], int recordCount, Index index[], int indexCount);
void searchRecords(Record records[], int recordCount, Index index[], int indexCount, char *query);

// Main function
int main() {
    Record records[MAX_RECORDS];
    Index index[MAX_RECORDS];
    int recordCount = 0;
    int indexCount = 0;

    Record newRecord = {1, "John Doe", 30, 5.6};
    addRecord(records, index, &recordCount, &indexCount, newRecord);

    newRecord = (Record){2, "Jane Smith", 25, 5.2};
    addRecord(records, index, &recordCount, &indexCount, newRecord);

    newRecord = (Record){3, "Bob Johnson", 45, 6.0};
    addRecord(records, index, &recordCount, &indexCount, newRecord);

    printf("All records: \n");
    printRecords(records, recordCount, index, indexCount);

    printf("\nSearching for records with name containing \"smith\": \n");
    searchRecords(records, recordCount, index, indexCount, "smith");

    return 0;
}

/**
 * Adds a new record to the database and updates the index.
 */
void addRecord(Record records[], Index index[], int *recordCount, int *indexCount, Record newRecord) {
    // Add record to the end of records array
    records[*recordCount] = newRecord;
    (*recordCount)++;

    // Find proper place in the index to insert new record's id
    int i;
    for (i = 0; i < *indexCount; i++) {
        if (strcmp(newRecord.name, records[index[i].id - 1].name) < 0) {
            break;
        }
    }

    // Shift index array to make space for new index item
    int j;
    for (j = *indexCount; j > i; j--) {
        index[j] = index[j - 1];
    }

    // Add new index item
    Index newIndex = {newRecord.id, i};
    index[i] = newIndex;

    (*indexCount)++;
}

/**
 * Prints all records in the database.
 */
void printRecords(Record records[], int recordCount, Index index[], int indexCount) {
    int i;
    for (i = 0; i < indexCount; i++) {
        printf("%d. %s, %d, %.1f\n", records[index[i].id - 1].id, records[index[i].id - 1].name, records[index[i].id - 1].age, records[index[i].id - 1].height);
    }
}

/**
 * Searches the database for all records with name containing the query string.
 */
void searchRecords(Record records[], int recordCount, Index index[], int indexCount, char *query) {
    int i;
    for (i = 0; i < indexCount; i++) {
        if (strstr(records[index[i].id - 1].name, query) != NULL) {
            printf("%d. %s, %d, %.1f\n", records[index[i].id - 1].id, records[index[i].id - 1].name, records[index[i].id - 1].age, records[index[i].id - 1].height);
        }
    }
}