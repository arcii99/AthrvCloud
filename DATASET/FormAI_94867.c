//FormAI DATASET v1.0 Category: Database Indexing System ; Style: grateful
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 10000
#define MAX_INDEX 1000

// Structure to hold a record
typedef struct {
    char name[50];
    char email[50];
    int age;
} Record;

// Array for storing all records
Record records[MAX_RECORDS];

// Index data structure
typedef struct {
    char key[50];
    int offset;
} Index;

// Array for storing all index records
Index indexData[MAX_INDEX];

int numRecords = 0;
int numIndexData = 0;

// Function to add a new record to the database
void addRecord(char name[], char email[], int age) {
    // Add record to records array
    Record newRecord;
    strcpy(newRecord.name, name);
    strcpy(newRecord.email, email);
    newRecord.age = age;
    records[numRecords++] = newRecord;

    // Add index data to the indexData array
    Index newIndex;
    strcpy(newIndex.key, email);
    newIndex.offset = numRecords - 1;
    indexData[numIndexData++] = newIndex;
}

// Function to search the database for a record by email
void searchByEmail(char email[]) {
    int startIndex = -1;
    int endIndex = -1;

    // Binary search to find the range of records with the specified email
    int left = 0;
    int right = numIndexData - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (strcmp(email, indexData[mid].key) == 0) {
            startIndex = mid;
            endIndex = mid;
            break;
        }
        else if (strcmp(email, indexData[mid].key) < 0) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    if (startIndex == -1) {
        // No records found with the specified email
        printf("No records found with the email: %s\n", email);
        return;
    }

    // Expand the range of records until we reach the start and end of the range
    while (startIndex > 0 && strcmp(email, indexData[startIndex - 1].key) == 0) {
        startIndex--;
    }
    while (endIndex < numIndexData - 1 && strcmp(email, indexData[endIndex + 1].key) == 0) {
        endIndex++;
    }

    // Print the records in the range
    printf("Records found with the email: %s\n", email);
    for (int i = startIndex; i <= endIndex; i++) {
        Record record = records[indexData[i].offset];
        printf("Name: %s, Email: %s, Age: %d\n", record.name, record.email, record.age);
    }
}

int main() {
    // Add some sample records to the database
    addRecord("John Doe", "john.doe@example.com", 25);
    addRecord("Jane Smith", "jane.smith@example.com", 30);
    addRecord("Bob Johnson", "bob.johnson@example.com", 35);
    addRecord("Alice Brown", "alice.brown@example.com", 40);
    addRecord("Tom Davis", "tom.davis@example.com", 45);

    // Search for a record by email
    searchByEmail("alice.brown@example.com");

    return 0;
}