//FormAI DATASET v1.0 Category: Database simulation ; Style: careful
#include <stdio.h>
#include <string.h>

// Define the maximum number of records to be stored
#define MAX_RECORDS 100

// Define the maximum length of each field in a record
#define MAX_FIELD_LENGTH 50

// Define the structure of a record
typedef struct {
    int id;
    char name[MAX_FIELD_LENGTH];
    float salary;
} Record;

// Define the structure of the database
typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function to add a new record to the database
void addRecord(Database* db, int id, char* name, float salary) {
    if (db->count >= MAX_RECORDS) {
        printf("Error: database is full\n");
        return;
    }
    Record record = {id};
    strncpy(record.name, name, MAX_FIELD_LENGTH);
    record.salary = salary;
    db->records[db->count++] = record;
    printf("Record with ID %d added to the database\n", id);
}

// Function to retrieve a record from the database by ID
Record* getRecordById(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    printf("Record with ID %d not found\n", id);
    return NULL;
}

// Function to print all records in the database
void printAllRecords(Database* db) {
    printf("ID\tName\t\tSalary\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\t\t%.2f\n", db->records[i].id, 
               db->records[i].name, db->records[i].salary);
    }
}

int main() {
    // Initialize an empty database
    Database db = {0};
    
    // Add some records to the database
    addRecord(&db, 1, "Alice", 50000);
    addRecord(&db, 2, "Bob", 60000);
    addRecord(&db, 3, "Charlie", 70000);
    
    // Retrieve a record from the database and print it
    Record* record = getRecordById(&db, 2);
    if (record != NULL) {
        printf("Record found: ID=%d Name=%s Salary=%.2f\n", 
               record->id, record->name, record->salary);
    }
    
    // Print all records in the database
    printAllRecords(&db);
    
    return 0;
}