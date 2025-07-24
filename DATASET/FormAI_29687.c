//FormAI DATASET v1.0 Category: Database Indexing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DB_SIZE 1000
#define MAX_ENTRY_SIZE 100

typedef struct {
    char key[MAX_ENTRY_SIZE];
    char value[MAX_ENTRY_SIZE];
} Entry;

typedef struct {
    Entry entries[MAX_DB_SIZE];
    int size;
} DB;

typedef struct {
    char key[MAX_ENTRY_SIZE];
    int index;
} Index;

typedef struct {
    Index indexes[MAX_DB_SIZE];
    int size;
} IndexTable;

IndexTable createIndex(DB db) {
    /*
    This function returns an IndexTable containing Index entries
    corresponding to each unique key in the given DB. Each Index
    entry contains the key and the index of the first Entry in the
    DB that has that key.
    */
    IndexTable indexTable;
    int i, j;

    indexTable.size = 0;

    for (i = 0; i < db.size; i++) {
        int found = 0;

        // Check if the current key is already in the IndexTable
        for (j = 0; j < indexTable.size; j++) {
            if (strcmp(db.entries[i].key, indexTable.indexes[j].key) == 0) {
                found = 1;
                break;
            }
        }

        // If the key is not in the IndexTable, add it
        if (!found) {
            Index index;
            strcpy(index.key, db.entries[i].key);
            index.index = i;
            indexTable.indexes[indexTable.size] = index;
            indexTable.size++;
        }
    }

    return indexTable;
}

void printDB(DB db) {
    /*
    This function prints out all the entries in the given DB
    */
    int i;

    printf("DB:\n");

    for (i = 0; i < db.size; i++) {
        printf("[%s, %s]\n", db.entries[i].key, db.entries[i].value);
    }
}

void printIndexTable(IndexTable indexTable) {
    /*
    This function prints out all the entries in the given IndexTable
    */
    int i;

    printf("IndexTable:\n");

    for (i = 0; i < indexTable.size; i++) {
        printf("[%s, %d]\n", indexTable.indexes[i].key, indexTable.indexes[i].index);
    }
}

int main() {
    /*
    Example usage of the Indexing System:
    */

    // Create a DB and add some entries to it
    DB myDB;
    myDB.size = 0;
    strcpy(myDB.entries[myDB.size].key, "foo");
    strcpy(myDB.entries[myDB.size].value, "bar");
    myDB.size++;
    strcpy(myDB.entries[myDB.size].key, "baz");
    strcpy(myDB.entries[myDB.size].value, "qux");
    myDB.size++;
    strcpy(myDB.entries[myDB.size].key, "foo");
    strcpy(myDB.entries[myDB.size].value, "spam");
    myDB.size++;

    // Print out the DB
    printDB(myDB);

    // Create an IndexTable from the DB
    IndexTable myIndexTable = createIndex(myDB);

    // Print out the IndexTable
    printIndexTable(myIndexTable);

    return 0;
}