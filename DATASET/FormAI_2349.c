//FormAI DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <string.h>
#define MAX_RECORDS 100

// Define the struct for our database record
typedef struct Record {
    int id;
    char name[50];
    char email[50];
} Record;

// Define the struct for our index entry
typedef struct IndexEntry {
    char email[50];
    int position;
} IndexEntry;

// Define the struct for our index
typedef struct Index {
    IndexEntry indexEntries[MAX_RECORDS];
    int count;
} Index;

// Declare our global index
Index emailIndex;

// Function to add a record to the database and index
int addRecord(Record* record) {
    // Check if the index is already full
    if (emailIndex.count >= MAX_RECORDS) {
        printf("Database is full\n");
        return 0;
    }
    // Add the record to the database
    FILE* database = fopen("database.txt", "a");
    fprintf(database, "%d,%s,%s\n", record->id, record->name, record->email);
    fclose(database);
    // Add the email address to the index
    strcpy(emailIndex.indexEntries[emailIndex.count].email, record->email);
    emailIndex.indexEntries[emailIndex.count].position = emailIndex.count;
    emailIndex.count++;
    return 1;
}

// Function to search for a record in the database by email address
Record* searchByEmail(char* email) {
    // Check if the index is empty
    if (emailIndex.count == 0) {
        printf("Database is empty\n");
        return NULL;
    }
    // Search the index for the email address
    int i;
    for (i = 0; i < emailIndex.count; i++) {
        if (strcmp(emailIndex.indexEntries[i].email, email) == 0) {
            // Open the database and seek to the record position
            FILE* database = fopen("database.txt", "r");
            fseek(database, (emailIndex.indexEntries[i].position * sizeof(Record)), SEEK_SET);
            // Read the record from the database
            Record* record = (Record*)malloc(sizeof(Record));
            fscanf(database, "%d,%[^,],%s\n", &record->id, record->name, record->email);
            fclose(database);
            return record;
        }
    }
    // If the email address was not found
    printf("Record not found\n");
    return NULL;
}

int main() {
    // Initialize the index count to 0
    emailIndex.count = 0;
    // Add some records to the database and index
    Record record1 = { 1, "Alice", "alice@example.com" };
    addRecord(&record1);
    Record record2 = { 2, "Bob", "bob@example.com" };
    addRecord(&record2);
    Record record3 = { 3, "Charlie", "charlie@example.com" };
    addRecord(&record3);
    // Search for a record by email address
    Record* result = searchByEmail("bob@example.com");
    if (result != NULL) {
        printf("%d,%s,%s\n", result->id, result->name, result->email);
    }
    return 0;
}