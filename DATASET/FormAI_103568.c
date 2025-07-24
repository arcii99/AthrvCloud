//FormAI DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

typedef struct Record {
    int id;
    char name[50];
    char address[100];
    int age;
} Record;

// Initializes an empty record
void initializeRecord(Record *record) {
    record->id = -1;
    strcpy(record->name, "");
    strcpy(record->address, "");
    record->age = -1;
}

// Displays given record on console
void displayRecord(Record record) {
    printf("ID: %d\n", record.id);
    printf("Name: %s\n", record.name);
    printf("Address: %s\n", record.address);
    printf("Age: %d\n", record.age);
}

// Checks if two records are equal based on their ID
int areRecordsEqual(Record record1, Record record2) {
    return record1.id == record2.id;
}

// Adds a new record to given records array
void addRecord(Record *recordsPointer, Record newRecord) {
    // Finds first empty record in the array
    for(int i = 0; i < MAX_RECORDS; i++) {
        if(recordsPointer[i].id == -1) {
            recordsPointer[i] = newRecord;
            return;
        }
    }
    printf("ERROR: Reached maximum record capacity.\n");
}

// Updates an existing record in the given records array
void updateRecord(Record *recordsPointer, Record updatedRecord) {
    // Finds record with matching ID in the array
    for(int i = 0; i < MAX_RECORDS; i++) {
        if(recordsPointer[i].id == updatedRecord.id) {
            recordsPointer[i] = updatedRecord;
            return;
        }
    }
    printf("ERROR: Record with ID %d not found.\n", updatedRecord.id);
}

// Deletes an existing record from the given records array
void deleteRecord(Record *recordsPointer, Record deletedRecord) {
    // Finds record with matching ID in the array
    for(int i = 0; i < MAX_RECORDS; i++) {
        if(recordsPointer[i].id == deletedRecord.id) {
            // Replaces target record with last non-empty record
            for(int j = i; j < MAX_RECORDS - 1; j++) {
                recordsPointer[j] = recordsPointer[j + 1];
            }
            initializeRecord(&recordsPointer[MAX_RECORDS - 1]);
            return;
        }
    }
    printf("ERROR: Record with ID %d not found.\n", deletedRecord.id);
}

int main() {
    Record records[MAX_RECORDS];
    // Initializes all records in the array as empty
    for(int i = 0; i < MAX_RECORDS; i++) {
        initializeRecord(&records[i]);
    }

    // Adds some example records to the array
    Record record1, record2, record3;
    record1.id = 1;
    strcpy(record1.name, "John Doe");
    strcpy(record1.address, "123 Main St, Anytown, USA");
    record1.age = 30;
    record2.id = 2;
    strcpy(record2.name, "Jane Smith");
    strcpy(record2.address, "456 Elm St, Anytown, USA");
    record2.age = 25;
    record3.id = 3;
    strcpy(record3.name, "Bob Johnson");
    strcpy(record3.address, "789 Oak St, Anytown, USA");
    record3.age = 35;
    addRecord(records, record1);
    addRecord(records, record2);
    addRecord(records, record3);

    // Displays all records in the array
    printf("ALL RECORDS:\n");
    for(int i = 0; i < MAX_RECORDS; i++) {
        if(records[i].id != -1) {
            displayRecord(records[i]);
            printf("-----------------------------\n");
        }
    }

    // Updates an existing record in the array
    Record updatedRecord;
    updatedRecord.id = 2;
    strcpy(updatedRecord.name, "Jane Doe");
    strcpy(updatedRecord.address, "456 Elm St, Anytown, USA");
    updatedRecord.age = 26;
    updateRecord(records, updatedRecord);

    // Deletes an existing record from the array
    Record deletedRecord;
    deletedRecord.id = 1;
    deleteRecord(records, deletedRecord);

    // Displays all records in the array again
    printf("ALL RECORDS:\n");
    for(int i = 0; i < MAX_RECORDS; i++) {
        if(records[i].id != -1) {
            displayRecord(records[i]);
            printf("-----------------------------\n");
        }
    }

    return 0;
}