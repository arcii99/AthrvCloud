//FormAI DATASET v1.0 Category: Database Indexing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 20
#define MAX_VALUE_SIZE 100
#define MAX_NUMBER_OF_RECORDS 1000

// Structure definition for database record
typedef struct {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} Record;

// Structure definition for the database
typedef struct {
    int numberOfRecords;
    Record records[MAX_NUMBER_OF_RECORDS];
} Database;

// Structure definition for indexing key-value pairs in the database
typedef struct {
    char key[MAX_KEY_SIZE];
    int index;
} Index;

// Structure definition for indexing system
typedef struct {
    int numberOfIndexes;
    Index indexes[MAX_NUMBER_OF_RECORDS];
} IndexingSystem;

// Global variable for the database
Database database;

// Global variable for the indexing system
IndexingSystem indexingSystem;

// Function declaration for adding records to the database
void addRecord(char *key, char *value);

// Function declaration for searching records in the database
void searchRecord(char *key);

// Function declaration for creating index for the database
void createIndex(char *key);

// Function declaration for searching index in the indexing system
int searchIndex(char *key);

int main() {
    char command[MAX_VALUE_SIZE];
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter key: ");
            scanf("%s", key);
            printf("Enter value: ");
            scanf("%s", value);
            addRecord(key, value);
        } else if (strcmp(command, "search") == 0) {
            printf("Enter key: ");
            scanf("%s", key);
            searchRecord(key);
        } else if (strcmp(command, "index") == 0) {
            printf("Enter key: ");
            scanf("%s", key);
            createIndex(key);
        } else {
            printf("Invalid command!\n");
        }
    }

    return 0;
}

void addRecord(char *key, char *value) {
    if (database.numberOfRecords == MAX_NUMBER_OF_RECORDS) {
        printf("Database is full!\n");
        return;
    }

    strcpy(database.records[database.numberOfRecords].key, key);
    strcpy(database.records[database.numberOfRecords].value, value);

    printf("Record added successfully!\n");

    // Update indexing system
    createIndex(key);

    database.numberOfRecords++;
}

void searchRecord(char *key) {
    int index = searchIndex(key);

    if (index == -1) {
        printf("Record not found!\n");
        return;
    }

    printf("Record found: %s\n", database.records[index].value);
}

void createIndex(char *key) {
    if (indexingSystem.numberOfIndexes == MAX_NUMBER_OF_RECORDS) {
        printf("Indexing system is full!\n");
        return;
    }

    // Check if index already exists
    int i;
    for (i = 0; i < indexingSystem.numberOfIndexes; i++) {
        if (strcmp(indexingSystem.indexes[i].key, key) == 0) {
            // Index already exists
            indexingSystem.indexes[i].index = database.numberOfRecords - 1;
            return;
        }
    }

    // Index does not exist, create new index
    strcpy(indexingSystem.indexes[indexingSystem.numberOfIndexes].key, key);
    indexingSystem.indexes[indexingSystem.numberOfIndexes].index = database.numberOfRecords - 1;

    indexingSystem.numberOfIndexes++;
}

int searchIndex(char *key) {
    int i;
    for (i = 0; i < indexingSystem.numberOfIndexes; i++) {
        if (strcmp(indexingSystem.indexes[i].key, key) == 0)
            return indexingSystem.indexes[i].index;
    }

    return -1;
}