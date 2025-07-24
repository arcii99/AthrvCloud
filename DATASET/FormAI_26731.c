//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_RECORDS 100
#define MAX_NAME_LEN 50

// define struct for record
typedef struct {
    int id;
    char name[MAX_NAME_LEN];
} Record;

// define struct for index entry
typedef struct {
    int id;
    int offset;
} IndexEntry;

// define struct for index
typedef struct {
    char name[MAX_NAME_LEN];
    int numEntries;
    IndexEntry entries[MAX_RECORDS];
} Index;

// define struct for database
typedef struct {
    int numRecords;
    Record records[MAX_RECORDS];
    Index indexes[MAX_RECORDS];
    int numIndexes;
} Database;

// function prototypes
void addRecord(Database* db);
void printAllRecords(Database* db);
IndexEntry* searchIndex(int id, Index* index);
void addIndex(Database* db, char* indexName);

// main function
int main() {
    Database db;
    db.numRecords = 0;
    db.numIndexes = 0;

    // add some records
    addRecord(&db);
    addRecord(&db);
    addRecord(&db);

    // add some indexes
    addIndex(&db, "id");
    addIndex(&db, "name");

    // search for a record by id
    printf("Searching for record with id=2...\n");
    int id = 2;
    IndexEntry* entry = searchIndex(id, &db.indexes[0]);
    if (entry != NULL) {
        Record* record = &db.records[entry->offset];
        printf("Found record: id=%d, name=%s\n", record->id, record->name);
    } else {
        printf("Record not found.\n");
    }

    return 0;
}

// function to add a record to the database
void addRecord(Database* db) {
    if (db->numRecords >= MAX_RECORDS) {
        printf("Database is full.\n");
        return;
    }

    Record* record = &db->records[db->numRecords];
    printf("Enter record id: ");
    scanf("%d", &record->id);
    printf("Enter record name: ");
    scanf("%s", record->name);

    db->numRecords++;
}

// function to print all records in the database
void printAllRecords(Database* db) {
    printf("All records:\n");
    for (int i = 0; i < db->numRecords; i++) {
        Record* record = &db->records[i];
        printf("id=%d, name=%s\n", record->id, record->name);
    }
}

// function to search an index for a given id
IndexEntry* searchIndex(int id, Index* index) {
    for (int i = 0; i < index->numEntries; i++) {
        IndexEntry* entry = &index->entries[i];
        if (entry->id == id) {
            return entry;
        }
    }
    return NULL;
}

// function to add an index to the database
void addIndex(Database* db, char* indexName) {
    if (db->numIndexes >= MAX_RECORDS) {
        printf("Too many indexes.\n");
        return;
    }

    Index* index = &db->indexes[db->numIndexes];
    strcpy(index->name, indexName);
    index->numEntries = 0;
    db->numIndexes++;
}